#ifndef EVAL_ADD_H
#define EVAL_ADD_H

#include <assert.h>



#include "tensor.h"
#include "expression.h"
#include "eval_binary.h"
#include "eval_op_prototypes.h"
#include "eval_op.h"

class eval_add: public eval_binary 
{
public:
    eval_add() {}
    
    eval_add(const expression &expr); //adding constructor myself
    
    tensor compute(const tensor &a, const tensor &b) override;

    std::shared_ptr<eval_op> clone(const expression &expr) override; //it is ok 
    

    static void store_prototype(eval_op_proto_map &proto_map)
    {
         assert(proto_map.find("Add") == proto_map.end());
         proto_map["Add"] = std::make_shared<eval_add>();
    } 

}; // class eval_add
#endif