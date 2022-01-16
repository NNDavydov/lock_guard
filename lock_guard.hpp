// Copyright Davydov Nikolay 2021

#ifndef INCLUDE_LOCK_GUARD_HPP_
#define INCLUDE_LOCK_GUARD_HPP_

#include <mutex>

namespace my_lock_guard {
    template<class Mutex>
    class lock_guard {
    private:
        Mutex& mtx_;
    public:
        explicit lock_guard(Mutex &m): mtx_(m){
            mtx_.lock();
        }
        
        lock_guard(Mutex& m, std::adopt_lock_t) :  mtx_(m) {}

        lock_guard(const lock_guard &) = delete;

        lock_guard &operator=(const lock_guard &) = delete;

        ~lock_guard(){
            mtx_.unlock();
        }
    };
}

#endif //INCLUDE_LOCK_GUARD_HPP_
