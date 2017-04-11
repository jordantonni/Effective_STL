/*
 * Make sure less<T> ALWAYS calls operator< for type T
 * 
 * operator< is the default way to implement less<T>
 * less<T> is the default comparison functor used for all sorting and searching 
 * 
 * Therefore operator< is the default.
 * 
 * If you want to sort objects using another criteria, don't specialize less<T> for your type T
 * instead, create a new functor and pass it to the algorithim
 * 
 * e.g: set<Widget, MyComparisonFunctor> mySet;
 *
 *
 *
 * Summary:
 *  - Always ensure less<T> means operator< for your type   - It's what is always expected
 */


