#pragma once
#include <iostream>
using namespace std;

class TimeSpan
{
	friend ostream& operator<<(ostream &outStream, const TimeSpan &dur);
	friend istream& operator>>(istream &inStream, TimeSpan &dur);

public:
	
	TimeSpan();
	TimeSpan(double s);
	TimeSpan(double m, double s);
	TimeSpan(double h, double m, double s);
	~TimeSpan();

	int getHours() const;
	int getMinutes() const;
	int getSeconds() const;

	void setSeconds();
	void setMinutes();
	void setHours();

	bool setTimes(double hours, double minutes, double seconds);
	bool setTime(int hours, int minutes, int seconds);

	TimeSpan operator+(const TimeSpan &dur) const;
	TimeSpan& operator+=(const TimeSpan &dur);
	TimeSpan operator-(const TimeSpan &dur) const;
	TimeSpan& operator-=(const TimeSpan &dur);

	void operator-();

	bool operator==(const TimeSpan &dur);
	bool operator!=(const TimeSpan &dur);



private:
	double hours, minutes, seconds;
	void reduce();

};

