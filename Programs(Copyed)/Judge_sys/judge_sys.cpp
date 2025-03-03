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
		string name = "选手";
		name += namecore[i];
		int score = 0;
		Person p= Person(name, score); //初始化

		v.push_back(p); //选手放入vector容器
	}
}

void setScore(vector<Person>& v) {
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		deque<int> d;
		for (int i = 0; i < 10; i++) {
			int score =  rand()%40 + 60;

			d.push_back(score); //成绩放入deque容器
		}
		sort(d.begin(), d.end());
		d.pop_back();
		d.pop_front();         //删除极值
		int sum = 0;
		for (deque<int>::iterator it = d.begin(); it != d.end(); it++) {
			sum += (*it);
		}
		int score = sum / d.size();  //获取平均分
		(*it).c_Score = score;  //录入成绩
		
		
			cout << it->c_Name<< "得分为：" << it->c_Score << endl;
			
	}
}

int main() {
	vector<Person> v;
	createPerson(v);
	setScore(v);

}