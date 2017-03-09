/*
 * Swap trick to trim excess capacity
 *
 * Shrink to fit:  
 *  - Erase reduces the size of the vector, but not the capacity
 *  - Swap trick reduces the capaicty to free up the space
 *  
 * How?
 *  - vector<int>(v1.begin(), v1.end())             : Copy constructs a temp vector of int from v1, using a range ctor (Note it doesnt copy the erased elements)
 *  - vector<int>(v1.begin(), v1.end()).swap(v1)    : Swaps the smaller temp vector into v1, removing all the elements that were erased
 *
 * Clear a vector or string:
 *  - vector<int>().swap(v1)    : Default initializes a temp vector then swaps that into the vector v1, essentially clearing it
 *  
 *  
 * Summary:
 *  - Use swap trick to bring capacity down to the size of the container
 *  - Works by copy ctor a temp container using range ctor, then swapping that back into the origianl
 */

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

namespace item17
{
    class Contestant
    {
    public:
        string name;
        int money;

        Contestant(const string& na, const int mon)
            : name { na }
            , money { mon }
        {}

        bool operator<(const Contestant& rhs) const
        {
            return money < rhs.money;
        }
    };

    template <typename T>
    void print(T con, int last = 0)
    {
        if (last != 0)
            for_each(begin(con), begin(con) + last, [](const auto& c) -> void
                     {
                         cout << c.name << "\t";
                     });
        else
            for_each(begin(con), end(con), [](const auto& c) -> void
                     {
                         cout << c.name << "\t";
                     });

        cout << endl << endl;
    }


    void test()
    {
        vector<Contestant> contestants;
        contestants.emplace_back(Contestant("Jay", 1337));
        contestants.emplace_back(Contestant("hjds", 87));
        contestants.emplace_back(Contestant("hfjwe", 34));
        contestants.emplace_back(Contestant("hiosfd", 74));
        contestants.emplace_back(Contestant("fsdhuiofhsef", 32));
        contestants.emplace_back(Contestant("yoier", 12));
        contestants.emplace_back(Contestant("hjdfs", 1));
        contestants.emplace_back(Contestant("sdiwe", 999));
        contestants.emplace_back(Contestant("oiwdf", 1200));

        print(contestants);

        cout << contestants.capacity() << endl;

        auto comp_lambda = [](const Contestant& lhs, const Contestant& rhs) -> bool
                {
                    return !(lhs < rhs);
                };

        partial_sort(begin(contestants), begin(contestants) + 4, end(contestants), comp_lambda);    // Sort the first 4 highest money values

        contestants.erase(begin(contestants)+4, end(contestants)); // Remove all the rest (This only moves the end itertator down, doesnt delete them)

        cout << endl << endl << "Cap = " << contestants.capacity() << endl;
        vector<Contestant>(begin(contestants), end(contestants)).swap(contestants);     // Swap trick 
        cout << endl << endl << "Cap = " << contestants.capacity() << endl;

        print(contestants);


    }
}
