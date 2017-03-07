/*
 * STL containers and thread safety
 *
 * 
 * Multiple readers are safe
 * Multiple writers to seperate contianers are safe
 * 
 * Best way to code against it:
 *  - Create RAII classes that hold mutexes or locks
 *  - This is exception safe as the dtors will be called to free the resources even in the case of stack unwinding
 *  - Lock at the start of functions that will alter containers in a multi-threaded environment
 *  
 *
 *
 *
 * Summary:
 *  - There is none.
 */