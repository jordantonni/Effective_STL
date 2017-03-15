/*
 *
 *
 *
 *
 * Summary:
 *  -
 */

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

namespace item27
{
    void test()
    {
        vector<int> vec { 1,2,3,4,5,6 };
        vector<int>::const_iterator citr = vec.begin() + 4;

        for (const auto& i : vec)
            cout << i << " ";
        cout << endl;

        vector<int>::iterator i = begin(vec);
        advance(i, distance<vector<int>::const_iterator>(i, citr)); // Move iterator to const iterator position, getting a iter from a const_itr
        *i = 1337;

        for(const auto& i : vec)
            cout << i << " ";
        cout << endl;
    }
}
