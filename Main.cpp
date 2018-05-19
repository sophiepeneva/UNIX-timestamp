# UNIX-timestamp

#include<iostream>
#include "TimestampWithDescription.h"
#include "Timestamp.h"

using namespace std;

int main() 
{
	TimestampWithDescription ts1(2,"a");
	TimestampWithDescription ts2(3, "b");
	cout << ts2 << endl;
	ts2 = ts1;
	cout << ts2 << endl;
	cin >> ts2;
	cout << ts2 << endl;
	system("pause");
}
