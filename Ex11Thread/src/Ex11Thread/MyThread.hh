#include <sched.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <system_error>

class MyThread
{
  protected:
    pid_t pid;
    size_t stack_size;
    char *stack;
    void *stack_end;

  public:
    MyThread(int (*f)(void *args))
    {
        stack_size = 10240;
        stack = new char[stack_size];
        stack_end = stack + stack_size;

        if ((pid = clone(f, stack_end, CLONE_VM | CLONE_FS | CLONE_FILES | CLONE_SIGHAND | SIGCHLD, 0)) == -1)
        {
            throw std::system_error(errno, std::generic_category());
        };
    }

    void join()
    {
        if ((waitpid(pid, (new int(0)), 0)) == -1)
        {
            throw std::system_error(errno, std::generic_category());
        }
    }

    bool joinable() { return (pid > 0 && kill(pid, 0) == 0) ? true : false; }

    pid_t get_id() { return pid; }

    void swap(MyThread &thread)
    {
        pid_t newPid = thread.pid;
        thread.pid = pid;
        pid = newPid;
    }

    MyThread &operator=(MyThread &&thread)
    {
        this->swap(thread);
        return *this;
    }

    ~MyThread()
    {
        kill(pid, SIGTERM);
        delete[] stack;
    }
};
