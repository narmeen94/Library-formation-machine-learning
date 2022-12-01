
#include <iostream>
class base 
{
    public:
    
    base(bool th) 
    {
        std::cout << "ctor of base" << std::endl;

        if (th) 
        {
            throw std::runtime_error("throw from ctor of base");
        }
    }
    
    ~base() 
    {
        std::cout << "dtor of base" << std::endl;
    }
};

class member 
{
    public:
    member(bool th) 
    {
        std::cout << "ctor of member" << std::endl;

        if (th) 
        {
            throw std::runtime_error("throw from ctor of member");
        }
    }
    ~member() 
    {
        std::cout << "dtor of member" << std::endl;
    }
};

class derived : public base 
{
    member m_;
    public:

    derived(bool base_th, bool member_th): base(base_th), m_(member_th) 
    {
        std::cout << "ctor of derived" << std::endl;
    }
    
    ~derived() 
    {
        std::cout << "dtor of derived" << std::endl;
    }
};

void test_1() 
{
    try 
    {
        derived d(false, false);
    }
    
    catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }
}
int main(){

    test_1();
}

