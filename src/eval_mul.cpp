#include <assert.h>
#include "eval_mul.h"

eval_mul::eval_mul(const expression &expr):eval_binary(expr)
{

}

std::shared_ptr<eval_op> eval_mul::clone(const expression &expr) 
{
    return std::make_shared<eval_mul>(expr);
}

tensor eval_mul::compute(const tensor &a, const tensor &b)
{
    tensor a_copy=a;
    tensor b_copy=b;

    size_t *shape_a=a_copy.get_shape_array();
    size_t *shape_b=b_copy.get_shape_array();
    double *data_a=a_copy.get_data_array();
    double *data_b=b_copy.get_data_array();

    //for a and b scalars

    if((a_copy.get_dim()==0)&&(b_copy.get_dim()==0))
    {
        return tensor(data_a[0]*data_b[0]);
    }

    

    

    std::vector<double>data_c;

    //a scalar, b tensor:

    if((a_copy.get_dim()==0)&&(b_copy.get_dim() !=0))
    {
        size_t N=1;

        for(int i=0;i!=b_copy.get_dim();i++)
        {
            N=N*shape_b[i];
        }

        for (size_t i=0;i!=N;i++)
        {
            data_c.push_back(data_b[i]*data_a[0]);
        }

        double *data_c_array=data_c.data();
        return tensor(b_copy.get_dim(),shape_b,data_c_array);
    }

    //b scalar, a tensor:

    else if((b_copy.get_dim()==0)&&(a_copy.get_dim() !=0))
    {
        size_t N=shape_a[0];

        for(int i=1;i!=a_copy.get_dim();i++)
        {
            N=N*shape_a[i];
        }

        for (size_t i=0;i!=N;i++)
        {
            data_c.push_back(data_a[i]*data_b[0]);
        }

        double *data_c_array=data_c.data();
        return tensor(a_copy.get_dim(),shape_a,data_c_array);
    }
    else{
    //both tensors
    double c=0;

    for(size_t i=0;i!=a_copy.get_shape_array()[0];i++)
    {
        for(size_t j=0;j!=b_copy.get_shape_array()[1];j++)
        {
            for(size_t k=0;k!=a_copy.get_shape_array()[1];k++)
            {
                c+=(a_copy.at(i,k)*b_copy.at(k,j));

            }
            data_c.push_back(c);
            c=0;
        }
    }

    double *data_c_array=data_c.data();
    size_t shape_c[2]={shape_a[0],shape_b[1]};
    return tensor(2,shape_c,data_c_array);
    }








}






















// #include "eval_mul.h"
// #include "eval_binary.h"
// #include "expression.h"
// #include <assert.h>

// eval_mul::eval_mul(const expression &expr):eval_binary(expr) //initializing base class
// {   

// }

// std::shared_ptr<eval_op> eval_mul::clone(const expression &expr) 
// {
//     return std::make_shared<eval_mul>(expr);
// }


// tensor eval_mul::compute(const tensor &a, const tensor &b) 
// {

//     //copying the tensors in safe places:
//     tensor a_copy=a;
//     tensor b_copy=b;

//     size_t *shape_a = a_copy.get_shape_array();
//     double *data_a=a_copy.get_data_array();

//     size_t *shape_b = b_copy.get_shape_array();
//     double *data_b=b_copy.get_data_array();

//     std::cout<<"i am here in mul compute"<<std::endl;

//     //for a and b both scalars:
//     if ((a_copy.get_dim()==0) && (b_copy.get_dim()==0))
//     {
//         double c=a_copy.item() * b_copy.item();

//         tensor c_tensor=tensor(c);
//         std::cout<<"i am here in mul  and b scalar"<<std::endl;
//         return c_tensor;
//     }
    
//     else if(a_copy.get_dim()==0 && b_copy.get_dim()!=0) {
//         //for a scalar and b tensor
//         //if(a_copy.get_dim()==0){

//             double a_scalar=a_copy.item();

//             // size_t *shape_b = b_copy.get_shape_array();
//             size_t N=1;
//             // //double *data_a=a_copy.get_data_array();
//             // double *data_b=b_copy.get_data_array();



//             for (size_t i=0;i<size_t(b_copy.get_dim());i++){

//                 N=N*shape_b[i];

//             }

//             //double data_c[N]={0};
//             std::vector<double>data_c;

//             for (size_t i=0;i<N;i++){
//                 //data_c[i]= a_scalar*data_b[i];
//                 data_c.push_back(a_scalar*data_b[i]);
//             }

//             double *data_c_array=data_c.data();
//             std::cout<<"i am here in mul a scalar"<<std::endl;

//             tensor c=tensor(b_copy.get_dim(),shape_b,data_c_array);
//             return c;
//     }
//         //for b scalar and a tensor
//         else if(b_copy.get_dim()==0 && a_copy.get_dim()!=0){

//             double b_scalar=b_copy.item();

//             //size_t *shape_a = a_copy.get_shape_array();
//             size_t N=1;
//             //double *data_a=a_copy.get_data_array();
//             //double *data_a=a_copy.get_data_array();



//             for (size_t i=0;i<size_t(a_copy.get_dim());i++){

//                 N=N*shape_a[i];

//             }

//             //double data_c[N]={0};
//             std::vector<double>data_c;
//             for (size_t i=0;i<N;i++){
//                 data_c.push_back(b_scalar*data_a[i]);
//                 //data_c[i]= b_scalar*data_a[i];
//             }

//             double *data_c_array=data_c.data();
//             tensor c_tensor=tensor(a_copy.get_dim(),shape_a,data_c_array);
//             std::cout<<"i am here in mul b scalar"<<std::endl;
//             return c_tensor;
//         }

    

//         else if ((a_copy.get_dim()>0) && (b_copy.get_dim()>0)){

//             if(shape_a[1]==shape_b[0]){
//                 //no. of columns of a should be equal to no. of rows of b for matix mul
//                 //int num_of_elem=shape_a[0]*shape_b[1];

//                 //double data_c[num_of_elem]={0};
//                 double c=0;
                
//                 std::cout<<"i am here in mulmatrix"<<std::endl;

//                 std::vector<double>data_c;
//                 //tensor c=tensor(dim_c,shape_c,data_c);
//                 //int n=0;

//                 for(size_t i=0;i!=shape_a[0];i++){
//                     for(size_t j=0;j!=shape_b[1];j++){
//                         for(size_t k=0;k!=shape_a[1];k++){
//                             //c.at(i,j)+=a_copy.at(i,k)*b_copy.at(k,j)
//                             c=c+(a_copy.at(i,k)*b_copy.at(k,j));
//                             //data_c[i]=c;
//                         }
                        
//                         data_c.push_back(c);
//                         //n++;
//                         c=0;
//                     }
//                 }

//                 //converting vector to array:
//                 //int dim_c=a_copy.get_dim();

//                 size_t shape_c[2]={shape_a[0],shape_b[1]};
//                 double *data_c_array=data_c.data();
                
                
//                 tensor c_tensor=tensor(2,shape_c,data_c_array);
//                 return c_tensor;


//             }  

//     return tensor();
//     }

    



    
    
// }
