/**
 * LeetCode 300: 最长递增子序列
 * 输入一个数组，求该数组的最长递增子序列的长度
 */
#include <iostream>
#include <algorithm>
#include <vector>

// 暴力遍历法求最长递增子序列
int getMaxSubQueueceLength(const std::vector<int>& nums)
{
    int maxCount = 0;
    int numsSize = nums.size();
    for (int i = 0; i < numsSize; i++) {
        int curCount = 1;
        int curMax = nums[i];
        int remainCount = numsSize - i; //剩余可能的最长递增子序列
        if (remainCount <= maxCount) {  //后面找不出比这个更长的了
            break;
        }
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[j] > curMax) {
                curMax = nums[j];
                curCount++;
            }
        }
        maxCount = std::max(maxCount, curCount);
    }
    return maxCount;
}

/**
 *
 * 动态规划 思路与算法

定义dp[i]为考虑前 i 个元素，以第 i 个数字结尾的最长上升子序列的长度，注意nums[i]
必须被选取。

我们从小到大计算dp数组的值，在计算dp[i] 之前，我们已经计算出 dp[0…i−1] 的值，则状态转移方程为：

dp[i]=max(dp[j])+1,其中0≤j<i且num[j]<num[i]

即考虑往 dp[0…i−1] 中最长的上升子序列后面再加一个nums[i]。由于
dp[j]代表nums[0…j] 中以nums[j]结尾的最长上升子序列，所以如果能从dp[j] 这个状态转移过来，那么nums[i]必然要大于
nums[j]，才能将 nums[i] 放在nums[j] 后面以形成更长的上升子序列。

最后，整个数组的最长上升子序列即所有dp[i]中的最大值。
*/
int dpFunc(const std::vector<int>& nums)
{
    int result = 1;
    int numsSize = nums.size();
    std::vector<int> dp(numsSize, 0);
    for (int i = 0; i < numsSize; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = std::max(dp[j] + 1, dp[i]);
            }
        }
        result = std::max(result, dp[i]);
    }
    return result;
}

//测试数据: 10 9 2 5 3 7 101 18
int main()
{
    int count { 0 };
    std::vector<int> nums;
    while (std::cin >> count) {
        nums.clear();
        for (int i = 0; i < count; i++) {
            int num;
            std::cin >> num;
            nums.push_back(num);
        }
        std::cout << dpFunc(nums) << std::endl;
    }
    return 0;
}