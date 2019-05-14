#include "iostream"

//NameSpace for a Tasks
namespace itertools {
    
    template <typename T1, typename T2> 
    class chain {
    
    private: // private variables and functions
        T1 itera_A;
        T2 itera_B;

    public:
        chain(T1 start, T2 end) :  itera_A(start), itera_B(end) {}
        
    auto begin(){ 
        return  iterator<decltype(itera_A.begin()),decltype(itera_B.begin())>(itera_A.begin(), itera_B.begin()); }  // iteratable object

    auto end() {
        return iterator<decltype(itera_A.end()),decltype(itera_B.end())>(itera_A.end(), itera_B.end()); }  // iteratable object  
 
    template <typename C1, typename C2>
        class iterator {

        private:
            C1 iterator_A; // iterator A
            C2 iterator_B; // iterator B
         bool checkKind;

        public:
            iterator(C1 itA , C2 itB): iterator_A(itA) , iterator_B(itB), checkKind(true)  {}

           iterator<C1,C2>& operator++() {
                if(checkKind){
                    ++iterator_A;
                }else {
                    ++iterator_B;
                }
                return *this;
            }


            decltype(*iterator_A) operator*() const {

                if(checkKind){
                    return *iterator_A;
                }else {
                    return *iterator_B;
                }
            }

            bool operator!=(iterator<C1,C2>  it){
                if(checkKind && !(iterator_A != it.iterator_A)){
                    checkKind = false;
                }
                if(checkKind){
                    return iterator_A != it.iterator_A;
                }else{
                    return iterator_A != it.iterator_A;
                }
            }


         
        }; // END OF CLASS ITERATOR

    };
}
