#include <iostream>

#include "lib/vectorina.h"

class wrap_object
{
public:
    int32_t elem;
    
    void hello()
    {
        std::cout << "Test run" << std::endl;
    }
};

/* out of range */
void test1()
{
    try
    {
        vectorina_base<int> check_vector{1, 2, 3};
        check_vector[14] = 1;
    }
    catch (vectorina_out_of_range &exception)
    {
        std::cout << exception.what() << std::endl;
    }
}

/* wrong dimension */
void test2()
{
    try
    {
        vectorina_base<int> check_vector{1, 2, 3};
        
        vectorina_base<int> wrong(2);
        wrong = check_vector;
    }
    catch (vectorina_wrong_dimension &exception)
    {
        std::cout << exception.what() << std::endl;
    }
}

/* common catch */
void test3()
{
    try
    {
        vectorina_base<int> check_vector{1, 2, 3};
        /* error */
        check_vector[14] = 1;
    }
    catch (vectorina_wrong_dimension &exception)
    {
        /* no */
        std::cout << "wrong catch!" << std::endl;
    }
    catch (vectorina_exception &exception)
    {
        std::cout << exception.what() << std::endl;
    }
    catch (...)
    {
        /* no */
        std::cout << "wrong catch!" << std::endl;
    }
}

int main()
{
    test1();
    
    test2();
    
    test3();
    
    /*
    const vectorina_base<int> tester{1, 2, 3};
    
    vectorina_base<int> test1(3);
    
    test1[0] = 1;
    test1[1] = 1;
    test1[2] = 1;
    
    std::cout << (tester + test1) << std::endl;
    std::cout << (tester * 4) << std::endl;
    std::cout << (tester - test1) << std::endl;
    
    auto iter = test1.begin();
    std::cout << *iter << std::endl;
    
    auto iter2 = tester.begin();
    
    */
    return 0;
}