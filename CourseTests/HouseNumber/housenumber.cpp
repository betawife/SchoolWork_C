#include<stdlib.h>
#include<iostream>
#include<set>

using namespace std;

int TwoInNum() {
	multiset<int> s;
	for (int i = 1; i <= 2020; i++) {
		if (i == 2) s.insert(i);
		if (10 <= i < 100) { int a = i / 10; int b = i % 10; s.insert(a); s.insert(b); }
		if (100 <= i < 1000) {
			int a = i / 100; int b = (i / 10) % 10; int c = i % 10; s.insert(a); s.insert(b); s.insert(c);
		}
		if (i >= 1000) {
			int a = i / 1000; int b = (i / 100) % 10; int c = (i / 10) % 10; int d = i % 10; s.insert(a); s.insert(b); s.insert(c); s.insert(d);
		}
	}
	return s.count(2);
}



int main() {
	cout << TwoInNum();
	return 0;
}