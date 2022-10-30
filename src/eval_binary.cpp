#include "eval_binary.h"
#include <assert.h>

eval_binary::~eval_binary() 
{

}

eval_binary::eval_binary(const expression &expr):inputs_(expr.get_inputs())
{

}

void eval_binary::eval(vars_type &variables, const kwargs_type &kwargs) 
{   
    printf("number of inputs is : %zu",inputs_.size());
    assert(inputs_.size() == 2);
    auto ita = variables.find(inputs_[0]);
    auto itb = variables.find(inputs_[1]);
     // handle errors for ita and itb
    variables[expr_id_] = compute(ita->second, itb->second);
    
}