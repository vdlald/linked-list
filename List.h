#ifndef ALINALABLIST_LIST_H
#define ALINALABLIST_LIST_H


#include <cstdio>

template<typename T>
class List {
public:
    virtual size_t get_size() = 0;

    virtual bool is_empty() = 0;

    virtual void add(size_t index, T object) = 0;

    virtual T remove(size_t index) = 0;

    virtual void push(T object) = 0;

    virtual T pop() = 0;

    virtual T get(size_t index) = 0;

    virtual void set(size_t index, T object) = 0;
};


#endif //ALINALABLIST_LIST_H
