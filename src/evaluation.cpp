#include <assert.h>
#include "evaluation.h"
#include <vector>
#include <iostream>
#include <string.h>
#include <sstream>
#include <iterator>
#include <map>
#include "expression.h"

evaluation::evaluation(const std::vector<expression> &exprs,std::map<std::string,double>const_) //a vector can be passed as a value or refernce.const so the vector exprs is not changed.just read.
    : result_(0)  //this seems a constructor initializer
{
    //for loop here
    exprs_copy=exprs;
    const_copy=const_;
    
    for (int i=0;i<int(exprs.size());i++){
        std::cout << "expression number:"<< i<<std::endl;
        std::cout<< "this is expression id:"<< exprs_copy[i].get_id()<<""<<std::endl;
        std::cout<< "this is operand name:"<< exprs_copy[i].get_op_name()<<""<<std::endl;
        std::cout<< "this is operator type:"<<exprs_copy[i].get_op_type()<<""<<std::endl;
        //std::cout<< exprs_copy[i].get_inputs()<<""<<std::endl;   
    }

    
}

void evaluation::add_kwargs_double(
    const char *key,
    double value)
    
{
    //std::string skey=key;
    printf("this is from kwargs/evaluation, Input is %s ,and its value is %f\n",key,value);
    //std::map<std::string,double>kwargs;
    kwargs[key]=value;
    printf("verifying map,value =%f\n",kwargs["a"]);
    
}

void evaluation::add_kwargs_ndarray(
    const char *key,
    int dim,
    size_t shape[],
    double data[])
{
}

int evaluation::execute()
{
    double value_a=kwargs["a"];
    printf("the input a has value: %f\n",value_a);

    double value_const=const_copy["value"];
    printf("this is constant: %f\n",value_const);

    //iterate through the expressions and see what is the operator type.
    int vec_size=exprs_copy.size();
    //std::cout << vec_size << std::endl;
    for (int i=0;i<vec_size;i++){

        if (exprs_copy[i].get_op_type()== "Input"){
            //int num_inputs=exprs_copy[i].get_inputs().size();
            double input_value=kwargs[exprs_copy[i].get_op_name()];
            result_=input_value;
            variables_[exprs_copy[i].expr_id_]=input_value;
            
            
        }

        else if (exprs_copy[i].get_op_type()== "Const"){

            
            
           
            

            double const_value=const_copy["value"];
            variables_[i]=const_value;
            std::cout<<const_value<<"should be the output of const"<<std::endl;
            
            
        }
        else if (exprs_copy[i].get_op_type()== "Add"){
            
            int inputs_size=exprs_copy[i].get_inputs().size();
            //std::cout<<inputs_size<<"this is the num2 of inputs for add"<<std::endl;
            double sum=0;
            for(int k=0;k<inputs_size;k++){
                   int expr_num=exprs_copy[i].get_inputs()[k];
                   sum=sum+variables_[expr_num];
                // int expr_num=exprs_copy[i].get_inputs()[k]; //it is zero for expr id 0
                // double input_value=kwargs[exprs_copy[expr_num].get_op_name()]; //access expr 0's opname's i.e. a's value i.e. 5
                // //this will happen for every input
                // std::cout<<input_value<<"this should be the valur of input 0"<<std::endl;
                // sum=input_value;
                // sum=sum+input_value;
                // //result_=result_+input_value;
                // //std::cout<<sum<<"this is the final sum"<<std::endl;
                // //result_=result_+sum-result_;
                
            }
            //std::cout<<sum<<"this is the final sum for add"<<std::endl;
            
            
            
            //result_=sum+result_;
            variables_[i]=sum;
            std::cout<<variables_[i]<<"  printing result for add"<<std::endl;

        }

        else if (exprs_copy[i].get_op_type()== "Sub"){
            
            int inputs_size=exprs_copy[i].get_inputs().size();
            //std::cout<<inputs_size<<"this is the num2 of inputs for add"<<std::endl;
            double sum=0;
            for(int k=0;k<inputs_size;k++){
                   int expr_num=exprs_copy[i].get_inputs()[k];
                   if (k==0){
                    sum=variables_[expr_num];
                   }
                   else{
                    sum=sum-variables_[expr_num];

                   }
                   
                   
                
                
            }
            
            //result_=sum+result_;
            variables_[i]=sum;
            std::cout<<variables_[i]<<"  printing result for Sub"<<std::endl;
        }


        else if (exprs_copy[i].get_op_type()== "Mul"){
            
            int inputs_size=exprs_copy[i].get_inputs().size();
            //std::cout<<inputs_size<<"this is the num2 of inputs for add"<<std::endl;
            double product=1;
            for(int k=0;k<inputs_size;k++){
                   int expr_num=exprs_copy[i].get_inputs()[k];
                   product=product*variables_[expr_num];

                // int expr_num=exprs_copy[i].get_inputs()[k]; //it is zero for expr id 0
                // double input_value=kwargs[exprs_copy[expr_num].get_op_name()]; //access expr 0's opname's i.e. a's value i.e. 5
                // //this will happen for every input
                // std::cout<<input_value<<"this should be the valur of input 0"<<std::endl;
                // //int sum=input_value;
                // product=product*input_value;
                // //std::cout<<product<<"this is the final product"<<std::endl;
                // //result_=product;
                
            }
            variables_[i]=product;
            result_=product;
            std::cout<<variables_[i]<<"printing result for mul"<<std::endl;

    }
    






    
}
result_=variables_[exprs_copy.size()-1];
std::cout<< "final result is: "<<result_<<std::endl;
return 0;
}

double &evaluation::get_result()
{
    return result_;
}



