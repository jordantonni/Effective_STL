/*
 * Make functor classes adaptable
 * 
 * not1, not2       - Function adapters that wrap and return the negation of a function that takes 1 (not1) or 2(not2) parameters
 * bind1st, bind2nd - Function adapters
 * 
 * ptr_fun      - Depreciated, use std::function instead
 *              - Wraps a function and returns a functor object that has typedefs defined that are required by functions such as not1, not2
 *              - TLDR: Turns a function into an adaptable function object
 *
 *
 * Adaptable Function Objects:
 *  - Functors that define the typedefs required by function adapters such as not1, not2, bind1st, bind2nd etc
 *  - Inherit from base structs, these provide the typedefs requried by function adapters:
 *      - std::unary_function<Param, Return>            
 *      - std::binary_function<Param1, Param2, Return>
 *  
 *  
 * Note: Functor classes with no state are usually defined as structs.
 *       Functor classes with state / private data, define as class.
 *       
 *  
 *
 * Summary:
 *  - Function adapters, such as not1, not2, can wrap functions such as negate them
 *  - In order for a function to be passed to a function adapter, it must be an adaptable function
 *  - Make a function adaptable via:
 *      - For Functors: Inheriting from one of the correct base classes
 *      - For Functions: Wrapping it with ptr_fun
 */

#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

namespace item40
{
    using namespace std;

    struct myFunctor : public unary_function<const int, bool>
    {
        bool operator()(const int x) const
        {
            return (0 == x % 2);
        }
    };

    bool isEven(const int x)
    {
        return (0 == x % 2);
    }

    void test()
    {
        vector<int> vec { 1,2,3,4,5,6 };

        // Copies odd numbers by wrapping the isEven function by ptr_fun to provide typedefs, then adapting the function using not1 function adpater
        copy_if(begin(vec), end(vec), ostream_iterator<int>(cout, " "), not1(ptr_fun(isEven)));

        cout << endl;

        // Same as above but uses the functor object, we inherit from unary_function to provide the typedefs required by not1 function adapter
        copy_if(begin(vec), end(vec), ostream_iterator<int>(cout, " "), not1(myFunctor()));

    }
}
