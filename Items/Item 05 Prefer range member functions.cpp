/*
 * Use range based member functions instead of functions that take a single element
 * 
 * i.e. Use member functions that take two iterators specifying a range instead of a function that only takes a single element
 * 
 * 
 * Assign member function:
 *  - Availble for Vector, String, Deque, List (Sequence Containers)
 *  - Lets you assign elements from one container within a range to another container
 * 
 * Calls to copy where the destination range is an insert iterator (inserter)
 *  - Replace that with a call to a range member function, it is more efficient
 *  
 * Range Based functions:
 *  - Range Construction: All containers offer it
 *  - Range Insertion: All containers offer it
 *  - Range Erasure: All containers offer it
 *  - Range Assignment: All contaiers offer it
 *
 * Summary:
 *  - Range member functions mean you dont have to write loops that use the single element functions. More readable and more efficient!
 *  - Range member functions shift elements to their final position in one go, loops with single element functions will shoft by one each time. BAD
 *  - Range member functions can increase the capacity of the container just once to the required size
 *      - Loops with single element functions will have to grow as needed, which will be > once!
 *  - Range member functions can set the pointers in a node based structure only once and be correct
 *      - Single element functions have to update each time, so repeated inserts etc will cause prev and next pointers to have shortlived updates
 *  - Dont use repeated calls to a single element insertions, prefer to use range based functions!
 */

#include <vector>
#include <iostream>
#include <string>

namespace item05
{
    using namespace std;

    template <typename T>
    void print(const string& str, const T& v)
    {
        cout << str.c_str() << ": ";
        for (auto e : v)
            cout << e << "\t";
        cout << "\n";
    }

    void test()
    {
        vector<int> vec;
        vector<int> src(5, 1337);
        src.emplace(src.begin(), 1);
        vec.reserve(src.size());

        print("vec", vec);
        print("src", src);

        // Assigns into vec, the values within the range demarcated by the two find calls within vector src
        vec.assign(
            find(src.begin(), src.end(), 1337),
            find(src.rbegin(), src.rend(), 1337).base());

        print("vec", vec);
        print("srs", src);
    }
}
