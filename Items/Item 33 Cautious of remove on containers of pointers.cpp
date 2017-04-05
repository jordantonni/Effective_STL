/*
 * Remove-like algorithims on containers of pointers
 *
 * Destroying a pointer element in a container does NOT delete what the pointer points to
 * 
 * remove and remove_if:
 *  - Overwrites elements to remove by assignment
 *  - If the container contains pointers they will be overwritten leaving no way to free what they pointed to
 *
 * Solution:
 *  - Go though each pointer element and delete the pointed to object first
 *  - Then use erase remove idiom
 *  
 *  - Better to use smart pointers. Due to RAII this isn't a problem then
 *  
 * Summary:
 *  - remove algorithims overwrite elements in the container, if the elements are pointers the memory will never be able to get free'd
 *  - Ensure pointer elements are deleted before you use remove on any container of pointers
 *  - Using smart pointers make this all irrelevant and easier to just use remove erase directly with it
 */

#include <algorithm>
#include <vector>

namespace item33
{
    using namespace std;

    struct widget
    {
        bool bad()
        {
            return true;
        }
    };

    void test()
    {
        vector<widget*> vec;
        vec.push_back(new widget);
        vec.push_back(new widget);
        vec.push_back(new widget);
        vec.push_back(new widget);

       


    }
}
