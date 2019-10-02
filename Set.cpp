#include "Set.h"
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <bitset>
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
    // copy bits
    for(unsigned int i = 0; i < a; i++){
        bits[i] = s.bits[i];
    }
}        
// assignment operator    
Set &Set::operator=(const Set &s){
    if (&s!=this)
    {
        n = s.n;
        a = s.a;
        delete[] bits;
        bits = new unsigned int[a]();
        // copy bits
        for(unsigned int i = 0; i < a; i++){
            bits[i] = s.bits[i];
        }
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
    // std::bitset<64> c(*bits);
    // std::cout<<c<<std::endl;
    // set complement int by int
    for(unsigned int i = 0; i < a; i++){
        bits[i] = ~bits[i];
    }
    // *bits = ~*bits;
    
    // std::bitset<64> b(*bits);
    // std::cout<<b<<std::endl;
}        
// return true iff x is element of set (0 <= x < n)
bool Set::has(size_t x) const{

    // x/INT_BITS is the index of array
    // x%INT_BITS is the index of bit in the element
    return 1 & (bits[x/INT_BITS]>>(x%INT_BITS));
} 
// add element x to set (0 <= x < n)
void Set::add(size_t x){

    // x/INT_BITS is the index of array
    // x%INT_BITS is the index of bit in the element
    bits[x/INT_BITS] |= (1 << x%INT_BITS);
}    
// remove element x from set (0 <= x < n)  
void Set::remove(size_t x){
    // x/INT_BITS is the index of array
    // x%INT_BITS is the index of bit in the element
    bits[x/INT_BITS] &= ~(1 << x%INT_BITS);
}  

// add all elements of s to set; pre-cond: s.n == n
void Set::add(const Set &s){
    assert(s.n==n);
    // element by element
    for(unsigned int i = 0; i < a; i++){
        bits[i] |= s.bits[i];
    }
    //*bits |= *(s.bits);
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
    // element by element
    for(unsigned int i = 0; i < a; i++){
        bits[i] &= bits[i] ^ s.bits[i];
    }
    
}


// print elements to output stream os (default std::cout) like so:
// [ 1 2 4 5 ]
// for set {1,2,4,5} (no extra spaces, no newline characters)
void Set::print(std::ostream &os) const{

    os<<"[ ";
    for (unsigned int i = 0; i < n; i++)
    {

        if(Set::has(i)){
            os << i << " ";
        }
    }
    os << "]";
}