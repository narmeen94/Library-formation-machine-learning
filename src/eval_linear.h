#ifndef EVAL_LINEAR_H
#define EVAL_LINEAR_H

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

class eval_linear: public eval_op 
{
    tensor weight_;
    tensor bias_;
    

public:
    eval_linear() {}
    eval_linear(const expression &expr);
    

    void eval(vars_type &variables, const kwargs_type &kwargs) override;//should it be here?

    std::shared_ptr<eval_op> clone(const expression &expr) override; //it is ok 
    
   

    static void store_prototype(eval_op_proto_map &proto_map)
    {
         assert(proto_map.find("Linear") == proto_map.end());
         proto_map["Linear"] = std::make_shared<eval_linear>();
    } 
     

    
    
}; // class eval_linear
#endif