/*
 * Choose a container
 * 
 * Sequence Containers: Vector, String, Deque, List
 * Associative Containers: Set, Multiset, Map, Multimap
 * Unordered Containers: UnorderedMap,UnorderedSet, UnorderedMulti[Map/Set]
 *
 * Contiguous Memory Containers: Array based
 *  - Elements must be shifted when inserted or removed
 *  - Vector, String, Deque
 *  
 * Node-Based Containers:
 *  - Only pointers change when insertions and deletions occur
 *  - lists, associatve containers and unordered containers
 *  
 * Questions to choose:
 *  - Insert at arbitrary position: Sequence Container
 *
 *  - Care how elements are ordered? 
 *      - No -> Hashed based unordered container.
 *      - Yes -> Avoid unordered containers
 *      
 *  - Iterators?
 *      - Random access -> Vector, Deque, String
 *
 *  - Should elements not be moved when insertions or delections occur?
 *      - If so, do not use a contiguous containers such as vector, deque, string
 *   
 *  - Lookup speed?
 *      - Hashed containers - best O(1)
 *      - Sorted Vectors - good O(lg n)
 *      - Associave containers - acceptable O(lg n)
 *      
 *  - Transactions for insertions and erasures?
 *      - Node based 
 * 
 *  - Minimize iterator, pointer and ref invalidations?
 *      - Node based containers
 *      
 *  - Deque?
 *      - Sequence container with random accesss iterators
 *      - Insertions at the end dont invalidate pointers or references
 *          - Iterators may be invalidated though
 *      
 */

namespace item01
{
    
}