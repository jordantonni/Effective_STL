/*
 * Base() method of reverse_iterarors
 *
 *
 * Base() member method of a reverse iterator class returns an iterator:
 *  - The iterator returned points to one element after the reverse_iterator!
 *
 * Note:
 *  C and C++ dictate that a pointer returned from a function is not modified:
 *      - i.e. if foo() returns a pointer, i.e. char* foo() { }
 *      - This is illegal: ++foo(); as it attempts to modify the returned pointer
 *      
 *      BUT:
 *          - You can assign the pointer returned from a function and modify it just fine.
 *          - i.e. char* cPtr = foo(); ++cPtr; Works just fine!
 *          
 *          
 * Insertion:
 *  - When you insert, you want to insert just before the elements position that you have an iterator to
 *  - Thinking from the perspective of a reverse_iterator, this means to the right, so inserting to a base() of that will be the correct location
 *  - If you want to insert to the left of the element, you will need to do: v.insert((++ri).base());
 *  
 * Erasure:
 *  - Erasing an element pointed to by a reverse_iteraor requires using base(), but this will point one to the right
 *      - So we need to do: v.erase((++ri).base)); to first move the rev_it to the left, then get the base of that, then erase


 * Summary:
 *  - Base() returns an iterator from a reverse_iterator
 *      - But it always points one element to the right of where the reverse_iterator did, remember this so you can insert/erase the correct element you want
 *      - use (++ri).base(); to first move the reverse_iterator to the left by one, then get base(), if you want to not get one element to the right!
 */


#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>

using namespace std;

namespace item28
{

    char* foo()
    {
        static char* sentence = "Jordan\0";
        return sentence;
    }
    void test()
    {
        vector<int> vec { 1,2,3,4,5,6,7,8,9,10 };
        vector<int>::reverse_iterator rev_it = find(rbegin(vec), rend(vec), 5); // Find the first 5, searching from right to left! (Last 5 really)

        vector<int>::iterator it { rev_it.base() }; // Get a normal iterator, this points to element 6 really!

        cout << *rev_it << endl;

        cout << *it << endl;

    }
}
