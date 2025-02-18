#include<stdlib.h>
#include<iostream>
using namespace std;

template<class T>
class Myarray {
public:
	Myarray(int capacity) {                   //有参构造
		this->capacity = capacity;
		this->a_size = 0;
		this->p = new T[this->capacity]; //堆区开辟数组
		cout << "有参构造" << endl;
	}

	Myarray(const Myarray& arr) {             //拷贝构造
		this->capacity = arr.capacity;
		this->a_size = arr.a_size;
		//this->p = arr.p;
		this->p = new T[arr.capacity];
		for (int i = 0; i < this->a_size; i++) {  //复制arr数组
			this->p[i] = arr.p[i];
		}
		cout << "拷贝构造" << endl;
	}

	Myarray& operator=(const Myarray& arr)   //运算符重载，防止浅拷贝
	{
		if (this->p != NULL) {
			delete[] this->p;
			this->p = NULL;
			this->capacity = 0;
			this->a_size = 0;
		}
		this->capacity = arr.capacity;
		this->a_size = arr.a_size;
		this->p = new T[arr.capacity];
		for (int i = 0; i < this->a_size; i++) {
			this->p[i] = arr.p[i];
		}
		return *this;
	}

	~Myarray() {
		if (this->p != NULL) { delete[] this->p; this->p = NULL; }
		cout << "析构" << endl;
	}
private:
	T* p; //指向堆区数组
	int capacity;
	int a_size;
};

void main() {
	Myarray<int> arr1(5);
	Myarray<int>arr2(arr1);
	Myarray<int>arr3 = arr2;
}