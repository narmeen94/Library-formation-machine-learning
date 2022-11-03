#ifndef EVALUATION_H
#define EVALUATION_H

#include "expression.h"
#include "tensor.h"
#include <memory>
#include "eval_op.h"



class evaluation
{
    //std::map<std::string,double>kwargs; //for inputs
    //std::vector<expression> exprs_copy;// for expressions
    //std::map<std::string,double>const_copy; //for constants
     
    
    

    //added for proj3:
    std::map<int, tensor> variables_;//for storing the expression numbers and corresponding tensors
    //i am adding the below line myself
    std::map<std::string, tensor> kwargs_;
    std::vector<std::shared_ptr<eval_op>> ops_; //for storing the key and value of the input for tensors
    tensor result_; //changed from double to tensor for proj 3

    int expr_id_;
    std::string op_name_;
    std::string op_type_;
    int *inputs_;
    int num_inputs_;
public:
    //added for proj3:
    
    evaluation(const std::vector<expression> &exprs);

    tensor &get_result();

    //evaluation(const std::vector<expression> &exprs,std::map<std::string,double>const_);
    

    void add_kwargs_double(
        const char *key,
        double value);

    void add_kwargs_ndarray(
        const char *key,
        int dim,
        size_t shape[],
        double data[]);

    // added for prj3:
    
    int execute(); //modified again in pj3


    // return the variable computed by the last expression
    //double &get_result();

    


    
   

}; // class evaluation

#endif // EVALUATION_H
