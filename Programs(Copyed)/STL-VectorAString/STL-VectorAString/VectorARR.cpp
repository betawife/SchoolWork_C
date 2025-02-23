#include<stdlib.h>
#include<iostream>
#include<vector>
#include<String>
using namespace std;

class Phone {
public:
	Phone(string branch, int price) {
		this->branch = branch;
		this->price = price;

	}
	string getbranch() { return this->branch; }
	int getprice() { return this->price; }
public:
	string branch; 
	int price;

};

int main() {
	Phone p1("iphone", 4599);
	Phone p2("Oppo", 3699);
	Phone p3("vivo", 4399);
	
	vector<vector<Phone>> V;
	vector<Phone> v1; vector<Phone> v2;
	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	v2.push_back(p1);
	v2.push_back(p2);
	v2.push_back(p3);
	V.push_back(v1);
	V.push_back(v2);

	for (vector<vector<Phone>>::iterator iB = V.begin(); iB != V.end(); iB++) {
		
		for (vector<Phone>::iterator ib = (*iB).begin(); ib != (*iB).end(); ib++) {
			cout << "Æ·ÅÆ£º" << (*ib).getbranch() << "¼Û¸ñ:" << (*ib).getprice()<<" ";
		}
		cout << endl;
	}

}
