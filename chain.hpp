#include "iostream"

namespace itertools
{
template <typename T1, typename T2>
class chain
{
private:
    T1 iter_A;
    T2 iter_B;

public:
    chain(T1 start, T2 end) : iter_A(start), iter_B(end) {}
    auto begin()
    {
        return iterator<decltype(iter_A.begin()), decltype(iter_B.begin())>(iter_A.begin(), iter_B.begin()); // iteratable object
    }
    auto end()
    {
        return iterator<decltype(iter_A.end()), decltype(iter_B.end())>(iter_A.end(), iter_B.end()); // iteratable object
    }
    template <typename B1, typename B2>
    class iterator
    {

    private:
        B1 iterator_A; // iterator A
        B2 iterator_B; // iterator B
        bool checkKind;

    public:
        iterator(B1 itA, B2 itB) : iterator_A(itA), iterator_B(itB), checkKind(true) {}

        iterator<B1, B2> &operator++()
        {
            if (checkKind)
            {
                ++iterator_A;
            }
            else
            {
                ++iterator_B;
            }
            return *this;
        }

        decltype(*iterator_A) operator*() const
        {

            if (checkKind)
            {
                return *iterator_A;
            }
            else
            {
                return *iterator_B;
            }
        }

        bool operator!=(iterator<B1, B2> it)
        {
            if (checkKind && !(iterator_A != it.iterator_A))
            {
                checkKind = false;
            }
            if (checkKind)
            {
                return iterator_A != it.iterator_A;
            }
            else
            {
                return iterator_B != it.iterator_B;
            }
        }

    }; // END OF CLASS ITERATOR
};
} // namespace itertools