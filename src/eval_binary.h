
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
    std::vector<int> inputs_;
    //int expr_id_;
    virtual tensor compute(const tensor &a, const tensor &b) = 0; //no implementation since it is virtual

public:

    virtual ~eval_binary();
    
    void eval(vars_type &variables, const kwargs_type &kwargs) final;

protected:
//since eval_binary is a base class for eval add and eval mul etc, it should have a virtual destrcutor too. let's follow the strategy in eval_op

    eval_binary() {}      

    eval_binary(const expression &expr);


}; // class eval_binary

#endif