#include "eval_relu.h"
//#include "eval_op.h"
//#include "expression.h"


eval_relu::eval_relu(const expression &expr):eval_op(expr)
{

}

void eval_relu::eval(vars_type &variables, const kwargs_type &kwargs) //should it be here?
{
    tensor input_relu=variables[inputs_[0]]; //we check which id is in inputs map and then give the id to variables. 
    //variables is a map so the corresponding entry goes to input_relu which i have defined as tensor.

    int dim=input_relu.get_dim();
    size_t *shape_relu=input_relu.get_shape_array();
    double *data_relu=input_relu.get_data_array();
    std::vector<double>data_new;

    size_t N=1;
    for(int i=0;i!=dim;i++)
    {
        N=N*shape_relu[i]; //for getting the size of data_array
    }

    for (size_t i=0;i!=N;i++)
    {
        if (data_relu[i]>0)
        {
            data_new.push_back(data_relu[i]);
        }
        else if (data_relu[i]<0)
        {
            data_new.push_back(0);
        }


    }

    double *data_new_array=data_new.data();
    
    variables[expr_id_]=tensor(dim,shape_relu,data_new_array);




    
}


std::shared_ptr<eval_op> eval_relu::clone(const expression &expr) 
{
    return std::make_shared<eval_relu>(expr);
}

