/*
 * Use empty() instead of checking size() == 0
 *
 * Empty() is O(1) operation:
 *  - Size is not always, in list it can be linear O(n)
 *  
 *  - Why is size() linear in list?
 *      - List spilcing, inserting elements from a range in List B into List A
 *      - Getting the size of this new List requires a traversal, something that size itself must do
 *      
 *      Why doesnt splice update size?
 *          - Splice is one of the best features of list, often a reason to choose list 
 *          - O(1) operation 
 *          - Would devolve into a linear O(n) operator if it had to update the size
 *  
 *
 * Summary:
 *  - Use empty() to check if a container has zero elements
 */

namespace item04
{
    

}
