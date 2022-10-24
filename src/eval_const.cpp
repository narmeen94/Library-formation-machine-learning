#include "eval_const.h"
#include "eval_op.h"
#include "expression.h"


eval_const::eval_const(const expression &expr):eval_op(expr), value_(expr.get_op_param("value")) //removed the "value" from the brackets
{

}
// void eval_const::eval(vars_type &variables, const kwargs_type &kwargs) 
// {
//     variables[expr_id_] = value_;
// }

std::shared_ptr<eval_op> eval_const::clone(const expression &expr) 
{
    return std::make_shared<eval_const>(expr);
}

 void eval_const::store_prototype(eval_op_proto_map &proto_map) //should it be changed to proto_map_ too?  //see it again.. should not it be static???????????????
{
        assert(proto_map.find("Const") == proto_map.end());
        proto_map["Const"] = std::make_shared<eval_const>();
} 