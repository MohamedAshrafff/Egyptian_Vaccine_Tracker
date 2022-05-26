#include "List.h"
#include<assert.h>
#include<iostream>
template<class T>
List<T>::List()
{
	size = 5;
	arr = new T[size];
	count = 0;
}

template <class T>
int List<T>::Length()
{
	return count;
}

template <class T>
void List<T>::Append(T value)
{
	if (count == size) {
		Expand();
	}
	arr[count] = value;
	count++;
}

template <class T>
void List<T>::Expand()
{
	T* newarr = new T[size * 2];
	for (int i = 0; i < count; i++) {
		newarr[i] = arr[i];
	}
	size = size * 2;
	delete arr;
	arr = newarr;
}

template <class T>
void List<T>::Delete()
{
	count = 0;
}

template<class T>
List<T>::~List(void)
{
	delete[] arr;
}