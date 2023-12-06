#include <iostream>
#include <cstring>
using namespace std;

int main(){
    // const char* source="hello world";
    // char* ptr1 = new char[sizeof(source)+1];
    // strcpy(ptr1, source);
    // cout << ptr1 << endl;
    // delete [] ptr1;

    int* ptr = nullptr;  // 表示该指针当前不指向任何有效的内存地址
    *ptr = 100;  //运行时出错
    
    return 0;
}