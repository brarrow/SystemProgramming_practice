#include <vector>

template <typename T>
void mergeSort(T left, T right)
{
    if (left + 1 == right)
        return;

    T center = left + (right - left) / 2;

    mergeSort(left, center);
    mergeSort(center, right);

    T lb = left;
    T rb = center;

    std::vector<typename std::iterator_traits<T>::value_type> arrayIt;

    while (lb != center || rb != right)
        if (lb == center)
            while (rb != right)
                arrayIt.push_back(*rb++);
        else if (rb == right)
            while (lb != center)
                arrayIt.push_back(*lb++);
        else if (*lb < *rb)
            arrayIt.push_back(*lb++);
        else
            arrayIt.push_back(*rb++);
    lb = left;
    rb = arrayIt.begin();
    while (lb != right)
        *lb++ = *rb++;
}