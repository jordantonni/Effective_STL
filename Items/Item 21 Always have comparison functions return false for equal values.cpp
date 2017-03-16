/*
 * Always make comparison functions return false for two values that are equal
 *
 * Because equivalence is defined as:
 *  - !(e1 < e2) && !(e2 < e1)
 *  
 *  - It will only return true of both tests return false, i.e. both sub expressions evaluate that neither of the elements are less than each other
 *  - If we use less_equal ( <= ) as our comparison operator, then the sub expressions will return true for equal elements, and false for equivalence!
 *  
 * NOTE:
 *  - Negation of less than, !( e < e2 ) is NOT greater than ( > )
 *      - It is actually greater than or equal ( >= )
 *      
 *      - Therefore, trying to sort by ascending order, you do not just negate (e < e2)
 *          - You instead: Swap the order of comparison: (e2 < e)
 *          
 *          
 * TLDR:
 *  - Comparison function returns whether one value precedes another value in the sort order defined by the function itself.
 *  - Equal values obviously do not precede themselves in the sort order
 *  - So Comparison function should return false when comparing equal values!
 *
 * Summary:
 *  - Ensure that comparison functions for associative containers return FALSE for EQUAL items, otherwise the equivalence of those items will be wrong
 */

