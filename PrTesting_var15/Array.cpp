#include "Array.h"

template<class T>
void Array<T>::free_memory() {
    if (length != 0) {
        delete array;
        length = 0;
    }    
}

template<class T>
int Array<T>::size() {
    return length;
}

template<class T>
T Array<T>::get(int index) {
    if (index < 0 || index >= length) {
        throw - 1;
    }
    return array[index];
}


template<class T>
inline void Array<T>::set(int index, T value)
{
    if (index < 0 || index >= length) {
        throw - 1;
    }
    array[index] = value;
}

template class Array<int>;
template class Array<float>;
template class Array<double>;
template class Array<bool>;
template class Array<char>;
template class Array<char*>;