/*
 * Consider using sorted vectors over associative containers
 * 
 * Associative Containers, such as set, map, multiset and multimap:
 *  - Implemented as balanced binary tree
 *  - Suited for mixed calls to insertions, erasures and lookups of elements
 *  
 * If instead you will use the DS in a more formal (discrete phases) way such as all inserts first, then some lookups then some erasures:
 *  - Can be better with a sorted vector
 *  - Sorted vector can use; binary_search, lower_bound, upper_bound, equal_range
 *  
 * Why?
 *  - Associative containers store objects as nodes -> At least 3 pointers size bigger than plain object in vector
 *  - More page faults and cache misses
 *  
 * Note:
 *  - Keeping a vector sorted is very expensive, due to copying, shifting, deleting, allocating etc
 *  - This technique is only viable when you dont mix insertions with erasures
 *
 *
 * Summary:
 *  - If you will be using your set or map in discrete phases of Inserts, then lookups, then erasures
 *      - Might be more efficient to store data in a SORTED vector
 */