#ifndef EVAL_ADD_H
#define EVAL_ADD_H

#include <vector>
#include <string>
#include <map>
#include <iostream>
#include "tensor.h"
#include "expression.h"
#include "eval_binary.h"

class eval_add: public eval_binary 
{
public:
    eval_add(const expression &expr); //adding constructor myself
    
    tensor compute(const tensor &a, const tensor &b) override;

}; // class eval_add
#endif