/**
 * 描述
给出一个字符串，该字符串仅由小写字母组成，定义这个字符串的“漂亮度”是其所有字母“漂亮度”的总和。
每个字母都有一个“漂亮度”，范围在1到26之间。没有任何两个不同字母拥有相同的“漂亮度”。字母忽略大小写。

给出多个字符串，计算每个字符串最大可能的“漂亮度”。

本题含有多组数据。

数据范围：输入的名字长度满足 1 \le n \le 10000 \1≤n≤10000

输入描述：
第一行一个整数N，接下来N行每行一个字符串

输出描述：
每个字符串可能的最大漂亮程度

示例1
输入：
2
zhangsan
lisi
复制
输出：
192
101
复制
说明：
对于样例lisi，让i的漂亮度为26，l的漂亮度为25，s的漂亮度为24，lisi的漂亮度为25+26+24+26=101.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <array>
#include <algorithm>

using namespace std;

int main()
{
    int count;
    cin >> count;
    vector<string> words;
    for (int i = 0; i < count; i++) {
        string word;
        cin >> word;
        words.push_back(word);
    }
    for (auto word : words) {
        map<char, int> charCountMap;
        for (char ch : word) {
            auto itor = charCountMap.find(ch);
            if (itor != charCountMap.end()) {
                charCountMap[ch]++;
            } else {
                charCountMap[ch] = 1;
            }
        }
        vector<pair<char, int>> charCountVector;
        for (auto item : charCountMap) {
            charCountVector.emplace_back(item.first, item.second);
        }
        sort(charCountVector.begin(), charCountVector.end(),
            [](const pair<char, int>& pair1, const pair<char, int>& pair2) -> bool {
                return pair1.second > pair2.second;
            });
        int result = 0;
        int mostCharValue = 26;
        for (auto item : charCountVector) {
            result += item.second * mostCharValue;
            mostCharValue--;
        }
        cout << result << endl;
    }
    return 0;
}
// 64 位输出请用 printf("%lld")