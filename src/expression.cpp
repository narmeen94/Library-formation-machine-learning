#include "expression.h"

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
}

void expression::add_op_param_ndarray(
    const char *key,
    int dim,
    size_t shape[],
    double data[])
{
}
//  void expression::print_output(std::vector<expression>&exprs)
//  {
//     std::cout <<&exprs.expr_id_<<std::endl; 
//  }
// int expression::get_id() {
    
//     return expr_id;}
