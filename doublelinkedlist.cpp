#include <iostream>

template <class T> class Link{
	public:
		T data;
		Link<T> *next;
		Link<T> *prev;
		Link(const T info, Link<T> *preValue = NULL, Link<T> *nextValue = NULL){
			data = info;
			next = nextValue;
			prev = preValue;
		}

		Link(Link<T> * preValue = NULL, Link<T> * nextValue = NULL){
			next = nextValue;
			prev = preValue;
		}
};

