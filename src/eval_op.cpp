
#include "eval_op.h"
#include <assert.h>

eval_op::~eval_op() 
{

}

void eval_op::eval(vars_type &variables, const kwargs_type &kwargs) 
{
    assert(false); // should be provided by derived classes
}