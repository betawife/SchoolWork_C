#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        int start = 0;  //������ʼ�±�
        int end = 0;

        for (int i = 0; i < s.size(); ++i) {        //����ÿһ��Ԫ�أ���������Ϊ�������ĵ������ĳ���
            int len1 = expandAroundCenter(s, i, i);      // �����������
            int len2 = expandAroundCenter(s, i, i + 1);  // ż���������
            int max_len = max(len1, len2);
            if (max_len > end - start) {            //max_len���ڼ�¼������start,end
                start = i - (max_len - 1) / 2;      // i�Ӽ��볤
                end = i + max_len / 2;
            }
        }

        return s.substr(start, end - start + 1);
    }

private:
    int expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;    //����
        }
        return right - left - 1;
    }
};