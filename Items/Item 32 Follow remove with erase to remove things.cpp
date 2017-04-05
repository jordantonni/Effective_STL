/*
 * Erase-Remove to really remove elements
 * 
 * All algorithims work on a range defined by iterators.
 * Hence, No algorithim knows anything about the underlying container on which it works on
 * The only way to really remove an elements from a container (erase it) is by calling the containers member functions
 * So remove, being an algorithim, cannot really remove an element.
 * 
 * What does remove do?
 *  - It shifts down all the unremoved elements.
 *  - Returns an iterator pointing to the new end (where the elements not to be removed ends)
 *      - There may or may not be the removed elements after this
 *      
 *  - Internally, remove walks down the elements in range and overwrites via assignment elements to be removed with the next element that is not to be removed
 *      - Must ensure you free your pointers before calling this. As this would results in the pointer being overwritten and no way to free the memory it pointed to!
 *  
 * 
 * TLDR: remove returns an iterator to the logical end of the container where the elements to really remove are
 *       pass that iterator to erase along with container.end() to really remove them
 *
 *
 *
 * Summary:
 *  - Remove doesnt really remove stuff, just moves it to the end
 *  - Erase remove idiom will really remove for you
 */

#include <vector>
#include <list>
#include <algorithm>

namespace item32
{
    using namespace std;


    void test()
    {
        vector<int> items { 1,6,3,4,5,6,6,7,7,6,8 };
        items.erase(remove(begin(items), end(items), 6), end(items));
    }
}
