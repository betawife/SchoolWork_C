#include<stdlib.h>
#include<iostream>

using namespace std;

int solve() {
	int count = 0;
	for (int i = 0; i < 50; i++)        //��������
	{
		for (int j = i + 1; j < 50; j++) {   //�������ˣ��᲻�ϼ���
			if (i<=42)count++;    //������ˣ���ǰ����չ��ˣ�ͬʱҲ���ܺͺ������գ����Բ��ټ���
		}
	}
	return count;
}

int main() {
	cout << solve() << endl;
	return 0;
}