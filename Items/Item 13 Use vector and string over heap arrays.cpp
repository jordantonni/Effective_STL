/*
 * Prefer vector and string over dynamically allocated arrays and arrays of char
 * 
 * If you use dynamic memory, i.e. new, then you take on the following responsibilities:
 *  1) You must call delete later
 *  2) Must use the correct form of delete, i.e. delete or delete[]
 *  3) Ensure delete is called only once
 *  
 * Why use vector and string instead of dynamically allocated arrays?
 *  - Manage their own memory
 *  - Resize themselves automatically
 *  - Work with STL algorithms
 *
 * Summary:
 *  - 99% of the time use a vector or string instead of a dynamically allocated array
 */

#include <string>
namespace item13
{
    void test()
    {
        
    }
}