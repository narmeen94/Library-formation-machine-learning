#ifndef EVAL_OP_H
#define EVAL_OP_H



#include <map>

#include <memory>
#include "tensor.h"
#include "expression.h"
//#include "eval_op_prototypes.h"

typedef std::map<int, tensor> vars_type;
typedef std::map<std::string, tensor> kwargs_type;

class eval_op  //eval_op refers to an expression to be evaluated.
{
protected:
    int expr_id_;
    std::string op_name_, op_type_;
    std::vector<int> inputs_;

    eval_op(): expr_id_(-1) {}      //for prototyping, adding default constructors
    
    
    eval_op(const expression &expr);

public:
    

    virtual ~eval_op();

    virtual void eval(vars_type &variables, const kwargs_type &kwargs)=0;

    virtual std::shared_ptr<eval_op> clone(const expression &expr) = 0;

    int get_id_op() const; 
    
    
    


}; // class eval_op
#endif