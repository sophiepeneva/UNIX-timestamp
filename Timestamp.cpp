# UNIX-timestamp

#include "Timestamp.h"


Timestamp::Timestamp(unsigned long s) : stamp(s)
{}

Timestamp::Timestamp(const Timestamp& ts)
{
	Copy(ts);
}

void Timestamp::Copy(const Timestamp& ts)
{
	stamp = ts.getValue();
}

ostream& operator<<(ostream& os, const Timestamp& ts)
{
	os << "Stamp : " << ts.stamp << std::endl;
	return  os;
}

istream& operator>>(istream& in, Timestamp& ts)
{
	cout << "Input stamp value : " << endl;
	in >> ts.stamp;
	return  in;
}

void Timestamp::operator+=(unsigned long num)
{
	stamp += num;
}

Timestamp& Timestamp::operator+(unsigned long num)
{
	Timestamp t;
	t.stamp = num + stamp;
	return t;
}
