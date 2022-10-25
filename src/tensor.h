#ifndef TENSOR_H
#define TENSOR_H

#include <vector>
#include <string>
#include <map>
#include <iostream>

class tensor {

private:
    std::vector<size_t> shape_;
    std::vector<double> data_;
    int dim_; //added myself to remove unreference error

public:
    tensor(); // scalar 0

    explicit tensor(double v); // scalar v

    tensor(int dim, size_t shape[], double data[]); // from C

    int get_dim() const; //for getting the dimension of the tensor
    
    // scalar only
    double item() const; //for getting a read-only scalar

    double &item(); //for read and write enabled scalar

    double at(size_t i) const;
    
    double at(size_t i, size_t j) const;

    size_t *get_shape_array();
    
    double *get_data_array();


}; //class tensor
#endif //end TENSOR_H