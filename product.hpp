#include <utility> // pair

namespace itertools
{


template <class T, class E>
/*
* _product class, using two iteratables to iterate over them in pairs (I.E returns elements of type std::pair<T,E>).
* the values given to the constructor must be a iteratable objects (implementing begin() and end() functions).
* and an iterator (ofcourse) which implements the following operators: != (not equal), ++ (prefix increment).
* the _product class contains inner iterator.
*/
class _product
{
    // Private variables and methods
private:
    T _iter_A;    // first iteratable - should be an iteratable
    E _iter_B;    // second iteratable - should be an iteratable

    // Inner class (iterator)
    template <typename U, typename V>
    class iterator
    {
    public:
        // variables
        U _iterator_A; //  should be an iterator
        V _iterator_B; //  should be an iterator

        V _iterator_B_start_pos; //  should be an iterator

        //constructor
        iterator(U iteratable_A, V iteratable_B) : 
            _iterator_A(iteratable_A), 
            _iterator_B(iteratable_B),
            _iterator_B_start_pos(iteratable_B) {}

        // operators
        bool operator!=(_product::iterator<U,V> const &other) 
        {            
            // if iterator A hasn't finish yet, and B finished, then rewind B to the start.
            if ((_iterator_A != other._iterator_A) && !(_iterator_B != other._iterator_B))
            { // rewind B
                _iterator_B = _iterator_B_start_pos;
                ++_iterator_A;
            }

            return (_iterator_A != other._iterator_A);
        }

        std::pair<decltype(*_iterator_A),decltype(*_iterator_B)> operator*() const
        {
            return std::pair< decltype(*_iterator_A),
                              decltype(*_iterator_B)> (*_iterator_A,*_iterator_B);
        }

        _product::iterator<U,V> &operator++()
        {
            ++_iterator_B;
            return *this;
        }
    };

public:
    _product(T from, E to) : _iter_A(from), _iter_B(to) {} // constructor

    auto begin() const{ 
        return  _product::iterator<decltype(_iter_A.begin()),decltype(_iter_B.begin())>(_iter_A.begin(), _iter_B.begin()); }  // iteratable object

    auto end() const {
        return _product::iterator<decltype(_iter_A.end()),decltype(_iter_B.end())>(_iter_A.end(), _iter_B.end()); }  // iteratable object  
};  // class

template <typename T, typename E>

_product<T, E> product(T first, E second)
{
    return _product<T, E>(first, second);
}

} // namespace itertools