#include "eval_input.h"
#include <memory>

eval_input::eval_input(const expression &expr):eval_op(expr)//removed value_()
{

}

void eval_input::eval(vars_type &variables, const kwargs_type &kwargs) //should it be here?
{
    //variables[expr_id_] = value_;
    //variables[expr_id_] = kwargs[op_name_];
    variables[expr_id_] = kwargs.at(op_name_); 
    std::cout<<"this is from eval_input. id is:" << expr_id_<<" and the op name is:" <<op_name_<<"value is:"<<std::endl; //can't print kwargs.at(op_name) how to print tensors????
}


std::shared_ptr<eval_op> eval_input::clone(const expression &expr) 
{
    return std::make_shared<eval_input>(expr);
}

