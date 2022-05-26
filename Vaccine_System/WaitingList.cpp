#include "WaitingList.h"
#include <iostream>
#include <assert.h>

template <class T>
WaitingList<T>::WaitingList()
{
    Size = 2;
    count = 0;
    Front = back = -1;
    arr = new T[Size];
}

template <class T>
void WaitingList<T>::enqueue(T value)
{
    if (count == Size)
        expand();

    if (count == 0)
        Front = 0;

    back = (back + 1) % Size;
    arr[back] = value;
    count++;
}

template <class T>
void WaitingList<T>::dequeue()
{
    assert(!empty());
    if (count == 1)
        Front = back = -1;
    else
        Front = (Front + 1) % Size;
    count--;
}

template <class T>
bool WaitingList<T>::empty()
{
    return (count == 0);
}

template <class T>
T WaitingList<T>::front()
{
    return (arr[Front]);
}

template <class T>
int WaitingList<T>::size()
{
    return count;
}

template <class T>
void WaitingList<T>::expand()
{
    T* newarr = new T[Size * 2];

    for (long long i = 0; i < count; i++)
    {
        newarr[i] = arr[i];
    }

    Size = Size * 2;
    delete arr;
    arr = newarr;
}

template <class T>
long long WaitingList<T>::length()
{
    return count;
}


template <class T>
WaitingList<T>::~WaitingList(void)
{
    delete[]arr;
}

