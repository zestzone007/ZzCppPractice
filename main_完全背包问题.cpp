/**
 * 完全背包
 *   有N件物品和⼀个最多能背重量为W的背包。第i件物品的重量是weight[i]，得到的价值是
 * value[i] 。每件物品都有⽆限个（也就是可以放⼊背包多次），求解将哪些物品装⼊背包⾥
 * 物品价值总和最⼤。
 *
    输入说明：
    第一行输入 N W
    第2行到N+1行 输入 第i 件物品的重量和价值
    weight[i] value[i]

    输出该背包能背的最大价值

    示例：
    输入
    3 4
    1 15
    3 20
    4 30

    最大价值为 四个1 15 X 4 = 60
    输出
    60

    dp[i] 数组的含义 当包容量为i时，其装的最大价值为dp[i]
    递推公式：dp[j] = max(dp[j -1], dp[j - weight[i]] + value[i])
 */

#include <iostream>
#include <vector>

int main()
{
    int N;
    int W;
    std::cin >> N >> W;
    std::vector<int> weights;
    std::vector<int> values;
    for (int i = 0; i < N; i++) {
        int itemWeight;
        int itemValue;
        std::cin >> itemWeight >> itemValue;
        weights.push_back(itemWeight);
        values.push_back(itemValue);
    }
    std::vector<int> dp(W + 1, 0);
    // 先遍历物品， 再遍历背包
    for (int i = 0; i < N; i++) {
        for (int j = weights[i]; j <= W; j++) {
            dp[j] = std::max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }
    std::cout << dp[W] << std::endl;
    return 0;
}