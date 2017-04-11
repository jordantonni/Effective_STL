/*
 * Functor classes are passed by value to STL algorithims
 * 
 * 
 * Passing a function as a parameter is done by passing a pointer to the function. i.e. &func
 * The pointer to the function is copied from the call site into the function parameter
 * 
 * STL Function objects are modelled after function pointers, so they too are copied (passed by value) when passed to a function.
 * 
 * As function objects / functors are passed by value and copied:
 *  1) Ensure they are not too expensive to copy
 *  2) They don't use virtual functions (i.e. belong to a class hierarcy using virtual functions) - Why? Slicing
 *  
 * To get around this restriction:
 *  - Use the PIMPL idiom (Bridge Pattern):
 *      - Have your functor class contain a smart pointer to an implementation class that can belong to a hierarchy and use virtual functions
 *      - Invoke the real virtual operator() function from the pimpl class operator()
 *      
 *
 * Summary:
 *  - Function objects are modelled after function pointers, hence: They are passed by value (copied) when passed to functions
 *  - Ensure your functors are designed with this copying in mind
 */

#include <vector>
#include <functional>
#include <iostream>
#include <algorithm>
#include <iterator>

namespace item38
{
    using namespace std;

    class doSomething
    {
    public:
        doSomething()
        {}

        doSomething(const doSomething& rhs)
        {
            cout << "COPIED\n";
        }

        void operator()(int x) const
        {
            cout << x << " ";
        }
    };

    void test()
    {
        vector<int> vec { 1,2,5,7,13,5,32 };

        // Explicitly binding the Function class of the algorithim to use a reference, this means coping doesnt take place
        // Do not do this, not all STL algorithims will compile like this
        for_each<vector<int>::iterator, doSomething&>(begin(vec), end(vec), doSomething());
        cout << endl;
    }
}
