#include <iostream>
#include <string>

using namespace ::std;
/**
 * @brief Numerated stream.
 *
 * Buffer that numerating each input. Delimiter is '\n'.
 *
 */
class LineNumberBuffer : public streambuf
{
  private:
    int numLine;
    streambuf *streamBuf;
    bool newStr;

  public:
    /**
    * @brief Constructor.
    *
    * Execution of the program
    * starts here.
    *
    * @param b Takes std::streambuf which elements we will number.
    *
    */
    LineNumberBuffer(streambuf *b)
    {
        numLine = 1;
        newStr = true;
        streamBuf = b;
    }

  protected:
        /**
    * @brief Overrided function. Outputing numered elements from stream. 
    *
    * Called when appears new char in stream. Delimiter is '\n'.
    *
    * @param b Takes std::streambuf which elements we will number.
    *
    */
    int_type overflow(int_type c) override
    {
        if (newStr == true)
        {
            string str = to_string(numLine++) + " ";
            streamBuf->sputn(str.data(), str.size());
            newStr = false;
        }
        if ((char)c == '\n')
            newStr = true;
        streamBuf->sputc(c);
        return c;
    }
};