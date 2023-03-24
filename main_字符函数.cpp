/**
    下面示例展示了<cctype>中字符相关函数的使用
 */

#include <iostream>
#include <string>
#include <cctype>

void coutBoolMsg(const char* msg, bool result)
{
    std::cout << msg ;
    if (result) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }
}

int main()
{
    char ch = 'a';
    bool isAlpha = std::isalpha(ch);
    coutBoolMsg("a isAlpha = ", isAlpha);
    char space = ' ';
    bool isSpace = std::isspace(space);
    coutBoolMsg("isSpace = ", isSpace);
    char digit8 = '8';
    bool isDigit = std::isdigit(digit8);
    coutBoolMsg("isDigit = ", isDigit);
    bool isXdigit = std::isxdigit('a');
    coutBoolMsg("isXdigit = ", isXdigit);
    bool isUpper = std::isupper('A');
    coutBoolMsg("isUpper = ", isUpper);
    bool isLower = std::islower('a');
    coutBoolMsg("isLower = ", isLower);
    bool isalnum = std::isalnum('k');
    coutBoolMsg("isalnum = ", isalnum);
    bool isCntrl = std::iscntrl('\n');
    coutBoolMsg("isCntrl = ", isCntrl);
    bool ispunct = std::ispunct(']');//不是字母 数字 空白符 或可见的控制字符吗？
    coutBoolMsg("ispunct = ", ispunct);
    bool isPrint = std::isprint('`');//是可打印的（ASCII ''..'~'）
    coutBoolMsg("isPrint = ", isPrint);
    bool isgraph = std::isgraph('&');// isalpha() || isdigit() || ispunct() 注意：不包括空格
    coutBoolMsg("isgraph = ", isgraph);
    char lower = 'a';
    char upper = std::toupper(lower);
    lower = std::tolower(upper);
    std::cout << lower << upper << std::endl;
    int i = 5;
    int s = (++i) + (i++);
    std::cout << i << std::endl;
    std::cout << s << std::endl;
    return 0;
}