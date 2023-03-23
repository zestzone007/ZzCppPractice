#include <cstdio>
#include <cstdint>

#ifndef PRINT_LN
#define println(fmt, ...) printf(fmt "\n", ##__VA_ARGS__)
#endif


class Parent {
public:
    Parent() = default;
    //最佳实践 需将父类析构函数写为virtual, 不然父类的指针指向的实体是子类时，delete 该指针时 将不执行子类的析构函数，这将很有可能导致内存泄露
    virtual ~Parent() = 0;//由于所有对象析构时，最后都会调用其基类的析构函数，所以基类的析构函数必须有定义。纯虚析构函数也不例外。
                          //所以，必须为基类的纯虚析构函数提供一个定义，否则，链接器会报错。
};

class SubClass : public Parent {
public:
    SubClass() = default;
    ~SubClass();
};

Parent::~Parent()
{
    println("Parent destruct");
}

SubClass::~SubClass()
{
    println("SubClass destruct");
}



int main(int argc, char** argv)
{
    println("main start");
    Parent * p = new SubClass();
    delete p;
    return 0;
}