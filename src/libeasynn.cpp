#include <stdio.h>

#include "libeasynn.h"
#include "program.h"
#include "evaluation.h"


program *create_program()
{
    program *prog = new program;
    printf("program %p\n", prog);
    return prog;
}

void append_expression(
    program *prog,
    int expr_id,
    const char *op_name,
    const char *op_type,
    int inputs[],
    int num_inputs)
{
    printf("program %p, expr_id %d, op_name %s, op_type %s, inputs %d (",
        prog, expr_id, op_name, op_type, num_inputs);
    for (int i = 0; i != num_inputs; ++i)
        printf("%d,", inputs[i]);
    printf(")\n"); //so the print on console is program......inputs 0 (blah)
    prog->append_expression(expr_id, op_name, op_type, inputs, num_inputs); //what does this mean? like why do we do prog->? can't we write (prog,expr_id,...)??
    //prog->push_back(expr);
    


    

}

int add_op_param_double(
    program *prog,
    const char *key,
    double value)
{
    printf("program %p, key %s, value %f\n",
        prog, key, value);
    return prog->add_op_param_double(key, value);
}

int add_op_param_ndarray(
    program *prog,
    const char *key,
    int dim,
    size_t shape[],
    double data[])
{
    printf("program %p, key %s, value %p dim %d (",
        prog, key, data, dim);
    for (int i = 0; i != dim; ++i)
        printf("%zu,", shape[i]);
    printf(")\n");
    return prog->add_op_param_ndarray(key, dim, shape, data);
    //return 0;
}

evaluation *build(program *prog)
{
    evaluation *eval = prog->build();
    printf("evaluation %p\n", eval);

    return eval;
}

void add_kwargs_double(
    evaluation *eval,
    const char *key,
    double value)
{
    printf("evaluation %p, key %s, value %f\n",
        eval, key, value);
    eval->add_kwargs_double(key, value); //we are adding the object eval from evaluation
}

void add_kwargs_ndarray(
    evaluation *eval,
    const char *key,
    int dim,
    size_t shape[],
    double data[])
{
    printf("evaluation %p, key %s, value %p dim %d (",
        eval, key, data, dim);
    for (int i = 0; i != dim; ++i)
        printf("%zu,", shape[i]);
    printf(")\n");
    eval->add_kwargs_ndarray(key, dim, shape, data);

}
//modified for proj 3:
int execute(evaluation *eval,int *p_dim, size_t **p_shape, double **p_data)
{
    // logging and error checking

    tensor &res = eval->get_result();
    *p_dim = res.get_dim();
    *p_shape = res.get_shape_array();
    *p_data = res.get_data_array();
    return 0;
}

// int execute(
//     evaluation *eval,
//     int *p_dim,
//     size_t **p_shape,
//     double **p_data)
// {
    
//     // printf("evaluation %p, p_dim %p, p_shape %p, p_data %p\n",
//     //     eval, p_dim, p_shape, p_data);   //%p is for the pointer values

//     //     //modified for new execute proj3:
//     // //int ret = eval->execute(eval, p_dim, p_shape, p_data);
//     // int ret = eval->execute(); //modified again in pj3

//     // if (ret != 0) //????
//     //     return ret;
//     // *p_dim = 0; //why?
//     // *p_shape = nullptr; //why?
//     // *p_data = &eval->get_result(); //why &eval?     //from evaluation.cpp
//     // fflush(stdout); //all buffered charcters are transmitted to the terminal
//     // return 0;
// }
