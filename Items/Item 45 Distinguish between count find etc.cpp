/*
 * count, find, binary_search, lower_bound, upper_bound, equal_range
 * What each does and when to use them:
 * 
 * Unsorted Ranges: (Linear Time) (Equality)
 * 
 *  count    : Returns how many elements have that value, can convert to bool to test for existance, slower than find if successful as it doesnt stop when found
 *  
 *  find     : Returns iterator to first element with value, if not found returns end()
 *  
 *  
 * Sorted Ranges: (Logaritmic time) (Equivalence)
 *  
 *  binary_search   : Returns true if value present, false otherwise
 *  
 *  lower_bound     : Returns iterator to first element with value, or if not iterator to where it should be inserted
 *                    Need to test return value against value searched for, but by using equivalence! 
 *                    
 *  upper_bound     : Returns iterator to one past the last element with value, or if not where it should be inserted
 *                    Useful to insert elements into an already sorted range at correct location
 *                    
 *  equal_range     : Returns pair of iterators. If both the same, no values found, Distance between first and last == count
 *                    First = what lower_bound would return, first element with value or where it should be
 *                    Last = what upper_bound would return, one past the last element with value or where it should be
 *                    TLDR: Returns range of values that are all Equilivant to value you searched for
 *                          To test for if the value is there and without having to jump around equivalence hoops like in lower_bound
 *                          We just compare to see if returnd.first != returned.second, if so returned.first is the value! This uses equivalence by default.
                        
 *                    
 * Associative Containers:
 * 
 *  For standard sequence containers, vector, list, string, deque, use above advice.
 *  Use member functions of same name for set, map, multiset, multimap
 *  
 *  set/map::count          : Test for existence of value in container
 *  
 *  multiset/multimap::find : Faster than count as a multimap or multiset can have multiple of the same values, so this will stop after first one is found
 *              
 *
 * Examples:
 * {1,2,3,4,4,5,6}
 * lower_bound: 4 - return iterator to first matching element, 4
 * upper_bound: 4 - return iterator to first element past range, 5
 * 
 * {1,2,3,5,6}
 * lower_bound: 4 - return iterator to first element equlivant or greater than - 5  - i.e. where the element should be inserted if doesnt exist
 * upper_bound: 4 - return iterator to first element greater than value - 5
 * 
 *
 * Summary:
 *  - Count and find good for unsorted range
 *  - binary_search good for sorted range to see if something exists
 *  - equal_range good to get first element with value
 *  - lower_bound good to get first value with element not preceding value
 *  - upper_bound good to get first value with element succeeding the value
 *  - Use member functions on associative containers such as sets and maps / multisets and multimaps
 */


#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <iterator>
#include <functional>

namespace item45
{
    using namespace std;

    void test()
    {
        //        cout << std::boolalpha;
        vector<int> vector { 8,3,5,5,5,2,0,9 };

        //Unsorted  ------------------------------
        copy(begin(vector), end(vector), ostream_iterator<int>(cout, " , "));
        cout << endl;

        //Using count to check if value is present
        if (count(begin(vector), end(vector), 5))
            cout << "Found" << endl;

        //Using find to check if value is present
        if (find(begin(vector), end(vector), 5) != end(vector))
            cout << "Found" << endl;

        //Sorted    ------------------------------
        sort(begin(vector), end(vector));
        copy(begin(vector), end(vector), ostream_iterator<int>(cout, " , "));
        cout << endl;

        //Using binary_search to check if value is present
        if (binary_search(begin(vector), end(vector), 5))
            cout << "Found" << endl;

        //Using lower bound to get location of value
        //NOTE: Using an equivalence test in the if to test if the value found by lower_bound is equivalent to the value we searched for
        auto lb = lower_bound(begin(vector), end(vector), 5);
        if (lb != end(vector) && (!(*lb < 5) && !(5 < *lb)))
            cout << "Found element with value " << *lb << " at location " << lb - begin(vector) << endl;

        //Using upper_bound to get element ONE PAST the last location of equivalent value in range
        auto up = upper_bound(begin(vector), end(vector), 5);
        if (up != end(vector))
            cout << "Found one past last element with value 5 at location " << up - begin(vector) << endl;

        //Using equal_range to get location of first element that is equivilant -- BEST WAY TO DO THIS
        auto eq = equal_range(begin(vector), end(vector), 5);
        if (eq.first != eq.second)
            cout << "Found first element with value of " << *eq.first << " at location " << eq.first - begin(vector) << endl;
        cout << "Number of elements with value of 5 is " << distance(eq.first, eq.second) << endl;
    }
}
