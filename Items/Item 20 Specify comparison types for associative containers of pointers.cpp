/*
 * Specify your own comparison type functor for associatve containers of pointers
 * 
 * The default comparison operator used for a set<T> is less<T>
 * 
 * If you store pointers in your set, you will get a set<T*> using less<T*>
 *  - The comparison function wont sort by the values of the pointers, but by the pointer values themselves!
 *  
 * Need to write a function object that can dereference the pointers and compare on the fields you want to be soted by
 *
 * NOTE:
 *  - Better to use copy(stringSet.begin(), stringSet(end), ostream_iterator<string>(cout, "\n") );
 *  - Instead of a for loop that prints each element out by itself
 *      - Using the STL algorithim way along with iterator objects instead of raw dereferences is safer and gives better error messages
 *
 * Summary:
 *  - 
 */

#include <iostream>
#include <set>


namespace item20
{
    struct Widget
    {
        int id = -1;

        struct Widget_Comparison
        {
            bool operator()(const Widget& lhs, const Widget& rhs) const
            {
                return lhs.id < rhs.id;
            }
        };

        // This comparison function first dereferences the pointer then compares the elements
        struct Widget_Pointer_Comparison
        {
            bool operator()(const Widget* lhs, const Widget* rhs) const
            {
                return lhs->id < rhs->id;
            }
        };
    };

    void test()
    {
        std::set<Widget*, Widget::Widget_Pointer_Comparison> wid_set;
        wid_set.insert(new Widget{ 1337 });
        wid_set.insert(new Widget{ 123 });
        wid_set.insert(new Widget{ 99 });
        wid_set.insert(new Widget{ 9999 });
        wid_set.insert(new Widget{ 544 });

        for (const auto& e : wid_set)
            std::cout << e->id << std::endl;

    }
}
