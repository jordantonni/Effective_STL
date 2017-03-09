/*
 * Reserve method to avoid unnecessary reallocations
 * 
 * STL containers automatically grow to accomodate new elements:
 *  - Up to their maximum size, given by their STLContainer<TYPE>::max_size non-static member
 *  
 * Vector and String:
 *  - Growth is done by basically called a realloc operation that:
 *      1) Allocate new memory that is some multiple of current capicity (Table Doubling)
 *      2) Copy all elements into new memory
 *      3) Destroy old elements via their dtors
 *      4) Deallocate old memory via delete
 *      
 *  The above require a lot of allocation, deallocation, copying and destruction -> Expensive
 *  Also all iterators, pointers and references into the string or vector become invalidated. -> Expensive
 *
 * Functions:
 *  - Size()        : How many elements in contianer
 *  - Capicity()    : How many elements could fit without allocating new memory
 *  - Resize(int n) : If n>size(), make their be n elements in vector, default init, else shrink to size n
 *  - Reserve(int n): Make enough memory for n objects to be alloacted into the vector or string
 *  
 * TLDR:
 *  - Inserting an element into the container when it will go above its capacity will result in allocations, deallocation, copies and invalidations
 *  - This is all very expensive
 *  - THEREFORE: Reserve to increase the capcaity to stop this by either
 *      1) Reserving to the size you know you need
 *      2) Reserving to a massive size then using the swap trick to trim down  (item 17)
 *
 * 
 * Note:
 *  - push_back, emplace_back don't invalidate pointers, references or iterators apart from the end(T) iterator!
 * 
 *
 * Summary:
 *  - Use reserve to increase the capacity of the vector or string to avoid reallocations
 *      - Trim it back down to size again if needed via the swap trick (item 17)
 */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

namespace item14
{
    template <typename T>
    void print(const T& c)
    {
        for (const auto& e : c)
            cout << e << " ";
        cout << endl;
    }

    void test()
    {
        vector<int> v { 1,2,3,4,5,6,7,8,9,10 };
        print(v);
        cout << v.size() << endl;
        v.resize(25);
        print(v);
        cout << v.size() << endl;

        v.resize(5);
        print(v);

        vector<int> v2;
        v2.reserve(100);
        for (int i = 0; i < 50; ++i)
        {
            v2.emplace_back((i + 100) / 2*i+1);
        }
        print(v2);
        cout << v2.capacity()<< endl;

        vector<int>(begin(v2), end(v2)).swap(v2);
        cout << v2.capacity() << endl;

    }
}
