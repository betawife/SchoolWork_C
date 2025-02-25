#include<stdlib.h>
#include<iostream>
#include<string>
using namespace std;

void test01() {
	string email;
	cout << "please typing your email to create new account:" << endl;
	cin >> email;
	int pos = email.find("@");
	string username = email.substr(0, pos);
	cout << "welcome to our communtiy," << username << "!" << endl;
}

int main() {
	test01();
}