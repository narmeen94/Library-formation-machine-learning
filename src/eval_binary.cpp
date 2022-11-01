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
    std::cout<<"this is input 1: "<< inputs_[0]<<std::endl;
    std::cout<<"this is input 2: "<< inputs_[1]<<std::endl;
    std::cout<<"this is size of variables map : "<< variables.size()<<std::endl;
    //std::cout<<"this is variable[0] dim: "<< variables[0].get_dim()<<std::endl;
    //std::cout<<"this is variable[last] dim: "<< variables.get_dim()<<std::endl;
    for (auto it=variables.begin();it!=variables.end();it++)
    {
        std::cout<<it->first<<"==>"<<it->second.get_dim()<<"\n";
    }



    // tensor a_narmeen=variables[inputs_[0]];
    // tensor b_narmeen=variables[inputs_[1]];
    // variables[expr_id_] = compute(a_narmeen,b_narmeen);


    auto ita = variables.find(inputs_[0]);
    auto itb = variables.find(inputs_[1]);
     // handle errors for ita and itb
     assert(ita!=variables.end());
     assert(itb!=variables.end());

    variables[expr_id_] = compute(ita->second, itb->second);
    
}