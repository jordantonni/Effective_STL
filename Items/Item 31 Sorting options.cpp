/*
 * What sorting algorithim to use
 * 
 * 
 * Random Access iterators (Vector, Array, String, Deques):
 * 
 *     sort             - Uses Intro sort (Quicksort that can use Heapsort if small) O(n lg n)
 *                      - Sorts entire container
 *                      - Default comparison predicate is less<T> ( < )
 *     
 *     stable_sort      - Stable version of sort
 *                  
 *     partial_sort     - Sorts the first n items in order
 *                      - Leaves the rest unsorted
 *                      - Equilivance
 *                      - Not Stable
 *                      
 *     nth_element      - Sorts the top n items (but the items in that sorted range are not sorted)
 *                      - Leaves the rest unsorted
 *                      - Can easily find median value by choosing container.size() / 2 as n
 *                      - Can easily get value at 75th precentile by choosing container.size() * 0.25 as n
 *                      - Equilivance
 *                      - Not Stable
 *
 * Bidirectional Iterators (Any Sequence container i.e. List)
 * 
 *     partition:       - Takes a predicate
 *                      - Returns an iterator to end of sorted range
 *                      - Sorts such that all items that satisfy predicate are sorted before the returned iterator
 * 
 * Efficiency (Most to least)
 *  (1) partition
 *  (2) stable_partition
 *  (3) nth_element
 *  (4) partial_sort
 *  (5) sort
 *  (6) stable_sort
 *
 * Summary:
 *  - Full sort use either sort or stable_sort or list::sort
 *  - Top n elements in order, partial_sort
 *  - Element at position n or top n elements in any order, nth_element
 *  - Split elements into 2 depending on criteria, partition
 *  
 */

#include <vector>
#include <algorithm>
#include <string>
#include <ostream>
#include <iostream>

namespace item31
{
    using namespace std;

    template <typename Container>
    void print(const Container& c)
    {
        for (const auto e : c)
        {
            cout << e << " ";
        }
        cout << "\n";
    }

    template <typename Container, typename Iter>
    void print(const Container& c, Iter& it)
    {
        typename Container::const_iterator i = begin(c);
        while (i != it)
        {
            cout << *i++ << " ";
        }
        cout << "\n";
    }

    void test()
    {
        vector<int> v { 3,6,2,4,7,9,45,23,89, 1 };
        print(v);

        //Full sort
        sort(begin(v), end(v));
        print(v);

        // Partial Sort - Sort highest 4 in order (1-4 are sorted also)
        partial_sort(begin(v), begin(v) + 4, end(v), [](const auto lhs, const auto rhs) -> auto
                     {
                         return lhs > rhs;
                     });
        print(v);

        sort(begin(v), end(v));
        print(v);

        //nth_element - Sort highest 4 (1-4 are not sorted)
        nth_element(begin(v), begin(v) + 4, end(v), [](const auto lhs, const auto rhs) -> auto
                    {
                        return rhs < lhs;
                    });
        print(v);

        sort(begin(v), end(v));
        print(v);


        // partition - Sort such that all elements satisfing the lamba predicate are before the rest
        auto evenDemarcate = partition(begin(v), end(v), [](const auto elem) -> auto
                                       {
                                           return !(elem % 2);
                                       });
        print(v, evenDemarcate);
        print(v);
    }
}
