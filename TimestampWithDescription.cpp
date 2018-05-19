# UNIX-timestamp

#include "TimestampWithDescription.h"



TimestampWithDescription::TimestampWithDescription(unsigned long s, const char* d) : Timestamp(s)
{
	description = new char[strlen(d)+1];
	strcpy_s(description, strlen(d) + 1, d);
}


TimestampWithDescription::TimestampWithDescription(const TimestampWithDescription& tsWD)
{
	Copy(tsWD);
}


TimestampWithDescription& TimestampWithDescription::operator=(const TimestampWithDescription& tsWD)
{
	if(this != &tsWD)
	{
		Destroy();
		Copy(tsWD);
	}
	return *this;
}


TimestampWithDescription::~TimestampWithDescription()
{
	Destroy();
}

void TimestampWithDescription::Destroy()
{
	delete[] description;
}


void TimestampWithDescription::Copy(const TimestampWithDescription& tsWD)
{
	setValue(tsWD.getValue());
	description = new char[strlen(tsWD.description)];
	strcpy_s(description, strlen(tsWD.description) + 1, tsWD.description);
}


void TimestampWithDescription::setDescription(const char* d)
{
	description = new char[strlen(d)];
	strcpy_s(description, strlen(d) + 1, d);
}


ostream& operator<<(ostream& os, const TimestampWithDescription& tsWD)
{
	os << (const Timestamp &)tsWD
	 << "Description : " << tsWD.description << endl;
	return os;
}

istream& operator>>(istream& in, TimestampWithDescription& tsWD)
{
	in >> (Timestamp &)tsWD;
	cout << "Enter description : " << endl;
	in >> tsWD.description;
	return  in;
}
