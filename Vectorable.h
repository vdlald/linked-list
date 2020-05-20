#ifndef ALINALABLIST_VECTORABLE_H
#define ALINALABLIST_VECTORABLE_H

#include <vector>

template<typename T>
class Vectorable {
public:
    virtual std::vector<T> to_vector() = 0;
};

#endif //ALINALABLIST_VECTORABLE_H
