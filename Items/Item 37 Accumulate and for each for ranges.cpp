/*
 * Summarizing a range using accumulate and for_each
 * 
 *  Common summaries:
 *      - count         : # objects in range with specific value 
 *      - count_if      : # objects in range that satisify predicate
 *      - min_element   : Smallest element in range
 *      - max_element   : Largest element in range
 *      
 *  For more general summaries (i.e the product of all elements satisfying condition etc, or the average)
 *      
 *      - accumulate:
 *          - Lives in <numeric>
 *          - Two forms:
 *              - Take pair of iterators defining range + intial value for the sum -> returns sum of all items in range + initial value
 *              - Take pair of iterators defining range + initial value + summarization function -> returns initial value + summary function applied to range

 *          - Summary function :
 *              - return size_type of objects couting, take size_type of summary so far + object to count
 *              - container::size_type is just a typedef for size_t most all of the time
 *              - Can't having any side effects, i.e members of the obejcts passed into the summary function can't be modified inside it
 *              
 *      Standard utility convience functions:
 *          - multiplies<T>, add<T> etc can be passed to the accumulate function to carry out things very easily
 *        
 *      - for_each:
 *          - Allows side effects
 *          - Takes a range and function to invoke on each element in range
 *          - Returns the function object we passed as the function, need to add a getter method to invoke on it to get actual value
 *          
 * Summary:
 *  - Use accumulate to summarize a range
 *  - Use for_each to summarize a range if you also need the summarizing function to have side effects
 */

#include <vector>
#include <numeric>
#include <iostream>
#include <functional>
#include <algorithm>

namespace item37
{
    using namespace std;

    struct runningAvg
    {
    public:
        runningAvg()
            : avgSoFar{ 1.0f }
            , count{ 0 }
        {}

        float operator()(int elem)
        { 
            ++count;
            avgSoFar += elem;
            return avgSoFar;
        }

        float get()
        {
            return avgSoFar / count;
        }

    private:
        float avgSoFar;
        int count;
    };

    void test()
    {
        vector<int> results { 32,54,12,76,23,54,87,23,56 };

        int total = accumulate(begin(results), end(results), 0, plus<int>());   // Using accumulate and convienence functors

        cout << total << endl;


        float avg = for_each(begin(results), end(results), runningAvg()).get(); // Using for_each with a more complicated custom functor for average
        cout << avg << endl;
    }
}
