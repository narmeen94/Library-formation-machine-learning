#ifndef EVAL_ADD_H
#define EVAL_ADD_H

#include <assert.h>
#include "tensor.h"
#include "eval_binary.h"



typedef std::map<std::string, std::shared_ptr<eval_op>> eval_op_proto_map;

class eval_add: public eval_binary 
{
public:
    eval_add() {}   //adding default constructor for prototype.
    
    eval_add(const expression &expr); //adding constructor myself
    
    tensor compute(const tensor &a, const tensor &b) override; //overrride for virtual function in base class i.e. eval_binary

    std::shared_ptr<eval_op> clone(const expression &expr) override; //smart pointers 
    

    static void store_prototype(eval_op_proto_map &proto_map)
    {
         assert(proto_map.find("Add") == proto_map.end());
         proto_map["Add"] = std::make_shared<eval_add>();
    } 

}; // class eval_add
#endif