#include <iostream>
#include <vector>
using namespace std;

void reverseSubStr(string& str, int start, int end)
{
    if (end - start <= 0) {
        return;
    }
    int left = start;
    int right = end;
    while (right > left) {
        char tmp = str[right];
        str[right] = str[left];
        str[left] = tmp;
        left++;
        right--;
    }
}

int main()
{
    string str1;
    getline(cin, str1);
    int strLen = str1.length();
    int startPos = 0;
    for (int i = 0; i < strLen; i++) {
        if (str1[i] == ' ' || str1[i] == ',' || str1[i] == '.' || str1[i] == '?') {
            reverseSubStr(str1, startPos, i - 1);
            startPos = i + 1;
        }
    }
    cout << str1 << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")