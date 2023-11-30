#include <iostream>
#include <thread>
#include <mutex>
using std::cout;
using std::endl;
using std::thread;

volatile int counter = 0;
std::mutex mtx;

void attempt_10k_increases () {
    for (int i=0; i<10000; ++i) {
        // 这里用try_lock()counter值在波动；用lock()的话，counter等于10w
        if (mtx.try_lock()) {   // only increase if currently not locked:
              ++counter;
              mtx.unlock();
        }
        // mtx.lock();
        // ++counter;
        // mtx.unlock();
   }
}

int main(){
    thread threads[10];
    for(int i=0;i<10;i++){
        threads[i] = thread(attempt_10k_increases);
    }
    for(auto& th:threads) 
        th.join();

    std::cout << counter << " successful increases of the counter.\n";

    return 0;
}
