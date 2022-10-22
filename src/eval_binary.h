
#ifndef EVAL_BINARY_H
#define EVAL_BINARY_H

#include <vector>
#include <string>
#include <map>
#include <iostream>
#include "tensor.h"
#include "expression.h"
#include "eval_op.h"

class eval_binary: public eval_op 
{
    virtual tensor compute(const tensor &a, const tensor &b) = 0;

public:

    eval_binary(const expression &expr);
    
    void eval(vars_type &variables, const kwargs_type &kwargs) final;

}; // class eval_binary

#endif