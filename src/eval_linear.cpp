#include "eval_linear.h"
#include "eval_mul.h"
#include "eval_add.h"
//#include "eval_op.h"
//#include "expression.h"


eval_linear::eval_linear(const expression &expr):eval_op(expr),weight_(expr.get_op_param("weight")),bias_(expr.get_op_param("bias")) 
{

}

void eval_linear::eval(vars_type &variables, const kwargs_type &kwargs) 
{
    std::cout<<"i am linear"<<std::endl;

    tensor input=variables[inputs_[0]]; 

    int dim=input.get_dim();
    std::cout<<"dim of input vector is:"<<dim<<std::endl;
    size_t *shape=input.get_shape_array();
    double *data=input.get_data_array();

    size_t N=shape[0]; //rows of input vector
    size_t I=shape[1]; //columns of input vector

    int dim_w=weight_.get_dim();
    size_t *shape_w=weight_.get_shape_array();
    std::cout<<"dim of weight vector is:"<<dim_w<<std::endl;

    double *data_w=weight_.get_data_array();

    size_t O=shape_w[0];  //rows of weight vector

    //int dim_b=bias_.get_dim();
    //size_t *shape_b=bias_.get_shape_array();
    double *data_b=bias_.get_data_array();

    
    std::vector<double>data_out;

    double sum=0;

    for(size_t row_in=0;row_in!=N;row_in++)
    {
        for(size_t j=0;j!=O;j++)
        {
            for(size_t i=0;i!=I;i++)
            {
                //std::cout<<"i am in linear inner most loop"<<std::endl;
                sum=sum+weight_.at(j,i)*input.at(row_in,i);
            }
            data_out.push_back(sum+bias_.at(j));
            sum=0;
        }
    }

    double *data_out_array=data_out.data();
    size_t shape_out[2]={N,O};

    variables[expr_id_]=tensor(2,shape_out,data_out_array);
    
}


std::shared_ptr<eval_op> eval_linear::clone(const expression &expr) 
{
    return std::make_shared<eval_linear>(expr);
}

