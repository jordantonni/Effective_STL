/*
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
#include <algorithm>

namespace item45
{
    using namespace std;

    struct widget
    {
        int x;

        widget(const int v)
            : x { v }
        {}
    };

    bool operator<(const widget& lhs, const widget& rhs)
    {
        cout << "OP<" << endl;
        return lhs.x < rhs.x;
    }

    void test()
    {
        vector<int> v { 10,9,8,7,4,4,4,6,5,3,2,1 };

        for (const auto x : v)
            cout << x << " ";
        cout << endl;

        sort(begin(v), end(v));

        for (const auto x : v)
            cout << x << " ";
        cout << endl;


        auto it = upper_bound(begin(v), end(v), 4);
        cout << *it << endl;

        for (const auto x : v)
            cout << x << " ";
        cout << endl;


        vector<widget> vw { 1,2,5,3,2,43 };
        sort(begin(vw), end(vw));
    }
}
