#include "list.h"

template <class T>
List<T>::List()
{
    this->num = 0;
}

template <typename T>
List<T>::~List()
{
   
}

template<class T>
void List<T>::addData(T  &item)
{
    if (num < 100)
    {
        this->arr[this->num] = item;
        num++;
    }
    else
    {
        cout << "The list is full!" << endl;
    }
}

template<class T>
T List<T>::getNumData(int dem)
{
    return this->arr[dem];
}

template<class T>
int List<T>::size()
{
    return this->num;
}

template<class T>
void List<T>::Sort(int i, int j)
{
    swap(this->arr[i], this-> arr[j]);
}
