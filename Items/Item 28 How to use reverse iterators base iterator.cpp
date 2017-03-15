/*
 *
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
 * Summary:
 *  -
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
        vector<int>::reverse_iterator rev_it = find(rbegin(vec), rend(vec), 5);

        vector<int>::iterator it { rev_it.base() };

        cout << *rev_it << endl;

        cout << *it << endl;

        char* charstar = foo();
        ++charstar;
        cout << *charstar << endl;
        ++charstar;
    }
}
