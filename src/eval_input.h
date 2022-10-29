
#include <vector>
#include <string>
#include <map>
#include <iostream>
//#include "tensor.h"
//#include "expression.h"
#include "eval_op.h"
//#include <assert.h>
#include "eval_const.h"
//#include "eval_op_prototypes.h"


typedef std::map<std::string, std::shared_ptr<eval_op>> eval_op_proto_map;

class eval_op;

class eval_input: public eval_op 
{
    tensor value_;
    

public:
    eval_input() {}
    eval_input(const expression &expr);
    

    void eval(vars_type &variables, const kwargs_type &kwargs); 

    std::shared_ptr<eval_op> clone(const expression &expr) override; //it is ok 
    
   

    static void store_prototype(eval_op_proto_map &proto_map)
    {
         assert(proto_map.find("Input") == proto_map.end());
         proto_map["Input"] = std::make_shared<eval_input>();
    } 
     

    
    
}; // class eval_input