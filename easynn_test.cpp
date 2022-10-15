/**
 * A simple test program helps you to debug your easynn implementation.
 */

#include <stdio.h>
#include "src/libeasynn.h"

int main()
{
    program *prog = create_program(); //create program returns a pointer

    int inputs0[] = {};
    //from libeasynn.cpp
    append_expression(prog, 0, "a", "Input", inputs0, 0); //we are accessing the pointer prog that is a pointer to the output of 
    append_expression(prog, 1, "b", "Input", inputs0, 0);
    append_expression(prog, 2, "c", "Input", inputs0, 0);
    append_expression(prog, 3, "value", "Const", inputs0, 0);
    add_op_param_double(prog,"value",10);
    //expr_id=0, operand name is a,operand type is input,inputs0 is the pointers to "inputs". num_inputs is the number of inputs 
    //here, t0=a.input(); t1=Add(t0,t0)
    int inputs1[] = {1, 2}; // t0 and t0 are two inputs 
    append_expression(prog, 4, "", "Sub", inputs1, 2);
    int inputs2[]={4,0};
    append_expression(prog, 5, "", "Mul", inputs2, 2);
    int inputs3[]={5,3};
    append_expression(prog, 6, "", "Add", inputs3, 2);

    evaluation *eval = build(prog); //why like this? it is from libeasynn evaluation .returns a pointer
    //this gives the output print evaluation,key ,value.key=string,value=float
    add_kwargs_double(eval, "a", 5);
    add_kwargs_double(eval, "b", 9);
    add_kwargs_double(eval, "c", 2);
    //add_op_param_double(prog,"value",10);  //for const

    int dim = 0;
    size_t *shape = nullptr; //size_t is unsigned long
    double *data = nullptr;
    if (execute(eval, &dim, &shape, &data) != 0)
    {
        printf("evaluation fails\n");
        return -1;    
    }

    if (dim == 0)
        printf("res = %f\n", data[0]);
    else
        printf("result as tensor is not supported yet\n");

    return 0;
}
