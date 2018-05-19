# UNIX-timestamp

#pragma once
#include<iostream>
using namespace std;

class Timestamp
{
public:
	Timestamp(unsigned long stamp = 0);
	Timestamp(const Timestamp& ts);
	~Timestamp() {};

	unsigned long getValue() const { return stamp; };
	void setValue(unsigned long s) { stamp = s; };

	friend ostream& operator<<(ostream& os, const Timestamp& ts);
	friend istream& operator>>(istream& in, Timestamp& ts);

	void operator+=(unsigned long num);
	Timestamp& operator+(unsigned long num);
private:
	void Copy(const Timestamp& ts);
	unsigned long stamp;
};


