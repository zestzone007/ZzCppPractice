/**
 * 有n阶楼梯，一次只能走1阶 2阶 或 3阶，请问到达n阶楼梯总共有多少种走法
 *1.dp[i] 的定义: 到达i阶楼梯，总共有dp[i]中走法
 *2.递推公式为 dp[i] = dp[i - 1] + dp[i -2] + dp[i - 3];
 *3.初始化dp数组：dp[1] = 1, dp[2] = 2, dp[3] = 4;
 *4.遍历方向 从1 到 n
 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    cout << dp[n] << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")