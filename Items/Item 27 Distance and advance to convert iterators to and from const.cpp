/*
 * Converting a const_iterator to an iterator via advance and distance
 * 
 * No implicit conversion from const_iterator to iterator
 *  - Need to convert const_iterators quite often to pass to algorithims and methods
 * 
 * Distance:
 *  - takes two iterators and returns the difference between them
 *  
 * Advance:
 *  - Takes and iterator and a distance and moves the iterator up to the position
 *
 * NOTE:
 *  - The type for the templated function distance is the same for both params, therfore you cant pass both an iterator and a const_iterator!
 *      - Solution: Explicity set the template parameter to be that of the const_iterator type, so that is used for the plain iterator also
 *      - Remember, an implicit conversion exists for that direction, just not the const to non-const!
 *
 * Summary:
 *  - Convert via using advance(iterator, distance(iteraor, const_itr) )
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
