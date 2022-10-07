#include <assert.h>
#include "evaluation.h"
#include <vector>
#include <iostream>
#include <string.h>
#include <sstream>
#include <iterator>
#include <map>
#include "expression.h"

evaluation::evaluation(const std::vector<expression> &exprs) //a vector can be passed as a value or refernce.const so the vector exprs is not changed.just read.
    : result_(0)  //this seems a constructor initializer
{
    //for loop here
    exprs_copy=exprs;
    
    for (int i=0;i<int(exprs.size());i++){
        std::cout << "expression number:"<< i<<std::endl;
        std::cout<< exprs_copy[i].get_id()<<""<<std::endl;
        std::cout<< exprs_copy[i].get_op_name()<<""<<std::endl;
        std::cout<< exprs_copy[i].get_op_type()<<""<<std::endl;
        //std::cout<< exprs_copy[i].get_inputs()<<""<<std::endl;


        

        
        
        
       
       
     
    
    

        
    }

    
    // std::ostringstream myexprs;
    // std::copy(&exprs.begin(),&exprs.end()-1,std::ostream_iterator<expression>(myexprs,","));
    // myexprs<<&exprs.back();
    // std::cout<<myexprs.str()<<std::endl;
    //std::cout<< "this is my new ouput" << &exprs <<  std::endl;
    //std::cout<< exprs.size() <<std::endl;
    //std::cout<< "this is my element ouput" << exprs.at(0) <<  std::endl;
    


    // for (int i=0;i<myexprs.size();i++){
    //     printf(std::to_string(myexprs[i]));
    // }
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

    //iterate through 






    return -1;
}

double &evaluation::get_result()
{
    return result_;
}
