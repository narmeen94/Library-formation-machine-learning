#ifndef EVAL_MAXPOOL2D_H
#define EVAL_MAXPOOL2D_H

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

class eval_maxpool2d: public eval_op 
{
    tensor kernel_size_;
    //tensor bias_;
    

public:
    eval_maxpool2d() {}
    eval_maxpool2d(const expression &expr);
    

    void eval(vars_type &variables, const kwargs_type &kwargs) override;//should it be here?

    std::shared_ptr<eval_op> clone(const expression &expr) override; //it is ok 
    
   

    static void store_prototype(eval_op_proto_map &proto_map)
    {
         assert(proto_map.find("MaxPool2d") == proto_map.end());
         proto_map["MaxPool2d"] = std::make_shared<eval_maxpool2d>();
    } 
     

    
    
}; // class eval_maxpool2d
#endif