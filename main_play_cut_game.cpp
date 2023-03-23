#include <iostream>
#include <vector>
using namespace std;

void findMaxAndSum(const vector<int>& nums, int& max, int& sum)
{
    max = nums[0];
    for (int num : nums) {
        if (num > max) {
            max = num;
        }
        sum += num;
    }
}

int main()
{
    int goalSum = 0;
    int numCount = 0;
    vector<int> nums;
    cin >> goalSum >> numCount;
    for (int i = 0; i < numCount; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    int max = 0;
    int curSum = 0;
    findMaxAndSum(nums, max, curSum);
    vector<int> cutCounts(numCount, 0);
    if (curSum <= goalSum) {
        cout << "[]";
    } else {
        while (curSum > goalSum) {
            max--;
            int cutCount = 0;
            for (int i = 0; i < numCount; i++) {
                if (nums[i] > max) {
                    cutCount++;
                    cutCounts[i]++;
                }
            }
            curSum = curSum - cutCount;
        }
        cout << "[";
        for (int i = 0; i < numCount; i++) {
            cout << cutCounts[i];
            if (i != numCount - 1) {
                cout << ",";
            }
        }
        cout << "]";
    }

    cout << "main end" << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")