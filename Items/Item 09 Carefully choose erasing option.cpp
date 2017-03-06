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

    void test()
    {
        vector<int> vector1 { 1,2,3,4,5 };
        print(vector1);




    }
}
