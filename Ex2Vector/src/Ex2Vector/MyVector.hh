using namespace ::std;

template <typename T>

class MyVector
{
  private:
    T *elements;
    int length;

  public:
    MyVector()
    {
        length = 0;
        elements = new T[length];
    }

    MyVector(T &inp)
    {
        length = 1;
        elements = new T[length];
        elements[0] = inp;
    }

    //for copy
    MyVector(MyVector &inp) : length(inp.length)
    {
        for (int i; i < length; i++)
            elements[i] = forward(inp.elements[i]);
    }

    //for move
    MyVector(MyVector &&inp) : length(inp.length)
    {
        elements = move(inp.elements);
        inp.length = 0;
    }

    T *begin()
    {
        return &elements[0];
    }

    T *end()
    {
        return (elements + length);
    }

    int size()
    {
        return length;
    }

    void push_back(T &inp)
    {
        length++;
        T *newEls = new T[length];

        for (int i = 0; i < length - 1; i++)
            newEls[i] = (elements[i]);
        newEls[length - 1] = (inp);
        delete[] elements;
        elements = newEls;
    }

    void push_back(T &&inp)
    {
        length++;
        T *newEls = new T[length];
        for (int i = 0; i < length - 1; i++)
            newEls[i] = move(elements[i]);
        newEls[length - 1] = move(inp);
        delete[] elements;
        elements = newEls;
    }

    void pop_back()
    {
        if (length != 0)
        {
            length--;
            T *newEls = new T[length];
            for (int i = 0; i < length; i++)
                newEls[i] = elements[i];
            elements = newEls;
        }
    }

    void erase(int pos)
    {
        if (!(pos > length))
        {
            T *newEls = new T[length - 1];
            int offset = 0;
            for (int i = 0; i < length; i++)
            {
                if (i != pos - 1)
                {
                    newEls[i - offset] = elements[i];
                }
                else
                    offset++;
            }
            delete[] elements;
            elements = newEls;
            length--;
        }
    }

    T &operator[](int i)
    {
        return elements[i];
    }

    //for copy
    MyVector &operator=(const MyVector &inp)
    {
        if (this->length != 0)
            delete[] this->elements;
        length = inp.length;
        elements = new T[length];
        for (int i; i < length; i++)
            elements[i] = (inp.elements[i]);
        return *this;
    }

    //for move
    MyVector &operator=(MyVector &&inp)
    {
        this->swap(inp);
        return *this;
    }

    void swap(MyVector &inp)
    {
        T *newEls = inp.elements;
        int newSize = inp.length;
        inp.elements = elements;
        inp.length = length;
        elements = newEls;
        length = newSize;
    }

    ~MyVector()
    {
        delete[] elements;
    }
};

template <typename T>

void swap(MyVector<T> &inp1, MyVector<T> &inp2)
{
    inp1.swap(inp2);
}
