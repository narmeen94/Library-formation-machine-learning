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
class eval_const: public eval_op 
{
    tensor value_;
    

public:
    eval_const() {}
    eval_const(const expression &expr);
    

    //void eval(vars_type &variables, const kwargs_type &kwargs) override;

    std::shared_ptr<eval_op> clone(const expression &expr) override;
    
    //void eval(vars_type &variables, const kwargs_type &kwargs);

     void eval_const::store_prototype(eval_op_proto_map &proto_map);
    //void eval_const::store_prototype(proto_map_);

    
    
}; // class eval_const