#include "eval_add.h"
#include "eval_binary.h"
#include "expression.h"
#include <assert.h>

eval_add::eval_add(const expression &expr):eval_binary(expr) //initializing base class
{   

}

tensor eval_add::compute(const tensor &a, const tensor &b) 
{

    //copying the tensors in safe places:
    tensor a_copy=a;
    tensor b_copy=b;

    //verifying if a and b have same shape:
    assert(a_copy.get_dim()==b_copy.get_dim());

    //for scalar:
    if (a_copy.get_dim()==0)
    {
        double c=a_copy.item()+b_copy.item();

        tensor c_tensor=tensor(c);
        return c_tensor;
    }

    else if (a_copy.get_dim()==1)

    size_t *shape_a = a_copy.get_shape_array();
    
    //int size_int=int(a_copy.get_shape_array());
    //shape=a_copy.get_shape_array();

    //for (size_t i=0;i< shape_a[0];)

    
        


    

    

   


    // make sure a and b to have the same shape... 
    // create c to have the same shape as a and b... 
    // add elements of a and b to obtain elements of creturn c;
    return tensor();
}

std::shared_ptr<eval_op> eval_add::clone(const expression &expr) 
{
    return std::make_shared<eval_op>(expr);
}
