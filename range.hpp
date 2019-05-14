namespace itertools
{
template <class T>
class range
{
private:
    T start;
    T end;

public:
    class iterator
    {

    public:
        T data;
        //constructor
        iterator(T d) : data(d) {}
        
        long int operator*() const { return data; }
        const iterator &operator++()
        {
            ++data;
            return *this;
        }
        bool operator!=(const iterator &other) const
        {
            return data != other.data;
        }
    };

public:
    range(T from, T to) : start(from), end(to) {}
    iterator begin() const { return iterator(start); }
    iterator end() const { return iterator(end); }
}; // class
} // namespace itertools