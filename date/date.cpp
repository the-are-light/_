#include "date.h"

Date::Date()
{
	jd = 0;
}

Date::Date(int year, int month, int day)
{
	if (isCorrect(year, month, day))
		jd = jdn_calc(day, month, year);
	else
		throw DateException();
}

Date::Date(double jd_data)
{
	if (isCorrect(jd_data))
		jd = jd_data;
	else
		throw DateException();
}

Date::Date(int year, int month, int day, int hour, int minute, int second)
{
	if (isCorrect(year, month, day, hour, minute, second))
	{
		jd = jdn_calc(day, month, year);
		int a, y, m, j;
		a = (14 - month) / 12;
		y = year + 4800 - a;
		m = month + 12 * a - 3;
		j = jdn_calc(day, month, year);
		jd = j + (hour - 12) / 24.0 + minute / 1440.0 + second / 86400.0;
	}
	else
		throw DateException();
}

double Date::jdn()
{
	return (int)jd;
}

int Date::jdn_calc(int day, int month, int year)
{
	int a, y, m, jdn;
	a = (14 - month) / 12;
	y = year + 4800 - a;
	m = month + 12 * a - 3;
	jdn = day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
	return jdn;
}

int Date::weekday() const
{
	return (int)jd % 7;
}

int Date::from_jdn_calc(int n) const
{
	int a, b, c, d, e, m;
	a = (int)jd + 32044;
	b = (4 * a + 3) / 146097;
	c = a - 146097 * b / 4;
	d = (4 * c + 3) / 1461;
	e = c - 1461 * d / 4;
	m = (5 * e + 2) / 153;
	switch (n) {
	case 0: 
		return e - (153 * m + 2) / 5 + 1; 
	case 1: 
		return m + 3 - 12 * (m / 10);
	case 2: 
		return 100 * b + d - 4800 + m / 10; 
	default: return 0;
	}
}

int Date::day() const
{
	return from_jdn_calc(0);
}

int Date::month() const
{
	return from_jdn_calc(1);
}

int Date::year() const
{
	return from_jdn_calc(2);
}


void Date::time(int& hours, int& minutes, int& seconds)
{
	double fracPart = jd - (int)jd;
	double totalSec = fracPart * 86400.0;
	hours = (int)(totalSec / 3600);
	totalSec -= hours * 3600;
	minutes = (int)(totalSec / 60);
	seconds = (int)totalSec % 60;
}

bool Date::isLeap() const
{
	int y = this->year();
	return y % 400 == 0 || y % 100 != 0 && y % 4 == 0;
}


int Date::operator -(const Date& d)
{
	return (int)this->jd - (int)d.jd;
}

istream& operator >>(istream& in, Date& date)
{
	int d, m, y;
	in >> d >> m >> y;
	date = Date(d, m, y);
	return in;
}

ostream& operator <<(ostream& out, Date& date)
{
	int d = date.day();
	int m = date.month();
	int y = date.year();

	out << (d < 10 ? "0" : "") << d << "-" << (m < 10 ? "0" : "") << m << "-" << y;

	return out;
}

bool Date::isCorrect(int y, int m, int d)
{
	if (y > 0 && 1 <= m && m <= 12 && 1 <= d <= dayMonth(m))
		return true;
	else
		return false;
}

bool Date::isCorrect(int year, int month, int day, int hour, int minute, int second)
{
	if (year > 0 && 1 <= month && month <= 12 && 1 <= day <= dayMonth(month) && 1 <= hour && hour <= 24 && 0 <= minute <= 60 && 1 <= second && second <= 60)
		return true;
	else
		return false;
}

bool Date::isCorrect(double jd_data)
{
	if (jd_data >= 0)
		return true;
	else
		return false;
}

int Date::dayMonth(int m)
{
	switch (m)
	{
	case 1:case 3:case 5:case 7:case 8:case 10: case 12: 
		return 31;
	
	case 4: case 6: case 9: case 11: 
		return 30;

	case 2: 
		return isLeap() ? 29 : 28;

	default:
		throw DateException();
	}
}

void Date::displayTime()
{
	int h, m, s;
	time(h, m, s);
	cout << year() << "-" << (month() < 10 ? "0" : "") << month() << "-" << (day() < 10 ? "0" : "") << day() << "T" << (h < 10 ? "0" : "") << h << ":" << m << ":" << s;
}

void Date::display()
{
	cout << (day() < 10 ? "0" : "") << day() << "." << (month() < 10 ? "0" : "") << month() << "." << year();
}

Date& Date::easter()
{
	int y = year();
	int a = y % 19;
	int b = y / 100;
	int c = y % 100;
	int d = b / 4;
	int e = b % 4;
	int f = (b + 8) / 25;
	int g = (b - f + 1) / 3;
	int h = (19 * a + b - d - g + 15) % 30;
	int i = c / 4;
	int k = c % 4;
	int l = (32 + 2 * e + 2 * i - h - k) % 7;
	int m = (a + 11 * h + 22 * l) / 451;
	int month = (h + l - 7 * m + 114) / 31;
	int day = ((h + l - 7 * m + 114) % 31) + 1;
	Date date(y, month, day);
	return date;
}
