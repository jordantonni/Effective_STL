/*
 * ptr_fun, mem_fun, mem_fun_ref
 * 
 * Three ways to call a function, f, on an object, x:
 *  (1) f(x);       Pass x to function f
 *  (2) x.f();      Invoke method f on object x
 *  (3) p->f();     Invoke method f on the object x pointed to by pointer p
 *  
 * In order to invoke a function passed to an STL algorithim, the correct syntax for function invocation would need to be used:
 *  - Within the STL all functors and functions are invoked via syntax (1), i.e. f(x);
 *  - So to invoke a member function (method) either directly or though a pointer, syntax 2 or 3 needs to be used
 *  - The mem_fun and mem_fun_ref wrappers take care of this 
 * 
 * ptr_fun      : Wraps functions to provide typedefs required by function adapters
 * mem_fun_ref  : Takes a member funcion and returns a mem_fun_ref_t wrapper 
 *                Converts Syntax(2) -> Syntax(1)
 * mem_fun      : Takes a pointer to a member function (method) returns a mem_fun_t wrapper that allows it to be invoked via f(x) syntaxA
 *                Converts Syntax(3) -> Syntax(1)
 *
 * Function Object Adapters:
 *  - Allow function invocation syntax (1) i.e. f(x) to be used to invoke on the methods this objects wraps
 *  - Also provide typedefs required by function adpaters, just like ptr_fun does
 *  - mem_fun_t
 *  - mem_fun_ref_t
 *  
 *
 * Summary:
 *  - mem_fun and mem_fun_ref do two things:
 *      - 1) Wraps the member functions into a function objectd adapter so they can be invoked using f(x) type syntax
 *      - 2) Provides typedefs required by adapter functions such as not1, not2 etc
 *      
 *  - ptr_fun does one thing:
 *      - 1) Provides typedefs required by adapter functions such as not1, not2 etc
 */


#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <iterator>
#include <deque>

namespace item41
{
    using namespace std;

    struct Widget
    {
        bool isGood() const
        {
            return true;
        }

        operator char() const
        {
            return 'Y';
        }
    };

    bool isGoodWidget(const Widget& w)
    {
        return true;
    }

    void test()
    {
        vector<Widget> vec { 5 };

        // Standalone function, passed a function pointer, doesnt need any adapter as invoaction syntax f(x) works
        copy_if(begin(vec), end(vec), ostream_iterator<char>(cout, " "), isGoodWidget);
        cout << endl;

        // Member function, passing the address of it as a function pointer, requires mem_fun_ref adapter to change x.f() into f(x);
        copy_if(begin(vec), end(vec), ostream_iterator<char>(cout, " "), mem_fun_ref(&Widget::isGood));
        cout << endl;

        int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
        deque<int> d;

        transform(begin(arr), end(arr), back_inserter(d), bind2nd(plus<int>(), 41));

        copy(begin(d), end(d), ostream_iterator<int>(cout, " "));
    }
}
