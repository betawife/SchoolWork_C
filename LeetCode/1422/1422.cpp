#include<stdlib.h>
#include<string>
using namespace std;

int maxScore(string s) {
    int n = s.length();
    int max_score = INT_MIN; // ��ʼ��Ϊ��С����ֵ
    int left_zeros = 0, right_ones = 0;

    // �ȼ��������ַ����� '1' ������
    for (char c : s) {
        if (c == '1') right_ones++;
    }
    //�������ұ����ַ�������0��left_zeros����1��right_ones;             �������ģ����Ӵ�����ȡ���ģ�����ͬʱʵ�ֱ��������ҷ���
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '0') {
            left_zeros++;
        }
        else {
            right_ones--;
        }
        int current_score = left_zeros + right_ones;
        if (current_score > max_score) {
            max_score = current_score;
        }
    }

    return max_score;
}
