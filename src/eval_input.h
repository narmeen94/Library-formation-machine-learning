
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include "tensor.h"
#include "expression.h"
#include "eval_op.h"
#include <assert.h>
#include "eval_const.h"


class eval_input: public eval_op 
{
    //void eval_input::store_prototype(eval_op_proto_map &proto_map);
    void eval_input::store_prototype(proto_map_);  //?????????????????????
}; //class eval_input