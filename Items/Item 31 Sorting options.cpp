/*
 *
 *
 *
 *
 * Summary:
 *  -
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

        students.emplace_back(Person { "Ryan", 34 });
        students.emplace_back(Person { "emma",64 });
        students.emplace_back(Person { "jeff",32 });
        students.emplace_back(Person { "mark",53 });
        students.emplace_back(Person { "john",98 });
        students.emplace_back(Person { "sarah",21 });
        students.emplace_back(Person { "kate",87 });
        students.emplace_back(Person { "rhonda",63 });
        students.emplace_back(Person { "richard",21 });
        students.emplace_back(Person { "sam",88 });

        print(students);

        partial_sort(begin(students), begin(students) + 4, end(students), rescomp);

        print(students);
    }
}
