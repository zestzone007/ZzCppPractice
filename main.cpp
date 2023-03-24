/**
 * 最长递增子序列
 * 输入一个数组，求该数组的最长递增子序列的长度
 */
#include <iostream>
#include <vector>

// 暴力遍历法求最长递增子序列
int getMaxSubQueueceLength(const std::vector<int>& nums)
{
    int maxCount = 0;
    int numsSize = nums.size();
    for (int i = 0; i < numsSize; i++) {
        int curCount = 1;
        int curMax = nums[i];
        int remainCount = numsSize - i;//剩余可能的最长递增子序列
        if (remainCount <= maxCount) { //后面找不出比这个更长的了
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
        int length = getMaxSubQueueceLength(nums);
        std::cout << length << std::endl;
    }
    return 0;
}