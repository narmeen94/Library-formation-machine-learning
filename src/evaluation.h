#ifndef EVALUATION_H
#define EVALUATION_H

#include "expression.h"

class evaluation
{
    std::map<std::string,double>kwargs; 
    std::vector<expression> exprs_copy;
    std::map<std::string,double>const_copy;
    
    std::map<int,double>variables_;

    int expr_id_;
    std::string op_name_;
    std::string op_type_;
    int *inputs_;
    int num_inputs_;
public:
    

    evaluation(const std::vector<expression> &exprs,std::map<std::string,double>const_);

    void add_kwargs_double(
        const char *key,
        double value);

    void add_kwargs_ndarray(
        const char *key,
        int dim,
        size_t shape[],
        double data[]);

    // return 0 for success
    int execute();


    // return the variable computed by the last expression
    double &get_result();

    

private:
    double result_;
}; // class evaluation

#endif // EVALUATION_H
