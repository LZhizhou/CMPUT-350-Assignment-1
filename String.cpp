#include "String.h"
#include <iostream>

// constructor: initializes String with char-by-char copy of 0-terminated
// C-string
String::String(const char *p)
{
    shared = new SharedData();
    shared->n = 0;
    shared->count = 1;
    int index = 0;
    
    while (p[index++] != 0)
    {
        shared->n++;
    }
    shared->data = new char[shared->n + 1];
    for (int i = 0; i < index; i++)
    {
        shared->data[i] = p[i];
    }
}

// destructor (when can shared data be released?)
String::~String()
{
    if (shared->count-- == 1)
    {
        delete[] shared->data;
        delete shared;
    }
}

// copy constructor (how does this change reference counts?)
String::String(const String &x)
{
    x.shared->count++;
    shared = x.shared;
}

// assignment operator (how does this change reference counts?)
String &String::operator=(const String &x)
{
    if (this != &x)
    {
        if (shared->count-- == 1)
        {
            delete[] shared->data;
            delete shared;
        }
        x.shared->count++;
        shared = x.shared;
    }

    return *this;
}

// return number of non-0 characters in string
size_t String::size() const
{
    return shared->n;
}

// return reference count
size_t String::ref_count() const
{
    return shared->count;
}

// returns pointer to C-string
const char *String::cstr() const
{
    return shared->data;
}


