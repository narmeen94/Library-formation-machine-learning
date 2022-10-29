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
    
    evaluation *eval = build(prog); 

    //add_kwargs_ndarray(eval,"a",1,2,(1,1));
    add_kwargs_double(eval, "a", 2);
    //add_op_param_double(prog,"value",10);  //for const

    //int dim=tensor.shape_.size();
    int dim=0;
    //size_t *shape =shape[0]; //size_t is unsigned long
    //double *data = data[0];
    size_t *shape=nullptr;
    double *data= nullptr;
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
