/**
 * 下面示例展示转移线程所有权
 */
#include <iostream>
#include <thread>
#include <string>


void some_function(){

}

void some_other_function(){

}

int main()
{
    std::thread t1(some_function);
    std::thread t2 = std::move(t1);
    t1 = std::thread(some_other_function);
    return 0;
}