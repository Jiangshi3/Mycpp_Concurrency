#include <iostream>
#include <thread>
using std::cout;
using std::endl;
using std::thread;

class Base{
public:
    static void func(int x){
        while(x>=0){
            cout << x << " ";
            x--;
        }
        cout << endl;
    }
};

int main(){
    thread t(&Base::func, 10);  // static member function
    t.join();

    return 0;
}