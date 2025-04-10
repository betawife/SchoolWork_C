#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_map<int, int> count;  //ʹ�ö���count�洢 nums������ÿ��Ԫ�س��ֵĴ���
        int max_num = 0;
        for (int num : nums) {
            count[num]++;
            if (num > max_num) {
                max_num = num;  //˳���¼nums�������
            }
        }

        vector<int> total(max_num + 1, 0);  //ʹ������total�洢 ��ͬԪ��x�ĺ�    (��������������ᳬ��max_num +1)
        for (const auto& entry : count) {
            total[entry.first] = entry.first * entry.second;
        }

        vector<int> dp(max_num + 1, 0);     //ʹ������dp��¼ ����õ���       (��ҽ�������)
        dp[0] = total[0];
        dp[1] = max(total[0], total[1]);
        for (int i = 2; i <= max_num; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + total[i]);
        }

        return dp[max_num];
    }
};

/*����һ���������� nums ������Զ�������һЩ������

ÿ�β����У�ѡ������һ�� nums[i] ��ɾ��������� nums[i] �ĵ�����֮�������ɾ�� ���� ���� nums[i] - 1 �� nums[i] + 1 ��Ԫ�ء�

��ʼ��ӵ�� 0 ����������������ͨ����Щ������õ���������*/

/* ����Ԫ��x,����ȡ����xʱ������Ԫ��ֵΪx-1��x+1��Ԫ�ض��ᱻɾ������x��ȫ�ˣ�����������Ԫ�ر�ѡ�ж�ɾ�� ���ض���ѡ��������
    �ó��������㣺
    1.ѡ��x,���Чѡ��������x                 ==����ԭ����ת��Ϊ�ܺ����飬ÿ��Ԫ�ش���ԭ������ͬԪ�صĺͣ�total[x]=x*������
    2.ѡ��x,��x-1,x+1���ܱ�ѡ�� �����������  ==����ҽ�������
*/