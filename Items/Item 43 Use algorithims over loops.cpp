/*
 * Use an Algorithm call over a hand written loop
 * 
 * All algorithms take a pair of iterators to demarcate a range over which to do something.
 * Therefore internally every algorithm contains a loop from beginning to the end of the range.
 * 
 * Algorithms are more:
 * 
 *  - Efficient:
 *      - Don't re-evaluate termination expression on each loop when testing
 *      - Library authors have knowledge if container internals, can use that to write better code
 *      - Library autohors use optimal algorithims and data structures to achieve best theoretic complexity
 *      
 *  - Correctness:
 *      - Easy to have iterator invalidation when modifying a container within a loop, algorithms take care of this for you
 *      
 *  - Maintainability:
 *      - A handwritten loop must be read in its entirety before you know what it is doing
 *      - An algorithim call explicitly says what it is doing via its name, it is more expressive
 *      
 *      
 * Drawbacks:
 *  - Before lambdas were introduced, creating certain predicates for an algorithim was difficult due to having to create new functor classes
 *  - Template classes are not allowed to be declared inside functions, so their logic was not close to their use
 *  - Classes defined inside functions are called Local Classes, and are not able to be bound to a template type argument
 *      - Therefore, it was often better to use a handwritten loop when these issues arose, but with lambdas, this is NOT the case
 *
 *
 * Summary:
 *  - Algorithms are more efficient, correct and maintainable than hand written loops, when you can, use them instead!
 *  - With the advent of lambdas, this is only strengthened
 */

namespace item43
{

}