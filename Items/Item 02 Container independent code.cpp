/*
 * Container independent code is not realistic
 *
 * STL and generalisation:
 *  - Arrays    -> Containers, parameterized on element type
 *  - Functions -> algorithims, parameterized on iterator type
 *  - Pointers  -> Iterators, parameterized on element in container type
 *  
 * Can't write good, efficient, correct code that is generic to work on all container types, or even some container types:
 *  - Why?
 *      - Not designed to be interchangable
 *      - End up writing weak code that doesnt take advantage of the specific strengths each conainter can offer on their own
 * 
 * How to make changing containers easier:
 *  - Typedefs for the container of objects, allows you to add allocaters and change itertors easier
 *  - Encapsulate containers in classes:
 *      - Offer access via methods
 *      - You the only need to change the methods in the class and not everywhere in the code base
 *
 *
 * Summary:
 *  -
 */

namespace item02
{
    
}