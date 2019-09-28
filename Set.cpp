#include "Set.h"
static const INT_BITS = sizeof(int)*8

// create empty subset of {0..n-1}
Set::Set(size_t n){
    for (int i = 0; n > 0; i++)
    {
        /* code */
    }
    
}
Set::~Set();                  // destructor
Set::Set(const Set &s);            // copy constructor
Set &Set::operator=(const Set &s); // assignment operator

void Set::clear();             // empty set
void Set::complement();        // negate set (x was in set before <=> x is not in set after)
bool Set::has(size_t x) const; // return true iff x is element of set (0 <= x < n)
void Set::add(size_t x);       // add element x to set (0 <= x < n)
void Set::remove(size_t x);    // remove element x from set (0 <= x < n)

// add all elements of s to set; pre-cond: s.n == n
void Set::add(const Set &s);

// remove all elements of s from set; pre-cond: s.n == n
void Set::remove(const Set &s);

// return maximum number of elements
size_t Set::get_n() const { return n; }

// print elements to output stream os (default std::cout) like so:
// [ 1 2 4 5 ]
// for set {1,2,4,5} (no extra spaces, no newline characters)
void Set::print(std::ostream &os = std::cout) const;