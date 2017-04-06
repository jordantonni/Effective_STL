/*
 * Case-Insensitive string comparison
 * 
 *  strcmp:
 *      - Compares two chars or strings
 *          - returns 0 if same
 *          - 1 if lhs < rhs
 *          - -1 if rhs < lhs
 * 
 *  lexicographical_compare:
 *      - Generalized form of strcmp, instead of only working in chars
 *      - Can be passed a predicate and compares using that
 *      
 *  mismatch:
 *      - returns pair of iterators (one pointer to the respective element in two ranges)
 *      - indicates the first location where they fail to match
 *
 *
 * Summary:
 *  -
 */