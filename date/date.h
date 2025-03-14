#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>
using namespace std;

class DateException {};

class Date
{
	double jd;
	int from_jdn_calc(int n) const;
	bool isCorrect(int year, int month, int day, int hour, int minute, int second);
	bool isCorrect(double jd_data);
	bool isCorrect(int y, int m, int d);
	int dayMonth(int m);


public:
	Date();
	Date(int year, int month, int day);
	Date(int jd_data);
	Date(int year, int month, int day, int hour, int minute, int second);

	int weekday() const;
	int day() const;
	int month() const;
	int year() const;

	bool isLeap() const;
	int jdn_calc(int day, int month, int year);

	double jdn();

	void time(int& hours, int& minutes, int& seconds);

	int operator -(const Date& d);

	friend istream& operator >>(istream& in, Date& date);
	friend ostream& operator <<(ostream& out, Date& date);

	void displayTime();
	void display();

	Date& easter();	

};



#endif