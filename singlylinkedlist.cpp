#include <iostream>

template <class T> class List{
	public:
		void clear();
		bool isEmpty();
		bool append(const T value);
		bool insert(const int p, const T value);
		bool delete(const int p);
		bool getPos(int &p, const T value);
		bool getValue(const int p, T &value);
		bool setValue(const int p, const T value);	
};

// node for singly linked list

template <class T> class Link{
	public:
		T data;
		Link<T> *next;

		Link(const T info, const Link<T> *nextValue = NULL){
			data = info;
			next = nextValue;
		}

		Link(const Link<T> *nextValue){
			next = nextValue;
		}
};

// singly linked list

template <class T> class lnkList: public List{
	private:
		Link<T> *head, *tail;
		Link<T> *setPos(const int p);
	public:
		lnkList(int s);
		~lnkList();
		bool isEmpty();
		void clear();
		int length();
		bool append(const T value);
		bool insert(const int p, const T value);
		bool delete(const int p);
		bool getValue(const int p, T &value);
		bool getPos(int &p, const T value);	
};

template <class T>
Link<T> * lnkList::setPos(int i){
	int count = 0;
	if(i == -1)
		return head;
	Link<T> *p = head->next;
	while(p != NULL && count < i){
		p = p->next;
		count++;
	};
	return p;
}

//insert

template <class T>
bool lnkList<T>::insert(const int i, const T value){
	Link<T> *p, *q;
	if((p = setPos(i-1)) == NULL){
		cout<<"illegal insert"<<endl;
		return false;
	}

	q = new Link<T>(value, p->next);
	p->next = q;
	if(p == tail)
		tail = q;
	return true;
}

//delete

template <class T>
bool lnkList<T>::delete(const int i){
	Link<T> *p, *q;
	if((p = setPos(i-1)) == NULL || p == tail){
		cout<<"illegal delete"<<endl;
		return false;
	}

	q = p->next;
	if(q == tail){
		tail = p;
		p->next = NULL;
	}
	else{
		p->next = q->next;
	}
	delete q;
	return true;
}



