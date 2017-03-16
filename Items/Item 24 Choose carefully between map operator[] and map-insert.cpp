/*
 * Difference between map::operator[] and map::insert
 *
 *
 * Maps' operator[] is not the same as for all other DS:
 *  - It provdies 'add or update' functionality
 *  -  First checks to see if the element is in the DS
 *      - If not, default constructs it
 *      - returns reference to new default ctors object
 *      - The does assignment to it
 *  - If it exists, it just assigns new value
 *  
 *  Expensive^^
 *  
 *  
 *
 * Summary:
 *  - If updating a value that exists in the Map, use operator[], more efficient
 *  - If adding a new value to the map, use map::insert, more efficient
 */