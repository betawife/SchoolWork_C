#include<stdlib.h>
#include<string>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;
/*错误点：未考虑词典wordDict中单词之间可能存在子串关系，如s:aaaaaaaaa wordDict:aaaaa,aa；导致dp计数不正确(只会使用aa)，无法以正确的方式完全匹配字符串s*/
/*
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        int m = wordDict.size();
        vector<int> dp(n, 0);  //记录该位之前的匹配子串长

        if (n == 1) {
            for (int i = 0; i < m; i++) {
                if (s == wordDict[i]) return true;
            }
            return false;
        }

        int head = 0; int end = 0;    //head指向新子串头，end指向上一个子串尾
        for (int i = head; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s.substr(head, i + 1 - head) == wordDict[j]) {
                    dp[i] = i + 1 - head + dp[end];   //新累长 =该子串长+之前匹配子串累长
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
        multiset<string> dict(wordDict.begin(), wordDict.end()); // 将字典排序插入，获得拷贝词典(有序)
        vector<bool> dp(n + 1, false);  //字符串分割点i,  dp[i]表示s的前i个字符能否被成功分割true/false
        dp[0] = true; // 空字符串

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) { //遍历分割点
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {   //find()返回的是迭代器，在词典中查找子串； j号分割点可分割且存在匹配子串
                    dp[i] = true; //有效分割点
                    break;
                }
            }
        }

        return dp[n];
    }
};