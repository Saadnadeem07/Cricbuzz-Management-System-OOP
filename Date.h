#pragma once
#include<iostream>
using namespace std;
class Date
{
public:
	Date();
	~Date();
	Date(int d, int m, int y);
	void set_date(int x);
	void set_month(int x);
	void set_year(int x);
	int get_date();
	int get_month();
	int get_year();
private:
	int date;
	int month;
	int year;
};