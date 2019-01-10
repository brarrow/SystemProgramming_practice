#include <ostream>

template <class T>
class MyIterator
{
  private:
    std::ostream *pntr;
    int index;
    int n;

  public:
    MyIterator(std::ostream &str, int ind)
    {
        pntr = &str;
        index = ind;
        n = 1;
    }

    MyIterator &operator*() { return *this; }

    MyIterator &operator=(T p)
    {
        if (n == index)
        {
            n = 1;
            *pntr << p;
        }
        else
            n++;
        return *this;
    }

    MyIterator &operator++(int i) { return *this; }

    ~MyIterator() = default;
};