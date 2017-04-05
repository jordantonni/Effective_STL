/*
 * What sorting algorithim to use
 * 
 * 
 * Random Access iterators (Vector, Array, String, Deques):
 * 
 *     sort             - Uses Intro sort (Quicksort that can use Heapsort if small) O(n lg n)
 *                      - Sorts entire container
 *                      - Default comparison predicate is less<T> ( < )
 *     
 *     stable_sort      - Stable version of sort
 *                  
 *     partial_sort     - Sorts the first n items in order
 *                      - Leaves the rest unsorted
 *                      - Equilivance
 *                      - Not Stable
 *                      
 *     nth_element      - Sorts the top n items (but the items in that sorted range are not sorted)
 *                      - Leaves the rest unsorted
 *                      - Can easily find median value by choosing container.size() / 2 as n
 *                      - Can easily get value at 75th precentile by choosing container.size() * 0.25 as n
 *                      - Equilivance
 *                      - Not Stable
 *
 * Bidirectional Iterators (Any Sequence container i.e. List)
 * 
 *     partition:       - Takes a predicate
 *                      - Returns an iterator to end of sorted range
 *                      - Sorts such that all items that satisfy predicate are sorted before the returned iterator
 * 
 * Efficiency (Most to least)
 *  (1) partition
 *  (2) stable_partition
 *  (3) nth_element
 *  (4) partial_sort
 *  (5) sort
 *  (6) stable_sort
 *
 * Summary:
 *  - Full sort use either sort or stable_sort or list::sort
 *  - Top n elements in order, partial_sort
 *  - Element at position n or top n elements in any order, nth_element
 *  - Split elements into 2 depending on criteria, partition
 *  
 */

#include <vector>
#include <algorithm>
#include <string>
#include <ostream>
#include <iostream>

namespace item31
{
    using namespace std;

    struct Person
    {
        string name;
        float exam_result;

        Person(const string& na, const float res)
            : name{ na }
            , exam_result{ res }
        {}

        friend ostream& operator<<(ostream& ost, const Person& p)
        {
            ost << p.name << "\t[ " << p.exam_result << " ]\n";
            return ost;
        }
    };

    bool rescomp(const Person& lhs, const Person& rhs)
    {
        return lhs.exam_result > rhs.exam_result;
    }

    void print(const vector<Person>& c)
    {
        for(const auto& e : c)
            cout << e;

        cout << endl << endl;
    }

    void test()
    {
        vector<Person> students;
        students.reserve(10);

        students.emplace_back(Person { "ryan", 34 });
        students.emplace_back(Person { "emma",100 });
        students.emplace_back(Person { "jeff",32 });
        students.emplace_back(Person { "mark",53 });
        students.emplace_back(Person { "john",98 });
        students.emplace_back(Person { "sara",21 });
        students.emplace_back(Person { "kate",87 });
        students.emplace_back(Person { "rhonda",63 });
        students.emplace_back(Person { "richard",21 });
        students.emplace_back(Person { "sam",88 });

        print(students);

        partial_sort(begin(students), begin(students) + 4, end(students), rescomp);

        print(students);
    }
}
