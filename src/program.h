#ifndef PROGRAM_H
#define PROGRAM_H

#include "expression.h"

class evaluation;
class expression;

class program
{
    std::vector<expression> exprs_; //for the expression objects
    std::map<std::string,tensor>op_param_; //for the constants
    

public:
    program();

    void append_expression(
        int expr_id,
        const char *op_name,
        const char *op_type,
        int inputs[],
        int num_inputs);
        
    // return 0 for success
    int add_op_param_double(
        const char *key,
        double value);

    // return 0 for success
    int add_op_param_ndarray(
        const char *key,
        int dim,
        size_t shape[],
        double data[]);

    evaluation *build();

    

    
}; // class program

#endif // PROGRAM_H
