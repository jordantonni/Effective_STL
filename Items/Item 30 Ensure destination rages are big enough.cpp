/*
 * Ensure the destination range is big enough (or the iterator writing to the destination is capable of adding new elements to it)
 *
 * STL containers automatically expand themselves and resize as new objects are added via push_back, push_font, insert, emplace, emplace_back etc
 *  - Algorithim destination range is used by ASSIGNING results to the elements. It doesnt create more, it assigns.
 *  - Must have object there already
 *
 * transform (iterator sourceBegin, iterator sourceEnd, iterator destBegin, transformFunction)
 *  - Applied the transformFunction to each element in the source range, and writes the returned result from transformFunction to the destination
 *    starting at the destBegin iterator.
 *    
 * Insert Iterators:
 *  - Output iterators that invoke the containers insert method to add a new object to the container
 *  - These are capable of adding new objects to the container and then assigning the value to them
 *  
 * Back_inserter / front_inserter / inserter:
 *  - Convenience functions that create and return insert iterators for the container
 *  - Basically end up calling push_back etc on the container for each object we write to the iterator returned from these functions
 *  
 *  
 *
 * Summary:
 *  - Destination ranges in algorithims assign to each element, they don't create new ones
 *      - To increase the size of the destination container as you go, use an insert iterator (i.e. ostream_iterator or back_inserter() )
 *      - Don't need an insert iterator to overwrite another container though, just ensure dest size is large enough!
 */


#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

namespace item30
{
    int transmorgify(const int val)
    {
        return val + 1;
    }

    void test()
    {
        vector<int> src { 1,2,3,4,5,6,7,8,9,10 };
        vector<int> dest;

        // back_inserter constructs a back_insert_iterator for the vector<int> dest container
        // back_insert_iterator invokes vector<int>::push_back() member function on dest to add the return value from transmorgify 
        transform(begin(src), end(src), back_inserter(dest), transmorgify);

        // back_inserter() just infers the type of the container and returns the below insert iterator easier
        transform(rbegin(src), rend(src), back_insert_iterator<vector<int>>(dest), transmorgify);

        // Dont need to use an insert iterator below, as the destination range already has values, we are just going to overwrite them
        vector<int> dest2(10, 1337);
        transform(begin(src), end(src), begin(dest2), transmorgify);
    }
}
