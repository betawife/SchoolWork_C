#include<stdlib.h>
#include<string>
using namespace std;

int maxScore(string s) {
    int n = s.length();
    int max_score = INT_MIN; // 初始化为最小整数值
    int left_zeros = 0, right_ones = 0;

    // 先计算整个字符串中 '1' 的数量
    for (char c : s) {
        if (c == '1') right_ones++;
    }
    //从左至右遍历字符串，遇0加left_zeros，遇1减right_ones;             遍历到哪，左子串就算取到哪；可以同时实现遍历和左右分组
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
