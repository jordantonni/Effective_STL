/*
 * Never do in-place key modification in a set or multiset
 * 
 * All associative containers keep their elements in some sorted order, defined by the comparison function given (Default is less<T>)
 *  - If you modify the key of an associative contianer, you must ensure you dont change its sorted order, as the DS will not enforce it!
 *
 * In a set<T>:
 *  - The field of T you use to determine your sort order is the key
 *  - The rest of the data within the T object is just "along for the ride"
 *  - This is why the key of a set isnt const, unlike in Map<T, U>, as we need to be able to change the other fields of the T objects in a set!
 *  
 * Keys in:
 *  - Map/ Multimap : const
 *  - Set/ Multiset : non-const (Although the iterator returned to them usually puts them const, so for most purposes the elements are!)
 *  
 * Correct way to change elements in set, multiset, map, multimap:
 *  1) Locate element to change
 *  2) Copy the element, dont make it const, as we need to change it
 *  3) Modify copy
 *  4) Remove original object
 *  5) Insert modified copy, can provide hint to the old position in the insert call if it will be close to the original value
 *
 * Summary:
 *  - Never modify associative containers keys
 */


#include <set>
#include <iostream>

using namespace std;

namespace item22
{
    struct widget
    {
        int id;
    };

    struct widget_comparator
    {
        bool operator()(const widget& lhs, const widget& rhs) const
        {
            return lhs.id < rhs.id;
        }
    };

    void test()
    {

        set<widget, widget_comparator> widget_set;
        widget_set.emplace(widget { 1337 });
        widget_set.emplace(widget { 999 });
        widget_set.emplace(widget { 25 });


        auto it = widget_set.find(widget { 999 });

        if (it != end(widget_set))
        {
            const_cast<int&>(it->id) = 1000; // Have to cast away the const of the key. Ensure you DONT modify key in way that invalidates the sorted order.
        }

        for (const widget& w : widget_set)
        {
            cout << w.id << "\n";
        }
    }
}
