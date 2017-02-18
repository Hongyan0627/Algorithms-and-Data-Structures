#include <iostream>
using namespace std;

template <class T> class List{
	public:
		virtual void clear() = 0;
		virtual bool isEmpty() = 0;
		virtual bool append(const T value) = 0;
		virtual bool insertNode(const int p, const T value) = 0;
		virtual bool deleteNode(const int p) = 0;
		virtual bool getPos(int &p, const T value) = 0;
		virtual bool getValue(const int p, T &value) = 0;
		virtual bool setValue(const int p, const T value) = 0;	
};

template <class T>
class arrList: public List<T> {
private:
	T *aList;
	int maxSize;
	int curLen;
	int position;
public:
	arrList(int size){
		maxSize = size;
		aList = new T[maxSize];
		curLen = position = 0;
	}
	~arrList(){
		delete [] aList;
		aList = NULL;
	}
	void clear(){
		delete [] aList;
		curLen = position = 0;
		aList = new T[maxSize];
	}
	int length() {
		return curLen;
	}
	bool append(const T value) {
		if(curLen >= maxSize) {
			return false;
		} else {
			aList[curLen++] = value;
			return true;
		}
	}
	bool deleteNode(const int p);
	bool insertNode(const int p, const T value);
	bool setValue(const int p, const T value) {
		if(p < 0 || p >= curLen) {
			return false;
		} else {
			aList[p] = value;
			return true;
		}
	}
	int getValue(const int p, T &value) {
		if(p < 0 || p >= curLen) {
			return false;
		} else {
			value = aList[p];
			return true;
		}
	}
	bool getPos(int &p, const T value) {
		for(int i = 0; i < curLen; i++) {
			if(aList[i] == value) {
				p = i;
				return true;
			}
		}
		return false;
	}
};

//insertNode

template <class T> 
bool arrList<T>::insertNode(const int p, const T value) {
	int i;
	if(curLen >= maxSize){
		cout<<"This list is overflow"<<endl;
		return false;
	}

	if(p < 0 || p > curLen){
		cout<<"Insertion point is illegal"<<endl;
		return false;
	}

	for(i = curLen; i > p; i--){
		aList[i] = aList[i-1];
	}
	aList[p] = value;
	curLen++;
	return true;
}

//delete

template <class T> 
bool arrList<T>::deleteNode(const int p){
	int i;
	if(curLen <= 0){
		cout<<"No element to delete"<<endl;
		return false; 
	}
	if(p < 0 || p > (curLen - 1)){
		cout<<"deletion is illegal"<<endl;
		return false;
	}

	for(i = p; i < curLen-1;i++){
		aList[i] = aList[i+1];
	}
	curLen--;
	return true;
}

int main() {
	return 0;
}