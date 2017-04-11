/*
 * Make predicates and predicate classes pure functions
 * 
 * Predicate        : Function that returns a bool
 * Pure Function    : Return value depends only on its parameters. Can only change if they do.
 * Predicate Class  : Functor class whose operator() is a predicate function
 * 
 * Anywhere a real predicate can be used, so too can a predicate class (functor)
 *  - and vice versa ( Can wrap a predicate function with ptr_fun() to pass to something expecting a functor)
 * 
 * Predicates passed to STL algorithims will be copied, and they may be stored and used later:
 *  - Having them be pure functions ensures the result is not time dependent. IMPORTANT
 *  
 *
 * Summary:
 *  - Predicate classes and functions are copied when passed to algorithims
 *  - They may not be invoked until later
 *  - Ensure your predicates are pure functions so they always return the correct result
 *      - Make them const
 *      - Don't access Mutable data, static data
 */

#include <functional>

namespace item39
{
    using namespace std;

    // Bad
    struct unpureFunctor
    {
        int count { 0 };

        bool operator()()
        {
            return 3 == ++count;
        }
    };

    // Good
    struct pureFunctor
    {
        bool operator()(int x) const
        {
            return 0 == x % 2;
        }
    };

    void test()
    { }
}
