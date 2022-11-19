#include "eval_conv2d.h"



eval_conv2d::eval_conv2d(const expression &expr):eval_op(expr),bias_(expr.get_op_param("bias")),in_channels_(expr.get_op_param("in_channels")),out_channels_(expr.get_op_param("out_channels")),weight_(expr.get_op_param("weight"))
{

}

void eval_conv2d::eval(vars_type &variables, const kwargs_type &kwargs) 
{
    

    tensor input=variables[inputs_[0]]; 

    int dim=input.get_dim();
    std::cout<<"dim of input vector is:"<<dim<<std::endl;
    size_t *shape=input.get_shape_array();
    double *data=input.get_data_array();

    //for NCHW format:
    size_t N=shape[0]; 
    size_t Cin=shape[1]; 
    size_t H=shape[2];
    size_t W=shape[3];

    size_t *shape_w=weight_.get_shape_array();
    double *data_w=weight_.get_data_array();
    size_t Cout=shape_w[0];
    size_t k=shape_w[2];

    

    std::cout<<"this is ksize  "<< k<<std::endl;
    std::cout<<"this is inchannels  "<< Cin<<std::endl;
    std::cout<<"this is outchannels  "<< Cout<<std::endl;


    std::vector<double>data_vec;
    double sum=0;

    for(size_t a=0;a!=N;a++)
    {
        for(size_t b=0;b!=Cout;b++)
        {
            for(size_t n=0;n!=(H-k+1);n++)
            {
                for(size_t m=0;m!=(W-k+1);m++)
                {
                    for(size_t c=0;c!=Cin;c++)
                    {

                        for(size_t i=0;i!=k;i++)
                        {
                            for(size_t j=0;j!=k;j++)
                            {
                                //sum=sum+data[(a*Cin*H*W)+(b*H*W)+(n+i)*W+(m+j)] * data_w[(a*Cin*k*k)+(b*k*k)+(i*k)+j];
                                sum=sum+data[(a*Cin*H*W)+(c*H*W)+(n+i)*W+(m+j)] * data_w[(b*Cin*k*k)+(c*k*k)+(i*k)+j];

                                
                            }
                        }
                        
                        
                        

                    }
                    data_vec.push_back(sum+bias_.at(b));
                    sum=0;
                }
            }
        }
    }

    // for(size_t a=0;a!=N;a++)
    // {
    //     for(size_t b=0;b!=Cout;b++)
    //     {
    //         for(size_t c=0;c!=Cin;c++)
    //         {
    //             for(size_t n=0;n!=(H-k+1);n++)
    //             {
    //                 for(size_t m=0;m!=(W-k+1);m++)
    //                 {
    //                     for(size_t i=0;i!=k;i++)
    //                     {
    //                         for(size_t j=0;j!=k;j++)
    //                         {
    //                             //sum=sum+data[(a*Cin*H*W)+(b*H*W)+(n+i)*W+(m+j)] * data_w[(a*Cin*k*k)+(b*k*k)+(i*k)+j];
    //                             sum=sum+data[(a*Cin*H*W)+(c*H*W)+(n+i)*W+(m+j)] * data_w[(b*Cin*k*k)+(c*k*k)+(i*k)+j];

                                
    //                         }
    //                     }
                        
    //                     data_vec.push_back(sum+bias_.at(b));
    //                     sum=0;
    //                 }
    //             }
    //         }
    //     }
    // }

    double *data_vec_array=data_vec.data();
    size_t shape_out[4]={N,Cout,(H-k+1),(W-k+1)};
    variables[expr_id_]=tensor(4,shape_out,data_vec_array);


     

     
    
}


std::shared_ptr<eval_op> eval_conv2d::clone(const expression &expr) 
{
    return std::make_shared<eval_conv2d>(expr);
}

