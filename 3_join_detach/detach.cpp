/**
 * 这用于从父线程分离新创建的线程
 * 在分离线程之前，请务必检查它是否可以joinable，
 * 否则可能会导致两次分离，并且双重detach()将导致程序终止
 * 如果我们有分离的线程并且main函数正在返回，那么分离的线程执行将被挂起;
 * 在C++中，如果一个线程是分离的（detached），而主线程（main函数所在的线程）正在返回，那么主线程的结束不会等待分离线程的结束。
    主线程会继续执行其余的清理工作，然后直接退出，而不等待分离线程的执行完成。
    这样做的原因是为了确保主线程的执行不会受到分离线程的阻塞，使得程序可以正常退出
*/
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std;

void run(int count) {
    while (count-- > 0) {
        cout << count << endl;
    }
    std::this_thread::sleep_for(chrono::seconds(3));
}

int main() {
    thread t1(run, 10);
    cout << "main()" << endl;
    t1.detach();
    if(t1.joinable()){
        cout << "不能双重detach(进不来这个if)" << endl;
        t1.detach();
    }
    
    cout << "main() after" << endl;
    return 0;
}