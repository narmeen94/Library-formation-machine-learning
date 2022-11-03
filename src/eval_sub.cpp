#include "eval_sub.h"
//#include "eval_binary.h"
//#include "expression.h"
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
     assert(a_copy.get_dim()==b_copy.get_dim());  //when i used if , warning:control reaches end of non-void function

     int dim_c=a_copy.get_dim(); //because c would have the same dimensions as a or b

     size_t *shape_a = a_copy.get_shape_array();
     

    //  for(int i=0;i!=dim_c;i++)
    //  {
    //     assert(shape_a[i]==shape_b[i]);
    //  }

     //a and b scalars:

     if(a_copy.get_dim()==0)
     {
        return tensor(a_copy.get_data_array()[0]-b_copy.get_data_array()[0]);
     }

     //both tensprs

     double *data_a=a_copy.get_data_array();
     double *data_b=b_copy.get_data_array();

     size_t N=1;
     for(int i=0;i!=dim_c;i++)
     {
        N=N*shape_a[i];
     }

     std::vector<double>data_c;

     for(size_t i=0;i!=N;i++)
     {
        data_c.push_back(data_a[i]-data_b[i]);
     }

     double *data_c_array=data_c.data();
     return tensor(dim_c,shape_a,data_c_array);
}

