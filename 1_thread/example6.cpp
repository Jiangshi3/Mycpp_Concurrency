/*
    this_thread_id = this_thread::get_id();
    chrono::seconds();
    chrono::milliseconds();
*/

#include <iostream>
#include <thread>
#include <chrono>
using std::cout;
using std::endl;


void pause_thread(int n){
    std::thread::id this_thread_id= std::this_thread::get_id();
    cout << n << "this_thread_id: " << this_thread_id << endl;
    std::this_thread::sleep_for(std::chrono::seconds(n));
    std::cout << "pause of " << n << " seconds ended\n";    
}


int main(){
    auto main_thread_id = std::this_thread::get_id();
    cout << "main_thread_id: " << main_thread_id << endl;

    std::thread th[3];
    for(int i=0;i<3;++i){
        th[i] = std::thread(pause_thread, i+1);
    }

    // for(int i=0;i<3;++i){
    //     if(th[i].joinable())
    //         th[i].join();
    // }
    for(auto& thread : th){
        if(thread.joinable())
            thread.join();
    }

    std::cout << "All threads joined!\n";
    return 0;
}
