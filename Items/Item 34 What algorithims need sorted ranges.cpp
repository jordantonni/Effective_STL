/*
 * What algorithims require sorted ranges to work on
 * 
 * 
 *  Not all algorithims can work on all ranges:
 *      - remove requires forward iterators and ability to make assignments via *iter
 *          - can't be used on map/multimap due to assigment not supported
 *          - can't be used on input iterators
 *      - Sorting algos mainly require random access iterators
 *          - can't be used on list
 *          
 *  Search algos use binary search, which only works when data is sorted to give logarithmic time
 *      - Only logarithimic if used on random access iterators, else it needs linear time to traverse
 *      
 * 
 *  Require Sorted Range: (And use equilivence)
 *      - Search                : binary_search, lower_bound, upper_bound, equal_range
 *      - Set                   : set_union, set_difference, set_intersection, set_symmetric_difference
 *      - Merge Sort (1 Pass)   : merge, implace_merge
 *      - includes (Checks if all elements of one container are in another)
 *      
 *      
 *  Don't require, but should always be used on sorted range:
 *      - unique, unique_copy   (unique will only remove duplicate values if they are beside each other, so need to be sorted to remove correctly!)
 *
 *
 * Summary:
 *  - Algorithims require sorted data so that they can offer the best performance guarantee
 *  - Ensure the comparison function the container uses is the same as the one passed to the algorithim
 */

#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>

namespace item34
{
    using namespace std;

    ostream& operator<<(ostream& ost, const vector<int>& v)
    {
        for (const int e : v)
            ost << e << " ";
        ost << "\n";
        return ost;
    }

    void test()
    {
        vector<int> vec { 43,76,12,8,34,897,234,56,23,78,34 };
        cout << vec;
        sort(begin(vec), end(vec), greater<int>());     // Sorts vector in descending order, default is less<T> i.e. ascending!
        cout << vec;

        bool found = binary_search(begin(vec), end(vec), 34);   // Wont find due to searching using less<T>, but data is sorted using greater<T>
        cout << std::boolalpha << found << endl;

        found = binary_search(begin(vec), end(vec), 34, greater<int>()); // Will find as we use the same comparison function for both the sorting and the algorithim
        cout << std::boolalpha << found << endl;
    }
}
