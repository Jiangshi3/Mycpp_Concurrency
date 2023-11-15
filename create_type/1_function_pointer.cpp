#include <iostream>
#include <thread>
using std::cout, std::endl, std::thread;

void func(int x){
    while(x>=0){
        cout << x << " ";
        x--;
    }
    cout << endl;
}


int main(){
    thread t1(func, 10);
    thread t2(func, 10);

    if(t1.joinable()){
        t1.join();
    }
    t2.join();

    return 0;
}