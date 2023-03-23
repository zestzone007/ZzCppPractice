#include <iostream>
#include <string>
using namespace std;

void assignTest() {
    string str1{"iAmTheOriginalStr"};
    str1.assign(4, 'a');
    cout << "str1 = " << str1 << endl;
    string str2{"const_string"};
    str1.assign(str2);
    cout << "str1 = " << str1 << endl;
    str1.assign(str2, 5,3);
    cout << "str1 = " << str1 << endl;
    const char* str = "this_is_const_char*";
    str1.assign(str,5);
    cout << "str1 = " << str1 << endl;
    str1.assign({'a', 'b', 'c'});
    cout << "str1 = " << str1 << endl;
}

int main()
{
    assignTest();
    return 0;
}
// 64 位输出请用 printf("%lld")