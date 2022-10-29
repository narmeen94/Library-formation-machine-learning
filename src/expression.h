#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <vector>
#include <string>
#include <map>
#include <iostream>
#include "tensor.h"

class evaluation;

class expression
{
    friend class evaluation;
    int expr_id_;
    std::string op_name_;
    std::string op_type_;
    std::vector<int> inputs_;
    int num_inputs_;
    
    std::map<std::string,tensor>op_param_ ; //for consts
public:
    expression(
        int expr_id,
        const char *op_name,
        const char *op_type,
        int *inputs,
        int num_inputs);

    void add_op_param_double(
        const char *key,
        double value);

    void add_op_param_ndarray(
        const char *key,
        int dim,
        size_t shape[],
        double data[]);

    int get_id() const;

    std::string get_op_name() const;

    std::string get_op_type() const;

    std::vector<int> get_inputs() const;

    int get_num_inputs_();

    tensor get_op_param(std::string) const;
   


    

}; // class expression

#endif // EXPRESSION_H
