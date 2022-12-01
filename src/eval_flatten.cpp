#include "eval_flatten.h"
//#include "eval_op.h"
//#include "expression.h"


eval_flatten::eval_flatten(const expression &expr):eval_op(expr)
{

}

void eval_flatten::eval(vars_type &variables, const kwargs_type &kwargs) //should it be here?
{
    tensor input_flatten=variables[inputs_[0]]; //we check which id is in inputs map and then give the id to variables. 
    //variables is a map so the corresponding entry goes to input_relu which i have defined as tensor.

    int dim=input_flatten.get_dim();
    size_t *shape_flatten=input_flatten.get_shape_array();
    double *data_flatten=input_flatten.get_data_array();
    

    size_t N=shape_flatten[0];
    size_t C=shape_flatten[1];
    size_t H=shape_flatten[2];
    size_t W=shape_flatten[3];


    size_t shape_new[2]={N,(C*H*W)};

    
    variables[expr_id_]=tensor(2,shape_new,data_flatten);
    
}


std::shared_ptr<eval_op> eval_flatten::clone(const expression &expr) 
{
    return std::make_shared<eval_flatten>(expr);
}

