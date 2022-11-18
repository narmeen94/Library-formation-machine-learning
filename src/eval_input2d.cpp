#include "eval_input2d.h"
//#include "eval_op.h"
//#include "expression.h"


eval_input2d::eval_input2d(const expression &expr):eval_op(expr)
{

}

void eval_input2d::eval(vars_type &variables, const kwargs_type &kwargs) //should it be here?
{
    //variables[expr_id_]=kwargs.at(op_name_);
    tensor input=kwargs.at(op_name_);
    //tensor input=variables[expr_id_]; //we check which id is in inputs map and then give the id to variables. 
    //variables is a map so the corresponding entry goes to input_relu which i have defined as tensor.

    int dim=input.get_dim();
    size_t *shape=input.get_shape_array();
    double *data=input.get_data_array();
    

    size_t N=shape[0];
    size_t H=shape[1];
    size_t W=shape[2];
    size_t C=shape[3];

    // size_t N=shape[0];
    // size_t C=shape[1];
    // size_t H=shape[2];
    // size_t W=shape[3];


    size_t shape_new[4]={N,C,H,W};

    //for new data array:
    std::vector<double>new_data;

    for (size_t i0=0;i0!=shape_new[0];i0++) 
    {
        for (size_t i1=0;i1!=shape_new[1];i1++)
        {
            for (size_t i2=0;i2!=shape_new[2];i2++)
            {
                for (size_t i3=0;i3!=shape_new[3];i3++ )
                {
                    //new_data.push_back(data[(i0*(shape_new[1]*shape_new[2]*shape_new[3]))+(i1*(shape_new[2]*shape_new[3]))+(i2*(shape_new[3]))+i3]);
                   //new_data.push_back(data[(i0*(shape[1]*shape[2]*shape[3]))+(i1*(shape[2]*shape[3]))+(i2*(shape[3]))+i3]);

                   new_data.push_back(data[(i0*shape[1]*shape[2]*shape[3])+(i2*shape[2]*shape[3])+(i3*shape[3])+i1]);  //converting from NHWC to NCHW requires this transformation.
                   //this is basically A(n,c,h,w)=n*CHW + h*HW + W*w + c

                }
            }
        }
    }

    double *new_data_array=new_data.data();
    variables[expr_id_]=tensor(4,shape_new,new_data_array);




    
}


std::shared_ptr<eval_op> eval_input2d::clone(const expression &expr) 
{
    return std::make_shared<eval_input2d>(expr);
}

