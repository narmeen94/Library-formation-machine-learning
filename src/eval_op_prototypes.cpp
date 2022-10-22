#include "eval_op_prototypes.h"
#include "eval_const.h"


eval_op_prototypes::eval_op_prototypes() 
{
//     void eval_const::store_prototype(proto_map_);
//     void eval_input::store_prototype(proto_map_);
}
eval_op_prototypes &eval_op_prototypes::instance() 
{
    static eval_op_prototypes instance;    // the only instance
    return instance;
}



//where is the definition for locate?


