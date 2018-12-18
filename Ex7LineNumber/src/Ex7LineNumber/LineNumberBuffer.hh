using namespace ::std;
class LineNumberBuffer : public streambuf
{
  private:
    int numLine;
    streambuf *streamBuf;
    bool newStr;

  public:
    LineNumberBuffer(streambuf *b)
    {
        numLine = 1;
        newStr = true;
        streamBuf = b;
    }

  protected:
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