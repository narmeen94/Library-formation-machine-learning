#ifndef EVAL_CONV2D_H
#define EVAL_CONV2D_H

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

class eval_conv2d: public eval_op 
{
    //tensor kernel_size_;
    tensor in_channels_;
    tensor out_channels_;

    tensor bias_;
    tensor weight_;
    

public:
    eval_conv2d() {}
    eval_conv2d(const expression &expr);
    

    void eval(vars_type &variables, const kwargs_type &kwargs) override;//should it be here?

    std::shared_ptr<eval_op> clone(const expression &expr) override; //it is ok 
    
   

    static void store_prototype(eval_op_proto_map &proto_map)
    {
         assert(proto_map.find("Conv2d") == proto_map.end());
         proto_map["Conv2d"] = std::make_shared<eval_conv2d>();
    } 
     

    
    
}; // class eval_conv2d
#endif