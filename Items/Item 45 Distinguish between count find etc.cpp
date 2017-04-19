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
 *  equal_range     : Returns pair of iterator
 *
 *
 *
 *
 *
 * {1,2,3,4,4,5,6}
 * 
 * lower_bound: 4 - return iterator to first matching element, 4
 * upper_bound: 4 - return iterator to first element past range, 5
 * 
 * {1,2,3,5,6}
 * 
 * lower_bound: 4 - return iterator to first element equlivant or greater than - 5  - i.e. where the element should be inserted if doesnt exist
 * upper_bound: 4 - return iterator to first element greater than value - 5
 * 
 * equal_range: return pair<iterator,iterator> that demarcate the lower_bound and upper_bound   - Should be called equlivant range!
 *
 *
 * Summary:
 *  -
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
        cout << std::boolalpha;
        vector<int> vector { 8,3,5,5,5,2,0,9 };

        //Unsorted  ------------------------------

        //Using count to check if value is present
        if(count(begin(vector), end(vector), 5))
            cout << "Found" << endl;

        //Using find to check if value is present
        if(find(begin(vector), end(vector), 5) != end(vector))
            cout << "Found" << endl;

        //Sorted    ------------------------------
        sort(begin(vector), end(vector));

        //Using binary_search to check if value is present
        if(binary_search(begin(vector), end(vector), 5))
            cout << "Found" << endl;






    }
}
