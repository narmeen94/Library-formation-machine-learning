#include <assert.h>
#include "evaluation.h"
#include <vector>
#include <iostream>
#include <string.h>
#include <sstream>
#include <iterator>

evaluation::evaluation(const std::vector<expression> &exprs)
    : result_(0)  //this seems a constructor initializer
{
    // for (int i=0;i<exprs.size();i++){
    //     printf(toString(exprs[i]));
    // }

    
    // std::ostringstream myexprs;
    // std::copy(&exprs.begin(),&exprs.end()-1,std::ostream_iterator<expression>(myexprs,","));
    // myexprs<<&exprs.back();
    // std::cout<<myexprs.str()<<std::endl;
    std::cout<< "this is my new ouput" << &exprs <<  std::endl;
    std::cout<< exprs.size() <<std::endl;
    std::cout<< "this is my element ouput" << exprs.at(0) <<  std::endl;
    


    // for (int i=0;i<myexprs.size();i++){
    //     printf(std::to_string(myexprs[i]));
    // }
}

void evaluation::add_kwargs_double(
    const char *key,
    double value)
{
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
    return -1;
}

double &evaluation::get_result()
{
    return result_;
}
