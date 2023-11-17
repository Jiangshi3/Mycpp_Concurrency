#include <iostream>
#include <thread>
#include <mutex>
using std::cout;
using std::endl;
using std::thread;


int res=0;
std::mutex m;

void func(){
    for(int i=0; i<100000; ++i){
        m.lock();
        res++;
        m.unlock();
    }
}


int main(){
    thread t1(func);
    thread t2(func);
    t1.join();
    if(t2.joinable()){
        t2.join();
    }

    cout << "res:" << res << endl;

    return 0;
}