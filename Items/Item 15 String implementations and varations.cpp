/*
 * STL String implementations
 * 
 * All String implementations contain:
 *  - Size      : Number of chars in a string
 *  - Capacity  : How many chars the string can hold without having to allocate more memory and reallocate the old string
 *  - Value     : The characters in the string
 *  
 * Some contain:
 *  - Allocator : Copy of the allocator being used
 *  
 * Reference Counting:
 *  - All string used to be reference counted. Most arent now days, including VC++
 *  
 * Examples:
 *  Imp A:  Allocator, size etc on stack, pointer to value on heap
 *  Imp B: Pointer to heap block with allocator, size etc, another pointer to heap value
 *  Imp C: Pointer to block on heap with everything and value
 *  Imp D: All on stack if char string length < 15, else stack buffer that held string now points to heap allocated value
 *
 *
 *
 * Summary:
 *  - Some string implementations may be reference counted. Most probably not nowadays due to mad optimization
 *  - Some strings may be up to 7x larger than a char* object, i.e. the char* is size of a pointer but e.g. Imp D would have all data on stack (minus value on heap)
 *  - Some strings may share info on their size and capacity with copyied strings
 *  - Some strings have minimum sizes, i.e. Imp D always has the stack buffer to hold strings < 15 chars
 */