/*
 * Be aware of C++'s most vexing parse
 * 
 * Declare a function that takes a double and returns an int:
 *      - int f(double d)
 *      - int f(double (d))
 *      - inf f(double)
 *      
 * Declare a function that takes a pointer to a function that returns a double and takes nothing, and returns an int:
 *      - int g(double (*pf)() )
 *      - int g(double pf() )
 *      - int g(double () )
 *
 * 
 * Parenthesis around a parameter name are ignored, such as int f(double (d) )
 * 
 * Parentheses on their own indicate a parameter list, i.e. a pointer to a function
 *
 * Summary:
 *  - Anything that can be parsed as a function declaration in C++, will be
 */

#include <list>
#include <fstream>
#include <iterator>

namespace item06
{
    using namespace std;

    ifstream dataFile("SomeData.txt");

    list<int> data(istream_iterator<int> (dataFile), istream_iterator<int> ()); // This declares a function called dataFile!


}
