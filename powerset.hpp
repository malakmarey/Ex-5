#pragma once
#include "range.hpp"
#include "product.hpp"

/*~Represents all sub-groups of container-like~*/

using namespace std;

namespace itertools{
    template<typename X> class powerset{
        public:
        //varaibels:
        X set;


        //Constructor:
        powerset(X container) : set(container){}
        
        //Inner class iterator
        class iterator{
            public:
            //Varaibels
            decltype(set.begin()) sBegin;
            decltype(set.end()) sEnd;

            iterator(decltype(set.begin()) setBegin, decltype(set.end()) setEnd) :
            sBegin(setBegin), sEnd(setEnd){}

            //Overloading operators:

            //---------------------need to be implement-------------------------//
            //* Operator
            auto operator*() const{
                return *sBegin;
            }

            //++i Operator
            iterator* operator++(){
                    *sBegin++;
                    return this;
            }

            //i++ Operator
			const iterator operator++(int) {
				iterator tmp= *this;
				*sBegin++;
				return tmp;
            }

            //== Operator
            bool operator==(const iterator& other) const {
				return *sBegin == *other.sBegin && *sEnd == *other.sEnd;
			}

            //!= Operator
            bool operator!=(const iterator& other) const {
				return *sBegin != *other.sBegin && *sEnd != *other.sEnd;
			}





        };//end iterator

        auto begin() const{
            return (set.begin(), set.end());
        }

        auto end() const{
            return (set.end(), set.end());
        }


    };//end powerset



};//end namespace iteratools
