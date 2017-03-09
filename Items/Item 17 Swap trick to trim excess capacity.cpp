/*
 *
 *
 *
 *
 * Summary:
 *  -
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
                         cout << c.name << "\n";
                     });
        else
            for_each(begin(con), end(con), [](const auto& c) -> void
                     {
                         cout << c.name << "\n";
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

        auto comp_lambda = [](const Contestant& lhs, const Contestant& rhs) -> bool
                {
                    return !(lhs < rhs);
                };

        partial_sort(begin(contestants), begin(contestants) + 4, end(contestants), comp_lambda);

        print(contestants);
    }
}
