#include "tensor.h"
#include <assert.h>

tensor::tensor():
data_(1, 0)  //it means it has one element that is 0
{

}

tensor::tensor(double v):
data_(1, v) // 1 element that is v
{

}

tensor::tensor(int dim, size_t shape[], double data[]):
shape_(shape, shape+dim)                    //initialize dimensions myself
{
    // calculate N as shape[0]*shape[1]*...*shape[dim-1]
    int N=1;
    for (int i=0;i<dim;i++)
    {                           
        N=N*shape[i];

    }
    //int N=sizeof(shape_)/sizeof(shape_[0]);
    
    data_.assign(data, data+N);
}

double tensor::item() const 
{
    assert(shape_.empty());
    return data_[0];        //to get the scalar value that is read only
}

double &tensor::item() 
{
    assert(shape_.empty());
    return data_[0];       //to get the scalar value so we can have operations with it too.
}

double tensor::at(size_t i) const 
{
    assert(get_dim() == 1);        
    assert(i < shape_[0]);  //so the index is not out of range for a vector.
    return data_[i];
}
    
double tensor::at(size_t i, size_t j) const 
{
    //assert(get_dim() == 2);
    assert((i < shape_[0]) && (j < shape_[1]));   //so the index is not out of range for a matrix.
    return data_[i*shape_[1]+j];
}

size_t *tensor::get_shape_array() 
{
    return shape_.empty()? nullptr: &shape_[0];  //if shape is empty i.e. for a scalar, give a null pointer at shape[0]
}

double *tensor::get_data_array() 
{
    return &data_[0];     //gets to the starting point of the data array.????? 
}

int tensor::get_dim() const  //added to remove unrefernce error
{
    return shape_.size();
}