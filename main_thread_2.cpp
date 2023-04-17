/**
 * 下面示例展示向线程函数传递参数
 */
#include <iostream>
#include <thread>
#include <string>

void f(int count, std::string const& s)
{
    for (int j = 0; j < count; j++) {
        std::cout << j << " " << s << std::endl;
    }
}

/**
void update_data_for_widget(widget_id w,widget_data& data); // 1
void oops_again(widget_id w)
{
widget_data data;
std::thread t(update_data_for_widget,w,data); // 2
display_status();
t.join();
process_widget_data(data); // 3
}
虽然update_data_for_widget 1的第二个参数期待传入一个引用，但是 std::thread 的构造函
数2并不知晓；构造函数无视函数期待的参数类型，并盲目的拷贝已提供的变量。当线程调用
update_data_for_widget函数时，传递给函数的参数是data变量内部拷贝的引用，而非数据本
身的引用。因此，当线程结束时，内部拷贝数据将会在数据更新阶段被销毁，且
process_widget_data将会接收到没有修改的data变量 3。使用 std::bind ，就可以解决这个
问题，使用 std::ref 将参数转换成引用的形式。
std::thread t(update_data_for_widget,w,std::ref(data));
*/

void oops(int count, int some_param)
{
    // 需要特别要注意，当指向动态变量的指针作为参数传递给线程的情况
    char buffer[1024];
    sprintf(buffer, "%i", some_param);
    // buffer是一个指针变量，指向本地变量，然后本地变量通过buffer传递到新线程中
    // 函数有很大的可能会在字面值转化成std::string对象之前崩溃，
    // 因为oops函数执行完成后，buffer所指空间会出栈回收。
    //  std::thread t(f, count, buffer);
    // 解决办法就是在传递到std::thread 构造函数之前就将字面值转化为std::string对象
    std::thread t(f, count, std::string(buffer));
    t.detach();
}

int main()
{
    oops(30, 38);
    return 0;
}