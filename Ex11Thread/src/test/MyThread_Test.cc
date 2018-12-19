#include <chrono>
#include <gtest/gtest.h>
#include <thread>
#include "../Ex11Thread/MyThread.hh"

int f(void *arg)
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return 0;
}

TEST(MYTHREAD, JOINFALSE)
{
    MyThread thread(f);
    
    thread.join();
    
    EXPECT_EQ(false, thread.joinable());
}

TEST(MYTHREAD, OPERATOREQUAL)
{
    MyThread thread1(f);
    pid_t pid1 = thread1.get_id();
    MyThread thread2(f);
    pid_t pid2 = thread2.get_id();

    thread1 = std::move(thread2);

    EXPECT_EQ(pid1, thread2.get_id());
    EXPECT_EQ(pid2, thread1.get_id());
}