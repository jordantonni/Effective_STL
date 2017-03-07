/*
 * Allocator convetions and restrictions
 * 
 * What are allocators:
 *  - Originally made to abstract away the differences between how pointers were implemented within segments (near/far/huge)
 *  - Also to help make memory managers as full objects
 *  - They are classes that provide static functions to allocate and deallocate memory for the objects a container will hold
 *  
 * Pointer and Reference typedefs:
 *  - Allocators were originally designed to abstract memory models, so they made their own pointers and references and then had typedefs for them
 *  - Not used anymore as standard says using T* and R& is allowed, so dont have to use the typedefs
 *  
 * Allocator Equilivance:
 *  - Two allocator objects of the same class/type are equilivant and compare as equal
 *  - Allows objects allocted with an instance allocator A to be deallocated with another instance of allocator A, needed for splicing operations.
 *  - Side effect of enforcing allocator instances of the same type are equilivant means no allocator can have state, i.e. only static members allowed!
 *  
 * Allocator<T> interface compare to new:
 *  - void* operator new(size_t bytes); 
 *  - pointer allocator<T>::allocate(size_type numOfObjects);
 *      - Only allocates the memory, doesnt call the ctors of any of the objects!
 *  
 *  - Note how allocators allocate method takes num of objects to allocate memory for, but operator new that num of bytes
 * 
 * Node based containers don't call the allocator provieded anyway:
 *  - Allocators of type allocator<int> could be passed to a list, list<int, allocator<int> >
 *  - But list doesnt allocate just ints, it needs to allocate listNode<int>
 *      - As do all node based containers
 * 
 * Rebind:
 *  - Every allocator must have a nested template struct called rebind
 *  - It defines a typedef to get from an allocator<T> to an allocator<U>
 *  - This allows node based containers to get from allocator<int> to allocator<ListNode<int> > etc
 *
 *
 *
 * Summary:
 *  - Allocators are weird creatures
 */