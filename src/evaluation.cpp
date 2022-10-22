#include <assert.h>
#include "evaluation.h"
#include <vector>
#include <iostream>
#include <string.h>
#include <sstream>
#include <iterator>
#include <map>
#include <memory>
#include "expression.h"
#include "eval_op.h"

// evaluation::evaluation(const std::vector<expression> &exprs,std::map<std::string,double>const_) //a vector can be passed as a value or refernce.const so the vector exprs is not changed.just read.
//     : result_(0)  //constructor initializer
// {
    
//     exprs_copy=exprs;
//     const_copy=const_;
    
//     for (int i=0;i<int(exprs.size());i++){
//         std::cout << "expression number:"<< exprs_copy[i].get_id()<<std::endl;
//         std::cout<< "this is expression id:"<< exprs_copy[i].get_id()<<""<<std::endl;
//         std::cout<< "this is operand name:"<< exprs_copy[i].get_op_name()<<""<<std::endl;
//         std::cout<< "this is operator type:"<<exprs_copy[i].get_op_type()<<""<<std::endl;
//         //std::cout<< exprs_copy[i].get_inputs()<<""<<std::endl;   
//     }

    
// }

// evaluation::evaluation(const std::vector<expression> &exprs) 
// {
//     for (auto &expr: exprs) 
//     {
//         if (expr.get_op_type() == "Input") 
//         {
//             ops_.push_back(std::make_shared<eval_input>(expr));
//         }
        
//         else if (expr.get_op_type() == "Const")
//         {
//             ops_.push_back(std::make_shared<eval_const>(expr));
//         }
        
//         else if (expr.get_op_type() == "Add")
//         {
//             ops_.push_back(std::make_shared<eval_add>(expr));
//         }

//     }
// }

// evaluation::evaluation(const std::vector<expression> &exprs,eval_op_proto_map &proto_map) 
// {
//     for (auto &expr: exprs) 
//     {
//         auto it = proto_map.find(expr.get_op_type());
//         if (it == proto_map.end()); 
//         // handling errors
//         ops_.push_back(it->second->clone(expr));
//     }
// }

evaluation::evaluation(const std::vector<expression> &exprs) 
{
    for (auto &expr: exprs) 
    {
        std::shared_ptr<eval_op> p= eval_op_prototypes::instance().locate(expr.get_op_type());
        ops_.push_back(p->clone(expr)); 
    }
}

void evaluation::add_kwargs_double(
    const char *key,
    double value)
    
{  
    printf("this is from kwargs/evaluation, Input is %s ,and its value is %f\n",key,value);
    kwargs[key]=value;
    //printf("verifying map,value =%f\n",kwargs["a"]); 
}

void evaluation::add_kwargs_ndarray(
    const char *key,
    int dim,
    size_t shape[],
    double data[])
{
}

// int evaluation::execute(evaluation *eval,int *p_dim, size_t **p_shape, double **p_data)
// {

//     tensor &res = eval->get_result();
//     *p_dim = res.get_dim();
//     *p_shape = res.get_shape_array();
//     *p_data = res.get_data_array();
//     return 0;
// }


int evaluation::execute() 
{
    //also include error handling here.
    variables_.clear();
    for (auto &op: ops_) 
    {
        op->eval(variables_, kwargs_);
    }
    return 0;
}

//     double value_a=kwargs["a"];
//     printf("the input a has value: %f\n",value_a);

//     double value_const=const_copy["value"];
//     printf("this is constant: %f\n",value_const);

//     //iterate through the expressions and see what is the operator type.
//     int vec_size=exprs_copy.size();
//     for (int i=0;i<vec_size;i++){

//         if (exprs_copy[i].get_op_type()== "Input"){
//             //int num_inputs=exprs_copy[i].get_inputs().size();
//             double input_value=kwargs[exprs_copy[i].get_op_name()];
//             result_=input_value;
//             variables_[exprs_copy[i].get_id()]=input_value;          
//         }

//         else if (exprs_copy[i].get_op_type()== "Const"){
//             double const_value=const_copy["value"];
//             variables_[exprs_copy[i].get_id()]=const_value;
//             std::cout<<const_value<<"should be the output of const"<<std::endl;     
//         }
//         else if (exprs_copy[i].get_op_type()== "Add"){
            
//             int inputs_size=exprs_copy[i].get_inputs().size();
//             double sum=0;
//             for(int k=0;k<inputs_size;k++){
//                    int expr_num=exprs_copy[i].get_inputs()[k];
//                    sum=sum+variables_[expr_num];
//             }
            
//             variables_[exprs_copy[i].get_id()]=sum;
//             std::cout<<variables_[exprs_copy[i].get_id()]<<"  printing result for add"<<std::endl;

//         }

//         else if (exprs_copy[i].get_op_type()== "Sub"){
            
//             //int inputs_size=exprs_copy[i].get_inputs().size();
//             //std::cout<<inputs_size<<"this is the num2 of inputs for add"<<std::endl;
//             // int inputs_size=exprs_copy[i].get_inputs().size();
//             // //std::cout<<inputs_size<<"this is the num2 of inputs for add"<<std::endl;
//             // double sub=variables_[0];
//             // for(int k=1;k<inputs_size;k++){
//             //        int expr_num=exprs_copy[i].get_inputs()[k];
//             //        sub=sub+variables_[expr_num];
                
                
            

//             double sum; 
//             // for(int k=0;k<inputs_size;k++){
//                    int expr_num1=exprs_copy[i].get_inputs()[0];
//                    int expr_num2=exprs_copy[i].get_inputs()[1];
//                    sum=variables_[expr_num1]-variables_[expr_num2];
            
//             variables_[exprs_copy[i].get_id()]=sum;
//             std::cout<<variables_[exprs_copy[i].get_id()]<<"  printing result for Sub"<<std::endl;
//         }


//         else if (exprs_copy[i].get_op_type()== "Mul"){
            
//             int inputs_size=exprs_copy[i].get_inputs().size();
//             //std::cout<<inputs_size<<"this is the num2 of inputs for add"<<std::endl;
//             double product=1;
//             for(int k=0;k<inputs_size;k++){
//                    int expr_num=exprs_copy[i].get_inputs()[k];
//                    product=product*variables_[expr_num];
                
//             }
//             variables_[exprs_copy[i].get_id()]=product;
//             result_=product;
//             std::cout<<variables_[exprs_copy[i].get_id()]<<"printing result for mul"<<std::endl;

//     }
    
// }
// result_=variables_[exprs_copy.size()-1];
// std::cout<< "final result is: "<<result_<<std::endl;


// return 0;
// }

double &evaluation::get_result()
{
    return result_;
}
    


