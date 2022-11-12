#pragma once
#ifndef LIST_H_
#define LIST_H_
#include"Car.h"

template<class T>
class List {
private:
	T arr[100];
	int num; //so xe
public:
	List();
	virtual ~List();
	void addData(T &);
	T getNumData(int);
	int size();
	void Sort(int i, int j);
	
};
#endif /* LIST_H_ */