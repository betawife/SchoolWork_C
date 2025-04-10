#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_map<int, int> count;  //使用对数count存储 nums数组中每个元素出现的次数
        int max_num = 0;
        for (int num : nums) {
            count[num]++;
            if (num > max_num) {
                max_num = num;  //顺便记录nums中最大数
            }
        }

        vector<int> total(max_num + 1, 0);  //使用数组total存储 相同元素x的和    (由题意得索引不会超过max_num +1)
        for (const auto& entry : count) {
            total[entry.first] = entry.first * entry.second;
        }

        vector<int> dp(max_num + 1, 0);     //使用数组dp记录 最大获得点数       (打家劫舍问题)
        dp[0] = total[0];
        dp[1] = max(total[0], total[1]);
        for (int i = 2; i <= max_num; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + total[i]);
        }

        return dp[max_num];
    }
};

/*给你一个整数数组 nums ，你可以对它进行一些操作。

每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数。之后，你必须删除 所有 等于 nums[i] - 1 和 nums[i] + 1 的元素。

开始你拥有 0 个点数。返回你能通过这些操作获得的最大点数。*/

/* 对于元素x,当提取点数x时，所有元素值为x-1，x+1的元素都会被删除，则：x安全了，不会因其他元素被选中而删除 ，必定被选中作点数
    得出以下两点：
    1.选中x,则等效选中了所有x                 ==》将原数组转化为总和数组，每个元素代表原数组相同元素的和；total[x]=x*次数；
    2.选中x,则x-1,x+1不能被选择 ；求最大收益  ==》打家劫舍问题
*/