namespace itertools
{


template <class T>

class range
{


private:
    T start; // __starting point
    T _end;   // stopping point.

    class iterator
    {

    public:
        T data;

        //constructor
        iterator(T v) : data(v){}

        // operators  
        T operator*() const
        {
            return data;
        }

      
    iterator &operator++()
        {

            ++data;
            return *this;
        }
        bool operator!=(iterator const &other) const
        { 
            return data != (other.data);
        }

    
    };

public:
    range(T from, T to) : start(from), _end(to) {}                      
    iterator begin() const { return iterator(start); }  
    iterator end() const { return iterator(_end); }      
}; // class


} // namespace itertools
