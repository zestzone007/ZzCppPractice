/**
 * leetcode 739
 * 给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i
天，下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。

 

示例 1:

输入: temperatures = [73,74,75,71,69,72,76,73]
输出: [1,1,4,2,1,1,0,0]
示例 2:

输入: temperatures = [30,40,50,60]
输出: [1,1,1,0]
示例 3:

输入: temperatures = [30,60,90]
输出: [1,1,0]
 

提示：

1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100
*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

//使用单调栈，所谓单调栈就是栈里的元素是单调递增或递减 ，多用于求数组内的间距的问题
int main()
{                       // 1   1  4   2   1    1   0  0
    vector<int> temps = { 73, 74, 75, 71, 69, 72, 76, 73 };
    vector<int> results(temps.size(), 0);
    stack<int> indexStack;
    int tempsLen = temps.size();

    for (int i = 0; i < tempsLen; i++) {
        if (indexStack.empty()) {
            indexStack.push(i);
        } else {
            int top = indexStack.top();

            if (temps[i] <= temps[top]) {
                indexStack.push(i);
            } else {
                while (!indexStack.empty() && temps[i] > temps[top]) {
                    results[top] = i - top;
                    indexStack.pop();
                    if (!indexStack.empty()) {
                        top = indexStack.top();
                    }
                }
                indexStack.push(i);
            }
        }
    }
    for (auto i : results) {
        cout << i << " ";
    }
    cout << "main end" << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")