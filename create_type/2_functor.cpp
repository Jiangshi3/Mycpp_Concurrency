#include <iostream>
#include <thread>
using std::cout;
using std::endl;
using std::thread;

class Func{
public:
    void operator()(int x){
        while(x>=0){
            cout << x << " ";
            x--;
        }
    cout << endl;
    }
};

int main(){
    thread t1(Func(), 20);
    thread t2(Func(), 20);

    if(t1.joinable()){
        t1.join();
    }
    t2.join();

    return 0;
}