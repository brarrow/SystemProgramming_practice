#include <fstream>

template <class Head>
void _message(std::ostream &stream, const char *str, Head head)
{
    while (*str != '%')
        stream << *str++;
        
    stream << head;
    str++;
    while (*str != '\0')
        stream << *str++;
}

template <class Head, class... Tail>
void _message(std::ostream &stream, const char *str, Head head, Tail... tail)
{
    while (*str != '%')
        stream << *str++;
    stream << head;
    str++;
    _message(stream, str, tail...);
}

template <class... Args>
bool message(std::ostream &stream, const char *string, Args... args)
{
    int numStrArgs = 0;
    const char *str = string;
    while (*str != '\0')
        if (*str++ == '%')
            numStrArgs++;

    if (sizeof...(args) != numStrArgs)
        return false;

    _message(stream, string, args...);
    return true;
}
