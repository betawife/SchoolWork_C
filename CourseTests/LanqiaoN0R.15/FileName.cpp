#include <iostream>
#include<vector>
using namespace std;

// 判断一个数字是否是好数（偶位为偶，奇位为奇）
bool isGoodNumber(int num) {
    vector<int> v;// 用于存储数字的各个位数
    
    // 将数字分解成各个位数
    while (num > 0 ) {
        v.push_back(num % 10);
        num /= 10;
    }

    // 检查奇位和偶位是否符合条件
    for (int i = 0; i < v.size(); i++) {
        if (i % 2 == 0 && v[i] % 2 == 0) return false;   //奇位但偶数
        if (i % 2 != 0 && v[i] % 2 != 0) return false;   //偶位但奇数
    }
    return true;        //若循环结束后仍没有返回false，说明是好数，返回true
}

int main() {
    int n;
    cout << "请输入一个数字: ";
    cin >> n;

    int goodNumberCount = 0;

    for (int i = 1; i <= n; ++i) {
        if (isGoodNumber(i)) {
            goodNumberCount++;
        }
    }

    cout << "1到" << n << "的好数个数是: " << goodNumberCount << endl;

    return 0;
}
