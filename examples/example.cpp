// Copyright Davydov Nikolay 2021
#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>
#include "lock_guard.hpp"

std::mutex mtx;

void foo() {
    std::this_thread::sleep_for(std::chrono::seconds(3));
    my_lock_guard::lock_guard<std::mutex> lock(mtx);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << std::this_thread::get_id() << "\n";
}

int main() {
    std::thread t1(foo);
    std::thread t2(foo);

    t1.join();
    t2.join();
    exit(EXIT_SUCCESS);
}
