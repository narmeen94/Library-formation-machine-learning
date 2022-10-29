#include "program.h"
#include "evaluation.h"
#include "expression.h"
#include <iostream> 
#include "tensor.h"

program::program()
{
    
}

void program::append_expression(
    int expr_id,
    const char *op_name,
    const char *op_type,
    int inputs[],
    int num_inputs)
{
    expression newexp=expression(expr_id,op_name,op_type,inputs,num_inputs);
    exprs_.push_back(newexp);
    

}

int program::add_op_param_double(
    const char *key,
    double value)
{
    exprs_.back().add_op_param_double(key,value);
    
    return 0;
}

int program::add_op_param_ndarray(
    const char *key,
    int dim,
    size_t shape[],
    double data[])
{
    exprs_.back().add_op_param_ndarray(key,dim,shape,data);
    
    return 0;
}


evaluation *program::build() 
{
     //evaluation *val=new evaluation(exprs_,const_); 
     evaluation *val=new evaluation(exprs_); 
     return val;

    
    //return nullptr;
    
}
    
