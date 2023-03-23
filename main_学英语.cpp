/**
 * 描述
Jessi初学英语，为了快速读出一串数字，编写程序将数字转换成英文：

具体规则如下:
1.在英语读法中三位数字看成一整体，后面再加一个计数单位。从最右边往左数，三位一单位，例如12,345 等
2.每三位数后记得带上计数单位 分别是thousand, million, billion.
3.公式：百万以下千以上的数 X thousand X, 10亿以下百万以上的数：X million X thousand X, 10 亿以上的数：X billion X
million X thousand X. 每个X分别代表三位数或两位数或一位数。
4.在英式英语中百位数和十位数之间要加and，美式英语中则会省略，我们这个题目采用加上and，百分位为零的话，这道题目我们省略and

下面再看几个数字例句：
22: twenty two
100:  one hundred
145:  one hundred and forty five
1,234:  one thousand two hundred and thirty four
8,088:  eight thousand (and) eighty eight (注:这个and可加可不加，这个题目我们选择不加)
486,669:  four hundred and eighty six thousand six hundred and sixty nine
1,652,510:  one million six hundred and fifty two thousand five hundred and ten

说明：
数字为正整数，不考虑小数，转化结果为英文小写；
保证输入的数据合法
关键字提示：and，billion，million，thousand，hundred。

数据范围：1 \le n \le 2000000 \1≤n≤2000000


输入描述：
输入一个long型整数

输出描述：
输出相应的英文写法

示例1
输入：
22
复制
输出：
twenty two
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <array>

using namespace std;

map<int, string> singleMap = { { 1, "one" }, { 2, "two" }, { 3, "three" }, { 4, "four" }, { 5, "five" }, { 6, "six" },
    { 7, "seven" }, { 8, "eight" }, { 9, "nine" }, { 10, "ten" }, { 11, "eleven" }, { 12, "twelve" },
    { 13, "thirteen" }, { 14, "fourteen" }, { 15, "fifteen" }, { 16, "sixteen" }, { 17, "seventeen" },
    { 18, "eighteen" }, { 19, "nineteen" }, { 20, "twenty" }, { 30, "thirty" }, { 40, "forty" }, { 50, "fifty" },
    { 60, "sixty" }, { 70, "seventy" }, { 80, "eighty" }, { 90, "ninety" } };

string getNumberText(int value, int index)
{
    bool hasAnd = (value > 100) && (value % 100 != 0);
    vector<string> numberStrs;
    if (index == 1) {
        numberStrs.push_back("thousand");
    } else if (index == 2) {
        numberStrs.push_back("million");
    } else if (index == 3) {
        numberStrs.push_back("billion");
    };

    int hundred = value / 100;
    int ten = value - hundred * 100;
    auto itor = singleMap.find(ten);
    if (itor != singleMap.end()) {
        numberStrs.push_back(itor->second);
    } else if (ten != 0) {
        int single = ten % 10;
        numberStrs.push_back(singleMap[single]);
        int trueTen = ten - single;
        numberStrs.push_back(singleMap[trueTen]);
    }
    if (hasAnd) {
        numberStrs.push_back("and");
    }
    if (hundred != 0) {
        numberStrs.push_back("hundred");
        numberStrs.push_back(singleMap[hundred]);
    }
    string result = "";
    int wordSize = numberStrs.size();
    for (int i = wordSize - 1; i >= 0; i--) {
        result += numberStrs[i];
        if (index > 0 || i > 0) {
            result += " ";
        }
    }
    return result;
}

int main()
{
    long numbers;
    cin >> numbers;
    vector<int> spiltNumbers;
    while (numbers > 0) {
        int item = numbers % 1000;
        spiltNumbers.push_back(item);
        numbers = numbers / 1000;
    }
    string result = "";
    int spiltNumbersLen = spiltNumbers.size();
    for (int i = spiltNumbersLen - 1; i >= 0; i--) {
        result += getNumberText(spiltNumbers[i], i);
    }
    cout << result << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")