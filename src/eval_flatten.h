#ifndef EVAL_FLATTEN_H
#define EVAL_FLATTEN_H

#include <vector>
#include <string>
#include <map>
#include <iostream>
#include "tensor.h"
#include "expression.h"
#include "eval_op.h"
#include "eval_op_prototypes.h"
#include <assert.h>

typedef std::map<std::string, std::shared_ptr<eval_op>> eval_op_proto_map;

class eval_flatten: public eval_op 
{
    //tensor value_;
    

public:
    eval_flatten() {}
    eval_flatten(const expression &expr);
    

    void eval(vars_type &variables, const kwargs_type &kwargs) override;//should it be here?

    std::shared_ptr<eval_op> clone(const expression &expr) override; //it is ok 
    
   

    static void store_prototype(eval_op_proto_map &proto_map)
    {
         assert(proto_map.find("Flatten") == proto_map.end());
         proto_map["Flatten"] = std::make_shared<eval_flatten>();
    } 
     //eval_const::store_prototype(proto_map_);

    
    
}; // class eval_relu
#endif