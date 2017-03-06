/*
 * If using a container of newed pointers, delete the pointers before destroying the contianer
 * 
 * Containers destroy their elements when they themselves are destroyed
 *  - By calling the destructor of each element
 *  
 * Containers whose elements are pointers:
 *  - Call the destructor of a pointer is a no-op, it does nothing
 *  
 * Soltuion:
 *  - Must delete the pointers within the container before the contianer is destroyed!
 *  
 *  Good way:
 *      - Create a delete function object and use that in a for_each over the container
 *      
 *  Best way:
 *      - Store the elements in the container as smart pointers, which will delete the memory automatically once the containers invokes the
 *        dtor on the smart pointer elements
 *
 * Summary:
 *  - Ensure containers with pointers to newed objects have their elements deleted before the container is deleted
 *      - BASICALLY, only store smart pointers in containers, not raw pointers
 */
