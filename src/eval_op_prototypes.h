#ifndef EVAL_OP_PROTOTYPE_H
#define EVAL_OP_PROTOTYPE_H


#include "eval_op.h"

typedef std::map<std::string, std::shared_ptr<eval_op>> eval_op_proto_map;

class eval_op_prototypes 
{
    

    eval_op_prototypes(const eval_op_prototypes &) = delete;      // prevent creation of additional instances
    eval_op_prototypes();
    
    eval_op_proto_map proto_map_;

public:

    std::shared_ptr<eval_op> locate(std::string name);

    static eval_op_prototypes &instance();                       // access the only instance

}; // class eval_op_prototypes
#endif