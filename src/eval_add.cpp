#include "eval_add.h"
//#include "eval_binary.h"
//#include "expression.h"
#include <assert.h>

eval_add::eval_add(const expression &expr):eval_binary(expr) //initializing base class
{   

}

std::shared_ptr<eval_op> eval_add::clone(const expression &expr) 
{
    return std::make_shared<eval_add>(expr);
}


tensor eval_add::compute(const tensor &a, const tensor &b) 
{

    //copying the tensors in safe places:
    tensor a_copy=a;
    tensor b_copy=b;


    //verifying if a and b have same shape:
     assert(a_copy.get_dim()==b_copy.get_dim());  //when i used if , warning:control reaches end of non-void function

     int dim_c=a_copy.get_dim();

     size_t *shape_a = a_copy.get_shape_array();
     

    //  for(int i=0;i!=dim_c;i++)
    //  {
    //     assert(shape_a[i]==shape_b[i]);
    //  }

     //a and b scalars:

     if(a_copy.get_dim()==0)
     {
        return tensor(a_copy.get_data_array()[0]+b_copy.get_data_array()[0]);
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
        data_c.push_back(data_a[i]+data_b[i]);
     }

     double *data_c_array=data_c.data();
     return tensor(dim_c,shape_a,data_c_array);
}




//     //size_t *size_a = a_copy.get_shape_array();
//     //size_t S=size_a[0];
    

//     //for scalar:
//     if (a_copy.get_dim()==0)
//     {
//         double c=a_copy.item()+b_copy.item();

//         tensor c_tensor=tensor(c);
//         return c_tensor;
//     }

//     //for other than scalar
//     if (a_copy.get_dim()>0)
//     {
//         size_t *shape_a = a_copy.get_shape_array();
//         size_t N=1;
//         double *data_a=a_copy.get_data_array();
//         double *data_b=b_copy.get_data_array();



//         for (size_t i=0;i<size_t(a_copy.get_dim());i++){

//             N=N*shape_a[i];

//         }

//         //double data_c[N]={0};
//         std::vector<double> data_c;
//         for (size_t i=0;i<N;i++){
//             //data_c[i]= data_a[i]+data_b[i];
//             data_c.push_back(data_a[i]+data_b[i]);
//         }
//         double *data_c_array=data_c.data();
//         tensor c=tensor(a_copy.get_dim(),shape_a,data_c_array);
//         return c;
                               
        

//     }
// }



//  below code is a try with arrays:

    // else if (a_copy.get_dim()==1)
    // {
    //     //size_t *size_a = a_copy.get_shape_array();
    //     // size_t S=size_a[0];
    //     double data_c[S]={0};
        
    //     for (size_t i=0;i<S;i++)
    //     {
    //         data_c[i]=a.at(i)+b.at(i);

    //     }

    //     tensor c=tensor(a_copy.get_dim(),a_copy.get_shape_array(),data_c);
    //     return c;

    // }

    // else
    // {
    //     size_t size_matrix=size_a[0]*size_a[1];
    //     double data_c[size_matrix]={0};

    //     for(size_t i=0;i<size_a[0];i++)
    //     {
    //         for(size_t j=0;j<size_a[1];j++)
    //         {
    //             data_c[j]

    //         }
    //     }

    // }
    //return tensor();


