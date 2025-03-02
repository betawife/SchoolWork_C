#include<stdlib.h>
#include<iostream>
#include<vector>
using namespace std;

void test01() {
	vector<int> v;
	for (int i = 0; i < 10000; i++) {
		v.push_back(i);
	}
	cout << "capacity:" << v.capacity() << endl;
	cout << "size:" << v.size() << endl;

	v.resize(5);
	cout << "capacity:" << v.capacity() << endl;
	cout << "size:" << v.size() << endl;

	vector<int>(v).swap(v);      //ͨ��v������sizeΪ5����������Ȼ����v����;���������漴�����գ������resize��capacity���������
	cout << "capacity:" << v.capacity() << endl;
	cout << "size:" << v.size() << endl;

}

int main() {
	test01();

	return 0;
}