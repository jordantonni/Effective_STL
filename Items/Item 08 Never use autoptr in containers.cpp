/*
 * Don't use auto_ptr in containers, or ever!
 *
 *
 *
 * Summary:
 *  - Auto_ptrs transfer ownership to the copied to auto_ptr when copied. Setting the src auto_ptr to null
 *      - i.e. chaging the elements value by copying it!
 *  - All containers make liberal use of copying their elements, so this is not good!
 */