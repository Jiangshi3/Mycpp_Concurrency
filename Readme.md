# Readme

---

Concurrent Programming

thread(); join(); detach(); joinable(); 

### detach()
detach() 是 std::thread 类提供的一个成员函数，用于将线程和调用者分离。 一旦线程被分离，就不能再调用 join() 来等待线程的结束。分离的线程在执行完成后会自动释放资源。
### joinable()
判断是否可以使用join()或detach();
