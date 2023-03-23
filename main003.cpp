#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> spliteStr(string src, string spliteFlagStr){
    vector<string> strings;
    
    return strings;
}

int main() {
    string str;
    getline(cin, str);
    int strLen = str.length();
    for (int i = strLen - 1; i >= 0; i--) {
        cout << str[i];
    }
    cout << endl;
}
// 64 位输出请用 printf("%lld")