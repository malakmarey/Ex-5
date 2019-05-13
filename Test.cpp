#include <iostream>
#include <string>
#include "chain.hpp"
#include "powerset.hpp"
#include "product.hpp"
#include "range.hpp"
#include "zip.hpp"
#include "badkan.hpp"
using namespace std;
using namespace itertools;

int main()
{

    // SOME TESTS WERENT ADDED BECAUSE THE IMPLEMENTATION IS NEEDED
    badkan::TestCase testcase;
    int grade = 0;
    int signal = setjmp(badkan::longjmp_buffer);
    if (signal == 0)
    {
        string test1 = "";
        string test2 = "";
        string test3 = "";
        string test4 = "";

        // test = iterable_to_string(range(5, 9));
        // test = iterable_to_string(range(5.1, 9.1));
        // test = iterable_to_string(range('a', 'e'));
        for (int i : range(5, 9))
        {
            test1.append(to_string(i));
        }
        for (int i : range(0, 10))
        {
            test2.append(to_string(i));
        }
        for (char i : range('a', 'e'))
        {
            test3 += i;
        }
        for (char i : range('a', 'z'))
        {
            test4 += i;
        }
        testcase.setname("Range")
            .CHECK_OUTPUT(test1, "5678")                       // 5678
            .CHECK_OUTPUT(test2, "0123456789")                 // 0123456789
            .CHECK_OUTPUT(test3, "abcd")                       // abcd
            .CHECK_OUTPUT(test4, "abcdefghijklmnopqrstuvwxy"); // abcdefghijklmnopqrstuvwxy

        test1 = "";
        test2 = "";
        test3 = "";
        test4 = "";

        for (int i : chain(range(1, 4), range(5, 8)))
        {
            test1.append(to_string(i));
        }
        for (double i : chain(range(1.5, 4.5), range(5.5, 8.5)))
        {
            test2.append(to_string(i) + " ");
        }
        for (char i : chain(range('a', 'e'), string("hello")))
        {
            test3 += i;
        }
        for (char i : chain(range('a', 'z'), range('z', 'a')))
        {
            test4 += i;
        }
        testcase.setname("Chain")
            .CHECK_OUTPUT(test1, "123567")                                                 // 123567
            .CHECK_OUTPUT(test2, "1.500000 2.500000 3.500000 5.500000 6.500000 7.500000 ") // 1.500000 2.500000 3.500000 5.500000 6.500000 7.500000
            .CHECK_OUTPUT(test3, "abcdhello")                                              // abcdhello
            .CHECK_OUTPUT(test4, "abcdefghijklmnopqrstuvwxyyxwvutsrqponmlkjihgfedcba");    // abcdefghijklmnopqrstuvwxyyxwvutsrqponmlkjihgfedcba

        test1 = "";
        test2 = "";
        test3 = "";
        test4 = "";

        for (auto pair : zip(range(1, 6), string("world")))
        {
            test1.append(to_string(pair) + " ");
        }
        for (auto pair : zip(zip(range(1, 4), string("xyz")), zip(string("abc"), range(6, 9))))
        {
            test2.append(to_string(pair) + " ");
        }
        for (auto pair : zip(range(1, 3), string("ac")))
        {
            test3.append(to_string(pair) + " ");
        }
        testcase.setname("Zip")
            .CHECK_OUTPUT(test1, "1,w  2,o  3,r  4,l  5,d ")
            .CHECK_OUTPUT(test2, "1,x,a,6  2,y,b,7  3,z,c,8 ")
            .CHECK_OUTPUT(test3, "1,a 2,b ");

        test1 = "";
        test2 = "";
        test3 = "";
        test4 = "";

        for (auto pair : product(range(1, 4), string("hello")))
        {
            test1.append(to_string(pair) + " ");
        }
        for (auto pair : product(range(1, 4), string("ad")))
        {
            test2.append(to_string(pair) + " ");
        }
        for (auto pair : product(range(1, 3), range(1, 3)))
        {
            test3.append(to_string(pair) + " ");
        }
        testcase.setname("Product")
            .CHECK_OUTPUT(test1, "1,h  1,e  1,l  1,l  1,o  2,h  2,e  2,l  2,l  2,o  3,h  3,e  3,l  3,l  3,o ")
            .CHECK_OUTPUT(test2, "1,a 1,d 2,a 2,d 3,a 3,d ")
            .CHECK_OUTPUT(test3, "1,1 1,2 1,3 2,1 2,2 2,3 3,1 3,2 3,3 ");

        test1 = "";
        test2 = "";
        test3 = "";
        test4 = "";

        for (auto subset : powerset(range(1, 4)))
        {
            test1.append(to_string(subset) + " ");
        }
        for (auto subset : powerset(chain(range('a', 'c'), range('x', 'z'))))
        {
            test2.append(to_string(subset) + " ");
        }
        testcase.setname("Powerset")
            .CHECK_OUTPUT(test1, "{}{1}{2}{1,2}{3}{1,3}{2,3}{1,2,3} ")
            .CHECK_OUTPUT(test2, "{}{a}{b}{a,b}{x}{a,x}{b,x}{a,b,x}{y}{a,y}{b,y}{a,b,y}{x,y}{a,x,y}{b,x,y}{a,b,x,y} ");

        grade = testcase.grade();
    }
    else
    {
        testcase.print_signal(signal);
        grade = 0;
    }
    cout << "Your grade is: " << grade << endl;
    return 0;
}
template <typename Iterable>
string iterable_to_string(const Iterable &iterable)
{
    ostringstream ostr;
    for (decltype(*iterable.begin()) i : iterable)
        ostr << i << ",";
    return ostr.str();
}