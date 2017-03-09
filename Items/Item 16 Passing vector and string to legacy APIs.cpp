/*
 * How to pass Vector and String to C APIs
 * 
 * 
 * With vector:
 *  - Vector<int> v;
 *  - &v[0]    -> Gives you a pointer to the contigious memory that is the vector
 *  - Wrap &v[0] inside a test for !v.empty(), as otherwise you can get a pointer to something that doesnt exist
 *  - If passing vector to c API using &v[0], make sure it doesnt modify the SIZE of the vector. This will render the size() etc of the vector inconsistent!
 *  
 *  
 * With String:
 *  - s.c_str()   Gives you a c style string version of the string data
 *  - String value is not guaranted to be stored in single chunk of contigious memory
 *  - Only pass c_str() to a const char*, why?
 *      - The c style string may be stored in a proxy like object, that isnt modiflible, it is not correct to try to modify a cpp string using s.c_Str()
 *
 * Other containers and a C API:
 *  - Copy containers values into a vector
 *      - i.e. via a range ctor
 *  - pass the vector to the C API via &v[0];
 *
 * Summary:
 *  - &v[0] to get pointer to start of vector, can treat as a c array
 *  - S.c_str() to get c style string from c++ string
 *  
 *  - Can't modify the string from a c_str() call
 *  - Dont chage number of elements in the vector using &v[0]
 *  
 *  - Pass other containers to C API via range ctor them into a vector then passing that
 */
