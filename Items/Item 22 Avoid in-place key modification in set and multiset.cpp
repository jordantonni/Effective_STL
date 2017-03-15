/*
 * Never do in-place key modification in a set or multiset
 * 
 * 
 *
 *
 *
 * Summary:
 *  -
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
        cout << endl << endl;

        for (const widget& w : widget_set)
        {
            cout << w.id << "\n";
        }
    }
}
