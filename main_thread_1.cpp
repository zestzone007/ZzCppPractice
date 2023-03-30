/**
 * 下面示例展示thread的两种启动方式
 */
#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <chrono>

void detachFunc(int num)
{
    std::cout << "detach thread exec num = " << num << std::endl;
}

/**
 * 使用RAII(资源获取即初始化)等待线程完成
 *
 */
class thread_guard {
    std::thread& t;

public:
    explicit thread_guard(std::thread& t_) : t(t_) {}
    ~thread_guard()
    {
        if (t.joinable()) {
            t.join(); // thread_gurad 析构时调用join
        }
    }
    thread_guard(thread_guard const&) = delete;            // 显示删除构造函数
    thread_guard& operator=(thread_guard const&) = delete; //// 显示删除赋值运算符
};

int main()
{
    std::thread joinThread([]() -> void { std::cout << "join thread exec" << std::endl; });
    joinThread.join(); //加入式启动，将block主线程，直到自己执行完成
    std::cout << "joinThread joinable = " << joinThread.joinable() << std::endl;
    std::thread detachThread(detachFunc, 6);
    detachThread.detach(); //分离式启动，将脱离主线程
    std::mutex mainMutex;
    std::unique_lock uLock { mainMutex };
    std::condition_variable cv;
    std::chrono::milliseconds m1(1000 * 2); //毫秒
    cv.wait_for(uLock, m1);                 //锁住主线程，2秒后解锁，为了打印 detachThrea的内容
    return 0;
}