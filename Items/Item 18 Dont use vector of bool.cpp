/*
 * Dont use vector<bool>
 * 
 * vector<bool> isnt an STL container:
 *  - STL containers must return a pointer to an element via operator[]
 *  - vector<bool> returns a proxy object 
 *      - nested class reference {} inside the partially specialized vector<bool, allocator> class
 *  
 * vector<bool> doesnt hold bools:
 *  - it packs them into individual bits, like a bitfield
 *  - Cant provide a pointer or reference to individual bits on any architecture
 *  
 * 
 * What to use instead?
 *  - deque<bool>
 *  - bitset
 *
 *
 * Summary:
 *  - Don't use vector<bool>
 *      - Cant get reference to elements as it stores bits, not bools, in a bitfield 
 *  - Use deque<bool> or bitset instead
 */

