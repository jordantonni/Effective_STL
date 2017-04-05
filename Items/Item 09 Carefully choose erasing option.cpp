/*
 * Erasing
 * 
 * Contiguous-Memory Containers:
 *  - Vector, Deque, String
 *  - erase-remove idiom O(n)
 *  - Remove_if to remove if items match a predicate
 *
 * List:
 *  - remove member function
 *  - remove_if to remove if items match a predicate
 *  
 * Associatve Containers:
 *  - erase member function O(lg n)
 *
 * Summary:
 *  - Erase all objects that have a specific value:
 *      - Vector, Deque, String: Erase-Remove
 *      - List: Remove member function
 *      - Associatve Container: erase member function
 *      
 *  - Erase all objects that match a predicate:
 *      - Vector, Deque, String: Erase-Remove_if
 *      - List: Remove_if member function
 *      - Associatve Contianer: Loop on iterator and test then erase. USE POSTINCRMENT on the iterator to ensure you dont invalidate it when you erase
 *      
 *  - Remove decorator, i.e. do something else, when you remove each item:
 *      - Sequence Container: Loop to decorate and also erase member function, use return value of erase to get iterator to next element, valid!
 *      - Associatve Container: Just decorate previous loop versions
 */


#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <list>

using namespace std;

namespace item09
{
    template <typename T>
    void print(const T& c)
    {
        for (const auto& e : c)
            cout << e << " ";
        cout << "\n";
    }

    bool odd(int val)
    {
        return (val % 2 != 0);
    }

    void test()
    {
        vector<int> vector1 { 1,2,5,3,5,4,5 };

        print(vector1);
        vector1.erase(remove(begin(vector1), end(vector1), 5), end(vector1)); // Erase-remove idiom
        print(vector1);

        set<int> mySet { 3,6,2,45,7,4,2,56,7 };
        print(mySet);


        // Remove_if for associatve
        // Note the postfix increment of it, means we erase the old iterator value that postinc returns, but the move on it to the new value
        // Note: erasure invalidates ALL iterators on a sequence container!, but in an associatve, it only invalidates the iterator the erased element
        for (set<int>::iterator it = begin(mySet); it != end(mySet);)
        {
            if (odd(*it))
                mySet.erase(it++);
            else
                ++it;
        }

        print(mySet);
    }
}
