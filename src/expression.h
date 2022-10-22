#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <vector>
#include <string>
#include <map>
#include <iostream>

class evaluation;

class expression
{
    friend class evaluation;
    int expr_id_;
    std::string op_name_;
    std::string op_type_;
    std::vector<int> inputs_;
    int num_inputs_;
    double op_param_;  //for consts
    //std::map<std::string,double>const_;
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

    int get_id();

    std::string get_op_name() ;

    std::string get_op_type() const;
    std::vector<int> get_inputs();
    int get_num_inputs_();
    //std::map<std::string,double> get_const_();
    double get_op_param()const;
   // void print_output(std::vector<expression>&exprs);


    

}; // class expression

#endif // EXPRESSION_H
