#include <thread>
#include <iostream>

using namespace std;

int main() {
    // Lambda函数
    auto fun = [](int x) {
        while (x-- > 0) {
            cout << x << " ";
        }
        cout << endl;
    };
    thread t1(fun, 10);

    // 也可以写成下面：
    std::thread t2([](int x) {
        while (x-- > 0) {
            cout << x << " ";
        }
        cout << endl;
    }, 11);
    t1.join();
    t2.join();
    return 0;
}