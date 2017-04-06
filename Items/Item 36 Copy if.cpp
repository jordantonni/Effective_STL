/*
 * Copy_if
 * 
 * Used to not be included in c++, since c++17 it now is 
 * 
 *
 *
 *
 * Summary:
 *  -
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <functional>

namespace item36
{
    using namespace std;

    void test()
    {
        vector<int> vec { 1,2,3,4,5,5,6,7,3,2,1 };

        auto even = [](const auto e) -> bool
                {
                    return !(e % 2);
                };

        vector<int> evens;
        evens.reserve(vec.size());
        copy_if(begin(vec), end(vec), back_inserter(evens), even);  // Only copy even values to vector, using stored lambda above

        cout << "Size of evens [" << evens.size() << "] capacity[" << evens.capacity() << "]\n";

        for (const auto e : vec)
            cout << e << " ";
        cout << endl;

        vector<int>(begin(evens), end(evens)).swap(evens);  // Copy and swap idiom to reduce capacity 

        for (const auto e : evens)
            cout << e << " ";
        cout << endl;

        cout << "Size of evens [" << evens.size() << "] capacity[" << evens.capacity() << "]\n";

        cout << endl;

        // Copies the even numbers into std output stream by writing them to an output iterator that is initialized with the std output stream (cout) as its stream
        copy_if(begin(vec), end(vec), ostream_iterator<int>(cout, ", "), even);
    }
}
