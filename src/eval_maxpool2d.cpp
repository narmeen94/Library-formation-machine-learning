#include "eval_maxpool2d.h"



eval_maxpool2d::eval_maxpool2d(const expression &expr):eval_op(expr),kernel_size_(expr.get_op_param("kernel_size"))
{

}

void eval_maxpool2d::eval(vars_type &variables, const kwargs_type &kwargs) 
{
    

    tensor input=variables[inputs_[0]]; 

    int dim=input.get_dim();
    std::cout<<"dim of input vector is:"<<dim<<std::endl;
    size_t *shape=input.get_shape_array();
    double *data=input.get_data_array();

    //for NCHW format:
    size_t N=shape[0]; 
    size_t C=shape[1]; 
    size_t H=shape[2];
    size_t W=shape[3];

    //double ksize=kernel_size_.at(0,0);
    double *data_kernel=kernel_size_.get_data_array();
    //double ksize=data_kernel[0];
    size_t ksize=data_kernel[0];
    size_t stride=ksize;
    std::cout<<"this is ksize and stride: "<< ksize<<std::endl;

     std::vector<double>data_vec;
     std::vector<double>data_max;

     for(size_t a=0;a!=N;a++)
     {
        for(size_t b=0;b!=C;b++)
        {
            for(size_t n=0;n!=(H/ksize);n++)
            {
                for(size_t m=0;m!=(W/ksize);m++)
                {
                    for(size_t i=0;i!=ksize;i++)
                    {
                        for(size_t j=0;j!=ksize;j++)
                        {
                            data_vec.push_back(data[(a*C*H*W)+(b*H*W)+((stride*n+i)*W)+(stride*m+j)]);
                        }
                    }

                    //double *data_vec_array=data_vec.data();
                    double max=data_vec[0];
                    for(int f=0;f<data_vec.size();f++)
                    {
                        if (max<data_vec[f])
                        {
                            max=data_vec[f];
                        }
                    }
                    data_max.push_back(max);
                    data_vec.clear();

                }
            }
        }
     }

     double *data_max_array=data_max.data();
     size_t shape_out[4]={N,C,(H/ksize),(W/ksize)};
     variables[expr_id_]=tensor(4,shape_out,data_max_array);
        
    
}


std::shared_ptr<eval_op> eval_maxpool2d::clone(const expression &expr) 
{
    return std::make_shared<eval_maxpool2d>(expr);
}

