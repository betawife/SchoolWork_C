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

	vector<int>(v).swap(v);      //通过v创建了size为5的匿名对象，然后与v互换;匿名对象随即被回收，解决了resize后capacity不变的问题
	cout << "capacity:" << v.capacity() << endl;
	cout << "size:" << v.size() << endl;

}

int main() {
	test01();

	return 0;
}