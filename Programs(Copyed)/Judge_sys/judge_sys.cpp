#include<stdlib.h>
#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
#include<string>

using namespace std;

class Person{
public:
	string c_Name;
	int c_Score;
	Person(string name,int score) {
		this->c_Name = name;
		this->c_Score = score;
	}
};

void createPerson(vector<Person>& v)
{
	string namecore = "ABCDEF";
	for (int i = 0; i < 6; i++) {
		string name = "ѡ��";
		name += namecore[i];
		int score = 0;
		Person p= Person(name, score); //��ʼ��

		v.push_back(p); //ѡ�ַ���vector����
	}
}

void setScore(vector<Person>& v) {
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		deque<int> d;
		for (int i = 0; i < 10; i++) {
			int score =  rand()%40 + 60;

			d.push_back(score); //�ɼ�����deque����
		}
		sort(d.begin(), d.end());
		d.pop_back();
		d.pop_front();         //ɾ����ֵ
		int sum = 0;
		for (deque<int>::iterator it = d.begin(); it != d.end(); it++) {
			sum += (*it);
		}
		int score = sum / d.size();  //��ȡƽ����
		(*it).c_Score = score;  //¼��ɼ�
		
		
			cout << it->c_Name<< "�÷�Ϊ��" << it->c_Score << endl;
			
	}
}

int main() {
	vector<Person> v;
	createPerson(v);
	setScore(v);

}