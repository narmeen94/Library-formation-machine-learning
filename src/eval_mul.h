#ifndef EVAL_MUL_H
#define EVAL_MUL_H

//#include "tensor.h"
//#include "expression.h"
#include "eval_binary.h"
//#include "eval_op_prototypes.h"
//#include "eval_op.h"
#include <assert.h>

typedef std::map<std::string, std::shared_ptr<eval_op>> eval_op_proto_map;

class eval_binary;

class eval_mul: public eval_binary 
{
public:
    eval_mul() {}
    
    eval_mul(const expression &expr); //adding constructor myself
    
    tensor compute(const tensor &a, const tensor &b) override;

    std::shared_ptr<eval_op> clone(const expression &expr) override; //it is ok 
    

    static void store_prototype(eval_op_proto_map &proto_map)
    {
         assert(proto_map.find("Mul") == proto_map.end());
         proto_map["Mul"] = std::make_shared<eval_mul>();
    } 

}; // class eval_mul
#endif