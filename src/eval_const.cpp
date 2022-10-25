#include "eval_const.h"
//#include "eval_op.h"
//#include "expression.h"


eval_const::eval_const(const expression &expr):eval_op(expr), value_(expr.get_op_param()) //removed the "value" from the brackets
{

}

void eval_const::eval(vars_type &variables, const kwargs_type &kwargs) //should it be here?
{
    variables[expr_id_] = value_;
}


std::shared_ptr<eval_op> eval_const::clone(const expression &expr) 
{
    return std::make_shared<eval_const>(expr);
}

