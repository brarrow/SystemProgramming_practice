#include <iostream>

struct Keeper
{
	std::ostream &stream;
	std::ios::fmtflags flag;
	char done;
	Keeper(std::ostream &stream): stream(stream)
	{
		flag = stream.flags();
		done = stream.fill();
	}
	~Keeper()
	{
		stream.flags(flag);
		stream.fill(done);
	}
};
