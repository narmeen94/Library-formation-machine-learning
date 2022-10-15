#include "program.h"
#include "evaluation.h"
#include "expression.h"
#include <iostream> 

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
    // std::cout <<"appending"<< std::endl;
    // std::cout <<newexp.get_id() <<std::endl;
    // std::cout << newexp.get_op_name() <<std::endl;
    exprs_.push_back(newexp);


    
   
    //exprs_.push_back(expression(expr_id,op_name,op_type,inputs,num_inputs));
    
    //std::cout<< << std::endl;
    

}

int program::add_op_param_double(
    const char *key,
    double value)
{
    const_["value"]=value;
    return 0;
}

int program::add_op_param_ndarray(
    const char *key,
    int dim,
    size_t shape[],
    double data[])
{
    return -1;
}


evaluation *program::build() 
{
     evaluation *val=new evaluation(exprs_,const_); 
     return val;

    
    //return nullptr;
    
}
    
