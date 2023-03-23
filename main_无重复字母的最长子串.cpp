
/**
 * 示例 1:
输入: s = "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:
输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:
输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。请注意，你的答案必须是 子串 的长度，"pwke"
是一个子序列，不是子串。
*/
#include <iostream>
#include <string>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

//遍历暴力解法 时间复杂度O(n2)
int getMaxUniqueSubLen(const string& str)
{
    int maxSubLen = 0;
    set<char> charSet;
    int strLen = str.length();
    for (int i = 0; i < strLen; i++) {
        int curCount = 0;
        for (int j = i; j < strLen; j++) {
            auto itor = charSet.find(str[j]);
            if (itor != charSet.end()) {
                break;
            } else {
                charSet.emplace(str[j]);
                curCount++;
            }
        }
        charSet.clear();
        maxSubLen = max(maxSubLen, curCount);
    }
    return maxSubLen;
}

//滑动窗口解法 时间复杂度O(n)
int getMaxUniqueSubLenBySlidingWindow(const string& str)
{
    int maxSubLen = 0;
    set<char> charSet;
    queue<char> charQueue;
    int strLen = str.length();
    for (int i = 0; i < strLen; i++) {
        if (charSet.find(str[i]) == charSet.end()) {
            charSet.emplace(str[i]);
            charQueue.push(str[i]);
        } else {
            int curSubLen = charQueue.size();
            maxSubLen = max(maxSubLen, curSubLen);
            char top = charQueue.front();
            while (top != str[i]) {
                charQueue.pop();
                top = charQueue.front();
            }
            charQueue.pop();
            charQueue.push(str[i]);
        }
    }
    return maxSubLen;
}

int main()
{
    string str;
    while (cin >> str) {
        cout << getMaxUniqueSubLenBySlidingWindow(str) << endl;
    }
    return 0;
}