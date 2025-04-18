#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        int start = 0;  //回文起始下标
        int end = 0;

        for (int i = 0; i < s.size(); ++i) {        //遍历每一个元素，计算以其为回文中心的最大回文长度
            int len1 = expandAroundCenter(s, i, i);      // 奇数长度情况
            int len2 = expandAroundCenter(s, i, i + 1);  // 偶数长度情况
            int max_len = max(len1, len2);
            if (max_len > end - start) {            //max_len大于记录，更新start,end
                start = i - (max_len - 1) / 2;      // i加减半长
                end = i + max_len / 2;
            }
        }

        return s.substr(start, end - start + 1);
    }

private:
    int expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;    //外扩
        }
        return right - left - 1;
    }
};