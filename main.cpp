/**
 * 零钱兑换
 *   给定不同⾯额的硬币和⼀个总⾦额。写出函数来计算可以凑成总⾦额的硬币组合数。假设每
⼀种⾯额的硬币有⽆限个。

⽰例 1:
输⼊: amount = 5, coins = [1, 2, 5]
输出: 4

解释: 有四种⽅式可以凑成总⾦额:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

⽰例 2:
输⼊: amount = 3, coins = [2]
输出: 0

解释: 只⽤⾯额2的硬币不能凑成总⾦额3。

⽰例 3:
输⼊: amount = 10, coins = [10]
输出: 1

注意，你可以假设：
0 <= amount (总⾦额) <= 5000
1 <= coin (硬币⾯额) <= 5000
硬币种类不超过 500 种
结果符合 32 位符号整数
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

int main()
{
    std::multiset<int> set1 = { 1, 1, 2, 2, 3 };
    std::multiset<int> set2 = { 1, 2, 1, 2, 3 };
    bool result = std::equal(set1.begin(), set1.end(), set2.begin());
    std::cout << result;
    return 0;
}