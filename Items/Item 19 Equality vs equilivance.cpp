/*
 * The difference between equality and equivalence
 * 
 * Equality:
 *  - Based on operator==
 *  - Tests to see if the values of two objects are the same
 *  - Used by find algorithim
 *  
 * Equivalence:
 *  - Based on operator<
 *  - Tests two objects within a sorted range, to see if neither of them come before the other
 *  - i.e. Equivalent with respect to an ordering criteria
 *  - Used by insert to check of item is already in associated data structure
 *  
 * Associate Containers:
 *  - key_comp member function returns functor that is the sorting predicate used by that container
 *  - So equivalence would be defined as:
 *      - !c.key_comp()(x,y) && !c.key_comp()(y,x)
 *  
 *  
 * Why do associative containers use equivalence and not equality?:
 *  - All associative containers store their values in order
 *  - To do this they must have a compairson function that they use to compare elements
 *  - They use this same sorting criteria comparison function to test for equivalence also
 *  - If they didn't, they would also need to be provied with an equality function
 *      - Then it would be sorted by equivalence but tested for equality with another function
 *      - Could end up in situation where two items arent added as they are equivalent but search doesnt work as the equivalent item isnt equal
 *
 *
 * Summary:
 *  - Use member functions such as set::find instead of free functions such as std::find
 *      - As set::find will use the equivalence function to test for EQUIVALNCE, not the equality function that std::find will use
 */

#include <vector>
#include <string>
#include <iostream>
#include <set>

using namespace std;

namespace item19
{
    struct widget
    {
        int id;
    };

    struct widget_comparator    // Functor class used for the equivalence comparison function
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
        widget_set.emplace(widget { 1 });
        widget_set.emplace(widget { 25 });

        for (const widget& w : widget_set)
        {
            cout << w.id << "\n";
        }

    }
}
