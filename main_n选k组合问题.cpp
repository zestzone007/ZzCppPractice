/**
 * 回溯算法实现 n个数的集合中，取k个数，列出这些组合的问题
 * 回溯算法三步曲
 * 1 递归函数的参数定义
 * 2.确定终止条件
 * 3.单步递归的逻辑
 *
 * 回溯函数模板
 * void backtracking(参数) {
        if (终⽌条件) {
            存放结果;
        return;
        }
        for (选择：本层集合中元素（树中节点孩⼦的数量就是集合的⼤⼩）) {
            处理节点;
            backtracking(路径，选择列表); // 递归
            回溯，撤销处理结果
        }
    }
 *
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * 二维数组 result
 * 一维数组 path
 */
vector<vector<int>> result;
vector<int> path;
void dfs(int n, int k, int startIndex)
{
    if (path.size() == k) {
        result.push_back(path);
        return;
    }
    for (int i = startIndex; i <= n; i++) {
        path.push_back(i);
        dfs(n, k, i + 1);
        path.pop_back();
    }
}

int main()
{
    int n;
    int k;
    cin >> n >> k;
    dfs(n, k, 1);
    int resultLen = result.size();
    for (int i = 0; i < resultLen; i++) {
        auto path = result[i];
        int pathLen = path.size();
        cout << "{";
        for (int j = 0; j < pathLen; j++) {
            if (j > 0) {
                cout << ",";
            }
            cout << path[j];
        }
        cout << "} ";
    }
    cout << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")