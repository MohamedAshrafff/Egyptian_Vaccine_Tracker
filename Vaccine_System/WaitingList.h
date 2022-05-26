#pragma once
template <class T>
class WaitingList
{
	T* arr;
	long long count, Size, Front, back;
public:
	WaitingList();
	void enqueue(T);
	void dequeue();
	void expand();
	bool empty();
	T front();
	int size();
	long long length();
	~WaitingList();
};