/*
 * When to use a custom allocator
 * 
 * If default STL memory manager allocator<T> is:
 *  - Excessive fragmentation
 *  - Want to use shared memory
 *  - Want to use a special heap
 *  
 * Can create own allocator with the allocate and deallocate methods:
 *  - They can call your special versions of new or malloc etc
 *  
 * Note that only the objects stored by the container will be in this memory, the container itself will be a normal stack variable
 *
 *
 *
 */