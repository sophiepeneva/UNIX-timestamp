# UNIX-timestamp

#pragma once
#include "Timestamp.h"
#include<iostream>
using namespace std;


class TimestampWithDescription :
	public Timestamp
{
public:
	TimestampWithDescription(unsigned long s = 0, const char* d = "NO DESCRIPTION");
	TimestampWithDescription(const TimestampWithDescription& tsWD);
	TimestampWithDescription& operator=(const TimestampWithDescription& tsWD);
	~TimestampWithDescription();

	void setDescription(const char* d);
	char* getDescription() const { return description; }

	friend ostream& operator<<(ostream& os, const TimestampWithDescription& tsWD);
	friend istream& operator>>(istream& in, TimestampWithDescription& tsWD);

private:
	void Destroy();
	void Copy(const TimestampWithDescription& tsWD);
	char * description;
};

