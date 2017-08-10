#include "stdafx.h"
#include "TimeSpan.h"
//#include <iostream>
#include <cmath>
using namespace std;


TimeSpan::TimeSpan()
{
	hours = 0;
	minutes = 0;
	seconds = 0;
}

TimeSpan::TimeSpan(double seconds)
{
	hours = 0;
	minutes = 0;
	this->seconds = seconds;
	
	setTimes(0, 0, seconds);
}

TimeSpan::TimeSpan(double minutes, double seconds)
{
	hours = 0;
	this->minutes = minutes;
	this->seconds = seconds;

	setTimes(0, minutes, seconds);
}

TimeSpan::TimeSpan(double hours, double minutes, double seconds)
{
	this->hours = hours;
	this->minutes = minutes;
	this->seconds = seconds;

	setTimes(hours, minutes, seconds);
}

int TimeSpan::getSeconds() const
{
	return seconds;
}

int TimeSpan::getMinutes() const
{
	return minutes;
}

int TimeSpan::getHours() const
{
	return hours;
}

void TimeSpan::setSeconds()
{
}

void TimeSpan::setMinutes()
{	
	if (minutes > 0)						//checks to see if mins is positive
	{
		if (minutes - floor(minutes) != 0)	//checks to see if mins is a decimal
		{
			double temp = minutes - floor(minutes);
			seconds += temp * 60;			//adjusts seconds for the decimal in mins
			minutes -= temp;
		}
		if (seconds < 0)					//check to see if the number is seconds is negative
		{
			minutes = minutes - 1;
			seconds = 60 + seconds;			//then takes time from mins and adjusts seconds
		}
	}
		
	if (minutes < 0)						//checks to see if mins is negative
	{
		if (minutes + ceil(minutes) != 0)	//checks to see if mins has a decimal
		{
			double temp = minutes - ceil(minutes);
			seconds += temp * 60;			//adjusts seconds for thew decimal
			minutes += temp;
		}
		if (seconds > 0)					//if seconds are positive, take add a min
		{
			minutes = minutes + 1;
			seconds = seconds - 60;
		}
	}
	reduce();
}

void TimeSpan::setHours()
{
	if (hours > 0)							//checks to see if hours is positive
	{
		if (hours - floor(hours) != 0)		//checks to see if hours is a decimal
		{
			double temp = hours - floor(hours);
			minutes += temp * 60;			//adjusts seconds for the decimal in hours
			hours -= temp;
		}
		if (minutes < 0)					//check to see if the number is mins is negative
		{
			hours = hours - 1;
			minutes = 60 + minutes;			//then takes time from hours and adjusts seconds
		}
	}

	if (hours < 0)							//checks to see if hours is negative
	{
		if (hours - ceil(hours) != 0)		//checks to see if hours has a decimal
		{
			double temp = hours - ceil(hours);
			minutes += temp * 60;			//adjusts mins for thew decimal
			hours += temp;
		}
		if (minutes > 0)					//if mins are positive, take add a hour
		{
			hours = hours + 1;
			minutes = minutes - 60;
		}
	}
	reduce();
}

bool TimeSpan::setTimes(double hours, double minutes, double seconds)
{
	setMinutes();
	setHours();

	return 1;
}

bool TimeSpan::setTime(int hours, int minutes, int seconds)
{
	return 1;
}

TimeSpan TimeSpan::operator+(const TimeSpan &dur) const
{
	TimeSpan result = *this;
	result += dur;
	return result;
}

TimeSpan& TimeSpan::operator+=(const TimeSpan &dur)
{
	hours = hours + dur.hours;
	minutes = minutes + dur.minutes;
	seconds = seconds + dur.seconds;
	reduce();
	return *this;
}

TimeSpan TimeSpan::operator-(const TimeSpan &dur) const
{
	TimeSpan result = *this;
	result -= dur;
	return result;
}

TimeSpan& TimeSpan::operator-=(const TimeSpan &dur)
{
	hours = hours - dur.hours;
	minutes = minutes - dur.minutes;
	seconds = seconds - dur.seconds;
	reduce();
	return *this;
}

bool TimeSpan::operator==(const TimeSpan &dur)
{
	if ((hours == dur.hours) && (minutes == dur.minutes) && (seconds == dur.seconds))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool TimeSpan::operator!=(const TimeSpan &dur)
{
	if ((hours != dur.hours) || (minutes != dur.minutes) || (seconds != dur.seconds))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void TimeSpan::operator-()
{
	hours = -hours;
	minutes = -minutes;
	seconds = -seconds;
}

ostream& operator<<(ostream &outStream, const TimeSpan &dur)
{
	outStream << "Hours: " << dur.getHours() << " Minutes: " << dur.getMinutes() << " Seconds: " << dur.getSeconds();
	return outStream;
}

istream& operator>>(istream &inStream, TimeSpan &dur)
{
	inStream >> dur.hours >> dur.minutes >> dur.seconds;
	dur.reduce();
	return inStream;
}

TimeSpan::~TimeSpan()
{
}

void TimeSpan::reduce()
{
	while (seconds >= 60)						//if over 60 secs, add a min
	{
		seconds -= 60;
		minutes++;
	}
	while (minutes >= 60)						//if over 60 mins, add a hour
	{
		minutes -= 60;
		hours++;
	}
	while (seconds <= -60)						//if under 60 sec, minus a min
	{
		seconds += 60;
		minutes--;
	}
	while (minutes <= -60)						//if under 60 mins, minus a hour
	{
		minutes += 60;
		hours--;
	}
	if (minutes < 0 && hours > 0)
	{
		minutes += 60;
		hours--;
	}
	if (minutes > 0 && hours < 0)
	{
		minutes -= 60;
		hours++;
	}
	if (seconds < 0 && minutes > 0)
	{
		seconds += 60;
		minutes--;
	}
	if (seconds > 0 && minutes < 0)
	{
		seconds -= 60;
		minutes++;
	}
}