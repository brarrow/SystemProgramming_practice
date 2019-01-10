#include <vector>
#include <stdlib.h>

template <typename T>
bool turn90(std::vector<T> &vector, int angle)
{
    if (vector.size() > 2)
        return false;

    if (angle % 90 != 0)
        return false;

    int n = angle / 90;
    for (int i = 0; i < abs(n); i++)
    {
        T a = vector[1];
        if (n < 0)
        {
            vector[1] = vector[0];
            vector[0] = -a;
        }
        else
        {
            vector[1] = -vector[0];
            vector[0] = a;
        }
    }
    return true;
}
