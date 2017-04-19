/*
 * Pass function objects instead of function pointers to algorithms
 * 
 * Passing a functor instead of a function pointer is faster:
 *  - Invoking an algorithim with a predicate such as find(it1, it2, 5, MyCompFun);
 *      - Here MyCompFun is passed as a function pointer
 *      - Can't be inlined (Almost all implementations don't inline functions invoked though function pointers)
 *      
 *  - A functor classes operator() can be inlined:
 *      - If it is defined within the class definition it is implicitly inlined
 *      - Can be explicitly declared inline in the definition
 *      
 *
 * Summary:
 *  - Pass functors instead of function pointers to algorithims
 *  - Note:
 *      - Lambdas are really function objects / closures internally, so they are still the best thing to pass
 */
