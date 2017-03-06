/*
 * Make copying cheap and correct for elements of containers
 * 
 * Copying:
 *  - Elements inserted to a container, unless using emplace, are copied into it
 *  - Within a container, elements are shifted up and down via copying when items are added and removed or sorted
 *      -> So ensure classes that will be in containers have efficient copy assignment and copy ctors
 * 
 * Containers of pointers:
 *  - Avoids the expensive copies
 *  - Avoid object slicing when copying inherited classes
 *      -> Best to use Smart Pointers
 *
 * Summary:
 *  -
 */

namespace item03
{
    
}