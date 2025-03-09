#include<stdlib.h>
#include<list>
#include<iostream>

using namespace std;

class Person {                            //�Զ�����
public: string name;
	  float height;
	  int age;
	  Person(string name, float height,int age) {
		  this->name = name;
		  this->height = height;
		  this->age = age;
	  }
};

bool compare(Person &p1,Person& p2)       //�Զ����������
{
	if (p1.age != p2.age)return p1.age > p2.age;
	else { return p1.height > p2.height; }
}

void test01() {
	list<Person> L;
	Person p1("����",175.5,18);
	Person p2("����", 168,19);
	Person p3("����", 171,20);
	Person p4("����", 190,18);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);

	L.sort(compare);                      //����

	for (list<Person>::iterator it = L.begin(); it != L.end(); it++) {
		cout << "������" << it->name << "���䣺" << it->age << "��ߣ�" << it->height<<endl;
	}
}

int main() {
	test01();
	return 0;
}