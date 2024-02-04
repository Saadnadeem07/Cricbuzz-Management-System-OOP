#include"Date.h"
Date::Date()
{
	this->date = 0;
	this->month = 0;
	this->year = 0;
}
Date::~Date()
{
	//cout << "\n\t Destructor of Date Called.";
}
Date::Date(int d, int m, int y)
{
	this->date = d;
	this->month = m;
	this->year = y;
}
void Date::set_date(int x)
{
	this->date = x;
}
void Date::set_month(int x)
{
	this->month = x;
}
void Date::set_year(int x)
{
	this->year = x;
}
int Date::get_date()
{
	return this->date;
}
int Date::get_month()
{
	return this->month;
}
int Date::get_year()
{
	return this->year;
}