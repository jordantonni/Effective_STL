/*
 * Prefer using iterator over const_itererator, reverse_iterator or const_reverse_iterator
 * 
 * Every container offers:
 *  - iteraor           -> Basically T*
 *  - const_iterator    -> Basically a const T*
 *  - reverse_iteraor   -> T* that starts are the end and moves backwards via ++
 *  - const_reverse_iterator
 *  
 * Implicit conversions exists from:
 *  - iterator      ->  const_iterator
 *  - iterator      ->  reverse_iterator    ->  const_reverse_iterator
 *  
 * Base():
 *  - Base gives you the iterator from a reverse iterator:
 *  - It always points to one element to the right of the element that the reverse_iterator pointed to!
 *
 * Iterator is special:
 *  - Only a normal unadorned iterator is used as a parameter by almost all algorithim and member functions
 *  - So makes it easy to use them over others
 *
 * Summary:
 *  - Most algorithims and methods that take iterator require a plain iterator
 *      - Make it easy for yourself and just use plain iterators when you can
 */