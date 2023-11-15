#include <iostream>
#include <thread>
using std::cout;
using std::endl;
using std::thread;

class Base{
public:
    void func(int x){
        while(x>=0){
            cout << x << " ";
            x--;
        }
        cout << endl;
    }
};

int main(){
    Base a;
    thread t(&Base::func, &a, 10);  // Non-static member function
    t.join();

    return 0;
}