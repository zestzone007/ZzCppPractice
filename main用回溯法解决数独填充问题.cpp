/**
 * 描述
问题描述：数独（Sudoku）是一款大众喜爱的数字逻辑游戏。玩家需要根据9X9盘面上的已知数字，推算出所有剩余空格的数字，并且满足每一行、每一列、每一个3X3粗线宫内的数字均含1-9，并且不重复。
例如：
输入

输出


数据范围：输入一个 9*9 的矩阵
输入描述：
包含已知数字的9X9盘面数组[空缺位以数字0表示]

输出描述：
完整的9X9盘面数组

示例1
输入：
0 9 2 4 8 1 7 6 3
4 1 3 7 6 2 9 8 5
8 6 7 3 5 9 4 1 2
6 2 4 1 9 5 3 7 8
7 5 9 8 4 3 1 2 6
1 3 8 6 2 7 5 9 4
2 7 1 5 3 8 6 4 9
3 8 6 9 1 4 2 5 7
0 4 5 2 7 6 8 3 1
复制
输出：
5 9 2 4 8 1 7 6 3
4 1 3 7 6 2 9 8 5
8 6 7 3 5 9 4 1 2
6 2 4 1 9 5 3 7 8
7 5 9 8 4 3 1 2 6
1 3 8 6 2 7 5 9 4
2 7 1 5 3 8 6 4 9
3 8 6 9 1 4 2 5 7
9 4 5 2 7 6 8 3 1
 */

#include <iostream>
#include <vector>
#include <array>

using namespace std;

bool isValid(int x, int y, int num, const array<array<int, 9>, 9>& square)
{
    for (int i = 0; i < square.size(); i++) {
        if (square[i][y] == num) {
            return false;
        }
    }
    auto column = square[x];

    for (int j = 0; j < column.size(); j++) {
        if (column[j] == num) {
            return false;
        }
    }

    int startX = (x / 3) * 3;
    int startY = (y / 3) * 3;

    for (int i = startX; i < startX + 3; i++) {
        for (int j = startY; j < startY + 3; j++) {
            if (square[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}

bool dfs(array<array<int, 9>, 9>& square)
{
    int squareLen = square.size();
    for (int i = 0; i < squareLen; i++) {
        for (int j = 0; j < squareLen; j++) {
            if (square[i][j] == 0) {
                for (int k = 1; k <= 9; k++) {
                    if (isValid(i, j, k, square)) {
                        square[i][j] = k;
                        int result = dfs(square);
                        if (result == true) {
                            return true;
                        }
                        square[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main()
{
    array<array<int, 9>, 9> square = {};

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> square[i][j];
        }
    }
    int result = dfs(square);
    cout << endl;
    if (result) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << square[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "FAUSE" << endl;
    }
    return 0;
}
// 64 位输出请用 printf("%lld")