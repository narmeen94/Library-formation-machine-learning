
#include "eval_op.h"
#include <assert.h>

eval_op::~eval_op() 
{

}

eval_op::eval_op(const expression &expr):expr_id_(expr.get_id()),op_name_(expr.get_op_name()),op_type_(expr.get_op_type()),inputs_(expr.get_inputs())
{
    std::cout<<"this is the expr_id from eval_op: "<<expr_id_<<std::endl;
}

//no implementation for the virtual funct.so commenting

void eval_op::eval(vars_type &variables, const kwargs_type &kwargs) 
{
    assert(false); // should be provided by derived classes
}

int eval_op::get_id_op() const
{
    return expr_id_;
    //return expr.get_id()

}