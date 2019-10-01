#include "Set.h"
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <math.h>
static const int INT_BITS = sizeof(int) * 8;

// create empty subset of {0..n-1}
Set::Set(size_t n){

    Set::n = n;
    a = ceil(n / INT_BITS);
    bits = new unsigned int[a]();
}
// destructor
Set::~Set(){
    delete[] bits;
}           
// copy constructor
Set::Set(const Set &s){
    n = s.n;
    a= s.a;
    delete[] bits;
    bits = new unsigned int[a]();
    *bits = *(s.bits);
}        
// assignment operator    
Set &Set::operator=(const Set &s){
    if (&s!=this)
    {
        n = s.n;
        a = s.a;
        delete[] bits;
        bits = new unsigned int[a]();
        *bits = *(s.bits);
    }
    return *this;
}
// empty set
void Set::clear(){
    delete[] bits;
    bits = new unsigned int[a]();
} 
// negate set (x was in set before <=> x is not in set after)
void Set::complement(){
    *bits = ~*bits;
}        
// return true iff x is element of set (0 <= x < n)
bool Set::has(size_t x) const{
    return (1 << x) & *bits;
} 
// add element x to set (0 <= x < n)
void Set::add(size_t x){
    *bits |= (1 << x);
}    
// remove element x from set (0 <= x < n)  
void Set::remove(size_t x){
    *bits &= ~(1 << x);
}  

// add all elements of s to set; pre-cond: s.n == n
void Set::add(const Set &s){
    assert(s.n==n);
    *bits |= *(s.bits);
}

// remove all elements of s from set; pre-cond: s.n == n
/*
1   1   0
1   0   1
0   1   0
0   0   0
*/
void Set::remove(const Set &s){
    assert(s.n==n);
    *bits &= *bits ^ *s.bits;
}


// print elements to output stream os (default std::cout) like so:
// [ 1 2 4 5 ]
// for set {1,2,4,5} (no extra spaces, no newline characters)
void Set::print(std::ostream &os) const{
    os<<"[ ";
    for (unsigned int i = 0; i < n; i++)
    {
        if(*bits&(1<<i)){
            os << i << " ";
        }
    }
    os << "]";
}