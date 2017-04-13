/*
 *
 *
 *
 *
 * Summary:
 *  -
 */

#include <set>
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <iterator>

namespace item44
{
    using namespace std;

    class RandomInt
    {
        random_device rd;
        mt19937 generator { rd() };
        uniform_int_distribution<int> dis { 1, 1000000 };
        int value { 0 };

    public:
        RandomInt()
            : value{ dis(generator) }
        {}

        operator int() const
        {
            return value;
        }
    };

    void test()
    {
        set<int> bigset;
        size_t count { 0 };

        cout << "Inserting..." << endl;
        while (count < 100000)
        {
            bigset.insert(RandomInt());
            ++count;
        }
        cout << "Inserts complete." << endl << endl;



        cout << "Member Finding 1337: ";
        auto before = chrono::duration_cast<chrono::milliseconds> (chrono::system_clock::now().time_since_epoch()).count();
        auto found1 { bigset.find(1337) };
        cout << boolalpha << (end(bigset) != found1) << endl;
        auto after = chrono::duration_cast<chrono::milliseconds> (chrono::system_clock::now().time_since_epoch()).count() - before;
        cout << "Find duration: " << after << "ms" << endl << endl;


        cout << "Algor Finding 1337: ";
        auto before2 = chrono::duration_cast<chrono::milliseconds> (chrono::system_clock::now().time_since_epoch()).count();
        auto found2 = std::find(begin(bigset), end(bigset), 1337);
        cout << boolalpha << (end(bigset) != found2) << endl;
        auto after2 = chrono::duration_cast<chrono::milliseconds> (chrono::system_clock::now().time_since_epoch()).count() - before2;
        cout << "Find duration: " << after2 << "ms" << endl;




    }
}
