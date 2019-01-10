#include <vector>
#include <thread>
#include <mutex>

long unsigned int hConc = std::thread::hardware_concurrency();
std::vector<std::thread> threads{hConc};
std::mutex mutex;

template <typename T>
void mergeSortThread(T left, T right)
{
    if (left == right)
        return;

    int size = right - left;

    if (size==1)
        return;

    T center = left + (size / 2);

    long unsigned int tmpThr1 = hConc;
    long unsigned int tmpThr2 = hConc;

    if (size >= 100)
    {
        tmpThr1 = 0;
        std::lock_guard<std::mutex> locked(mutex);
        for (tmpThr1 = 0; tmpThr1 < hConc; tmpThr1++)
            if (!threads[tmpThr1].joinable())
            {
                threads[tmpThr1] = std::thread{mergeSortThread<T>, left, center};
                break;
            }

        tmpThr2 = 0;
        for (tmpThr2 = 0; tmpThr2 < hConc; tmpThr2++)
            if (!threads[tmpThr2].joinable())
            {
                threads[tmpThr2] = std::thread{mergeSortThread<T>, center, right};
                break;
            }
    }
    if (tmpThr1 == hConc)
        mergeSortThread(left, center);
    if (tmpThr2 == hConc)
        mergeSortThread(center, right);

    T lb = left;
    T rb = center;

    std::vector<typename std::iterator_traits<T>::value_type> arr;

    if (tmpThr1 < hConc)
        threads[tmpThr1].join();
    if (tmpThr2 < hConc)
        threads[tmpThr2].join();


    while (lb != center || rb != right)
        if (lb == center)
            while (rb != right)
                arr.push_back(*rb++);
        else if (rb == right)
            while (lb != center)
                arr.push_back(*lb++);
        else if (*lb < *rb)
            arr.push_back(*lb++);
        else
            arr.push_back(*rb++);
    lb = left;
    rb = arr.begin();
    while (lb != right)
        *lb++ = *rb++;
}