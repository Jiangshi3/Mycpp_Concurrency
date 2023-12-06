#include <iostream>
#include <pthread.h>
#include <unistd.h>

void* thread_entry_funcA(void*){
    for(int i=0;i<100;++i){
        printf("thread_entry_funcA: %d\n", i);
        sleep(1);
    }
}
void* thread_entry_funcB(void*){
    for(int i=0;i<100;++i){
        printf("thread_entry_funcB: %d\n", i);
        sleep(1);
    }
}


int main(){
    pthread_t tidA, tidB;
    int ret = pthread_create(&tidA, NULL, thread_entry_funcA, NULL);
    if(ret < 0){
        perror("pthread_create");
        return 0;
    }
    ret = pthread_create(&tidB, NULL, thread_entry_funcB, NULL);
    if(ret < 0){
        perror("pthread_create");
        return 0;
    }
    pthread_join(tidA, NULL);
    pthread_join(tidB, NULL);


    return 0;
}

/*

std::thread 和 pthread_create 是在 C++ 中创建线程的两种不同的方法，它们有一些重要的区别：

C++标准库 vs POSIX库：
std::thread 是 C++11 标准引入的线程库的一部分，提供了一个高级的、面向对象的线程接口。它属于 C++ 标准库，因此在支持 C++11 及更高版本的编译器和环境中都可以使用。
pthread_create 是 POSIX 线程库的一部分，是一个更为底层的接口。它是 POSIX 标准定义的，因此在支持 POSIX 的系统上可以使用，但不是 C++ 标准的一部分。

面向对象 vs 过程式：
std::thread 提供了一个面向对象的接口，通过创建线程对象并调用其成员函数来管理线程。这样可以更容易地进行线程管理，并且在资源管理上更安全。
pthread_create 是一个过程式的接口，需要传递函数指针和参数，更接近底层的线程管理。
RAII（资源获取即初始化）：

std::thread 支持 RAII，线程对象在其生命周期结束时会自动加入（join）或分离（detach），从而避免了手动管理线程的资源。
pthread_create 创建的线程需要手动调用 pthread_join 或 pthread_detach 来释放资源。

异常处理：
std::thread 可以更方便地处理线程中的异常，异常会在线程的上下文中传播到 std::terminate。
在使用 pthread_create 时，需要手动处理线程中的异常，否则它们可能导致整个程序终止。
可移植性：

std::thread 是 C++ 标准库的一部分，因此具有更好的可移植性，可以在符合 C++11 及更高标准的平台上使用。
pthread_create 是 POSIX 标准的一部分，因此在支持 POSIX 的系统上具有良好的可移植性。
总体而言，如果您的项目使用了 C++11 或更高版本，推荐使用 std::thread，因为它提供了更高级、更安全的接口。如果您需要更底层的控制或者在不支持 C++11 的环境中工作，那么 pthread_create 可能是一个更合适的选择。

*/
