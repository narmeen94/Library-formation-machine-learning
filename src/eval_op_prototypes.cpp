#include "eval_op_prototypes.h"
#include "eval_const.h"
#include "eval_input.h"


eval_op_prototypes::eval_op_prototypes() 
{
      eval_const::store_prototype(proto_map_);
      //eval_input::store_prototype(proto_map_);
}
eval_op_prototypes &eval_op_prototypes::instance() 
{
    static eval_op_prototypes instance;    // the only instance
    return instance;
}

 std::shared_ptr<eval_op> eval_op_prototypes::locate(std::string name)
 {
    return proto_map_[name];

 }





