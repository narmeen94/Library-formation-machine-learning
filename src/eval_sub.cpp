#include "eval_sub.h"
#include "eval_binary.h"
#include "expression.h"
#include <assert.h>

eval_sub::eval_sub(const expression &expr):eval_binary(expr) //initializing base class
{   

}

std::shared_ptr<eval_op> eval_sub::clone(const expression &expr) 
{
    return std::make_shared<eval_sub>(expr);
}


tensor eval_sub::compute(const tensor &a, const tensor &b) 
{

    //copying the tensors in safe places:
    tensor a_copy=a;
    tensor b_copy=b;

    //verifying if a and b have same shape:
    assert(a_copy.get_dim()==b_copy.get_dim());

    //size_t *size_a = a_copy.get_shape_array();
    //size_t S=size_a[0];
    

    //for scalar:
    if (a_copy.get_dim()==0)
    {
        double c=a_copy.item()-b_copy.item();

        tensor c_tensor=tensor(c);
        return c_tensor;
    }

    //for other than scalar
    if (a_copy.get_dim()>0)
    {
        size_t *shape_a = a_copy.get_shape_array();
        size_t N=1;
        double *data_a=a_copy.get_data_array();
        double *data_b=b_copy.get_data_array();



        for (size_t i=0;i<size_t(a_copy.get_dim());i++){

            N=N*shape_a[i];

        }

        double data_c[N]={0};
        for (size_t i=0;i<N;i++){
            data_c[i]= data_a[i]-data_b[i];
        }

        tensor c=tensor(a_copy.get_dim(),shape_a,data_c);
        return c;
                               
        

    }
}