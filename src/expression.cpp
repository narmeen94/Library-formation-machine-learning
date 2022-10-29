#include "expression.h"
#include "tensor.h"

expression::expression(
    int expr_id,
    const char *op_name,
    const char *op_type,
    int *inputs,
    int num_inputs):expr_id_(expr_id), op_name_(op_name), op_type_(op_type),inputs_(inputs, inputs+num_inputs)
{
 

}

void expression::add_op_param_double(
    const char *key,
    double value)
{
    op_param_["value"]=tensor(value);
}

void expression::add_op_param_ndarray(
    const char *key,
    int dim,
    size_t shape[],
    double data[])
{
    op_param_["value"]=tensor(dim,shape,data);
}

int expression::get_id() const
{
    return expr_id_;
}

std::string expression::get_op_name() const
{
    return op_name_;
}

std::string expression::get_op_type() const
{
    return op_type_;
}

std::vector<int> expression::get_inputs() const
{
    return inputs_;
}

int expression::get_num_inputs_()
{
    return num_inputs_;
}

tensor expression::get_op_param(std::string key) const
{
    //return op_param_[value]; //won't allow this since the output of a const function is const so to access the op_param, at is used. it is a function of map.
    return op_param_.at(key);
}


    
     

