#include<stdlib.h>
#include<string>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;
/*����㣺δ���Ǵʵ�wordDict�е���֮����ܴ����Ӵ���ϵ����s:aaaaaaaaa wordDict:aaaaa,aa������dp��������ȷ(ֻ��ʹ��aa)���޷�����ȷ�ķ�ʽ��ȫƥ���ַ���s*/
/*
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        int m = wordDict.size();
        vector<int> dp(n, 0);  //��¼��λ֮ǰ��ƥ���Ӵ���

        if (n == 1) {
            for (int i = 0; i < m; i++) {
                if (s == wordDict[i]) return true;
            }
            return false;
        }

        int head = 0; int end = 0;    //headָ�����Ӵ�ͷ��endָ����һ���Ӵ�β
        for (int i = head; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s.substr(head, i + 1 - head) == wordDict[j]) {
                    dp[i] = i + 1 - head + dp[end];   //���۳� =���Ӵ���+֮ǰƥ���Ӵ��۳�
                    end = i;
                    head = i + 1;
                }
            }
        }
        if (dp[n - 1] == n) return true;

        return false;
    }
};
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        multiset<string> dict(wordDict.begin(), wordDict.end()); // ���ֵ�������룬��ÿ����ʵ�(����)
        vector<bool> dp(n + 1, false);  //�ַ����ָ��i,  dp[i]��ʾs��ǰi���ַ��ܷ񱻳ɹ��ָ�true/false
        dp[0] = true; // ���ַ���

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) { //�����ָ��
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {   //find()���ص��ǵ��������ڴʵ��в����Ӵ��� j�ŷָ��ɷָ��Ҵ���ƥ���Ӵ�
                    dp[i] = true; //��Ч�ָ��
                    break;
                }
            }
        }

        return dp[n];
    }
};