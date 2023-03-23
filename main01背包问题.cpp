/**
 *
 * 题目描述
 * 小明每周上班都会拿到自己的工作清单，工作清单内包含 n 项工作，每项工作都有对应的耗时时间（单位 h）和报酬，
 * 工作的总报酬为所有已完成工作的报酬之和，那么请你帮小明安排一下工作，保证小明在指定的工作时间内工作收入最大化。
 *
 * 输入描述
 * 输入的第一行为两个正整数 T，n。
 * T 代表工作时长（单位 h， 0 < T < 1000000），
 * n 代表工作数量（ 1 < n ≤ 3000）。
 * 接下来是 n 行，每行包含两个整数 t，w。
 * t 代表该工作消耗的时长（单位 h， t > 0），w 代表该项工作的报酬。
 *
 * 输出描述
 * 输出小明指定工作时长内工作可获得的最大报酬。
 *
 * 用例
 * 输入	40 3
 * 20 10
 * 20 20
 * 20 5
 * 输出	30
 * 说明	无
*/

#include <iostream>
#include <vector>
using namespace std;

//一维数组实现01背包的遍历
/**
 * 1.全部数组元素初始化为0
 * 2.递推dp[i]的含义：当工作时长为i时，dp[i]为其获得的最大报酬
 * 3.递推公式:dp[i] = max(dp[i],dp[i - time[i]] + salary[i]])
 * 4.遍历方向：先遍历工作，再倒序遍历工作时长
 */
int main()
{
    vector<int> time;   //记录每项工作消耗的时长
    vector<int> salary; //记录每项工作获得的报酬
    int myTime;         //本周的工作时长
    int workCount;      //工作数目
    cin >> myTime >> workCount;
    for (int i = 0; i < workCount; i++) {
        int itemTime;
        int itemSalary;
        cin >> itemTime >> itemSalary;
        time.push_back(itemTime);
        salary.push_back(itemSalary);
    }
    vector<int> dp(myTime + 1, 0);
    for (int i = 0; i < workCount; i++) {
        for (int j = myTime; j >= time[i]; j--) {
            dp[j] = max(dp[j], dp[j - time[i]] + salary[i]);
        }
    }
    cout<<dp[myTime];
    return 0;
}
// 64 位输出请用 printf("%lld")