#include <iostream>
#include<vector>
using namespace std;

// �ж�һ�������Ƿ��Ǻ�����żλΪż����λΪ�棩
bool isGoodNumber(int num) {
    vector<int> v;// ���ڴ洢���ֵĸ���λ��
    
    // �����ַֽ�ɸ���λ��
    while (num > 0 ) {
        v.push_back(num % 10);
        num /= 10;
    }

    // �����λ��żλ�Ƿ��������
    for (int i = 0; i < v.size(); i++) {
        if (i % 2 == 0 && v[i] % 2 == 0) return false;   //��λ��ż��
        if (i % 2 != 0 && v[i] % 2 != 0) return false;   //żλ������
    }
    return true;        //��ѭ����������û�з���false��˵���Ǻ���������true
}

int main() {
    int n;
    cout << "������һ������: ";
    cin >> n;

    int goodNumberCount = 0;

    for (int i = 1; i <= n; ++i) {
        if (isGoodNumber(i)) {
            goodNumberCount++;
        }
    }

    cout << "1��" << n << "�ĺ���������: " << goodNumberCount << endl;

    return 0;
}
