#ifndef EVAL_SUB_H
#define EVAL_SUB_H

#include <assert.h>



//#include "tensor.h"
//#include "expression.h"
#include "eval_binary.h"
//#include "eval_op_prototypes.h"
//#include "eval_op.h"
//#include <memory>
//#include <map>

typedef std::map<std::string, std::shared_ptr<eval_op>> eval_op_proto_map;

class eval_binary;

class eval_sub: public eval_binary 

{
public:
    eval_sub() {}
    
    eval_sub(const expression &expr); //adding constructor myself
    
    tensor compute(const tensor &a, const tensor &b) override;

    std::shared_ptr<eval_op> clone(const expression &expr) override; //it is ok 
    

    static void store_prototype(eval_op_proto_map &proto_map)
    {
         assert(proto_map.find("Sub") == proto_map.end());
         proto_map["Sub"] = std::make_shared<eval_sub>();
    } 

}; // class eval_sub
#endif