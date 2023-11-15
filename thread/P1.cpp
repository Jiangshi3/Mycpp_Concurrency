#include <iostream>
#include <thread>
using namespace std;


namespace s1{
    void fun(){
        for(int j=0;j<10;++j){
            cout << "子线程j= " << j << endl;
        }
        cout << endl;
    }

    //detach()  分离
    void tests1(){
        cout << "main主线程begin" << endl;
        thread f1(fun);
        f1.detach();
        //f1.join();

        cout << "主线程 1" << endl;
        cout << "主线程 2" << endl;
        cout << "主线程 3" << endl;
        cout << "主线程 4" << endl;
        cout << "主线程 5" << endl;
    }
}

namespace s2{
    //类作为线程函数
    class A{
    public:
        // 类A，其 operator() 函数可以被当做函数对象使用
        void operator()(){
            cout << "线程A" << endl;
            cout << "get_id:" << this_thread::get_id() << endl;
        }
    };

    void tests2(){
        cout << "test begin" << endl;
        A a;
         thread th(a);
        /*
        thread th(A()); 
        它会被解释为一个函数声明而不是一个对象的初始化。为了避免这个问题，可以使用额外的括号来明确指定它是一个对象的初始化而不是函数声明;
        */
        //thread th((A()));    
        //thread th(std::move(A()));
        if(th.joinable()){
            th.join();
        }
        cout << "test end" << endl;
    }
}

int main(){
    s2::tests2();
    return 0;
}

