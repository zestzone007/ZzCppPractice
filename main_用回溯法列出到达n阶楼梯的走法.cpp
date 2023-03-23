/**
 * 有n阶楼梯，一次只能走1阶 2阶 或 3阶，请列举出所有到达n阶楼梯的走法
 *
 */

#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, vector<int>>> result;
pair<int, vector<int>> path;
int goalStep;
void dfs()
{
    int total = path.first;
    if (total >= goalStep) {
        if (total == goalStep) {
            result.push_back(path);
        }
        return;
    }
    for (int i = 1; i <= 3; i++) {
        path.second.push_back(i);
        path.first += i;
        dfs();
        path.first -= i;
        path.second.pop_back();
    }
}

int main()
{
    cin >> goalStep;
    dfs();
    for (auto item : result) {
        cout << "{";
        for (auto num : item.second) {
            cout << num << " ";
        }
        cout << "}, " << endl;
    }
    cout << "result size = " << result.size() << endl;
    cout << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")