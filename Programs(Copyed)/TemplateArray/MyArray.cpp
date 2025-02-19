#include<stdlib.h>
#include<iostream>
using namespace std;

template<class T>
class Myarray {
public:
	Myarray(int capacity) {                   //有参构造
		this->capacity = capacity;
		this->a_size = 0;
		this->p = new T[this->capacity]; //堆区开辟数组,返回的指针由 this->p接收
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

	void Push_Back(const T& val) {
		if (this->capacity == this->a_size) { return; }
		this->p[this->a_size] = val;  //头指针位移至尾，插入元素
		this->a_size++;
	}

	void Pop_Back() {
		if (this->a_size == 0) { return; }
		this->a_size--;//减小长度的方式删除尾素
	}

	T& operator[](int index) {  //[]重载,实现通过数组下标访问元素 //返回值类型为T,且使用引用&，使其可以作为=左值存在
		return this->p[index];
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