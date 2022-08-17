#include "DataOfBirth.h"
	

DateOfBirth::DateOfBirth(int year, int month, int day) {
	if (year < 0)
		this->yearBirth = 0;
	else
		this->yearBirth = year;
	if (month < 0)
		this->monthBirth = 0;
	else
		this->monthBirth = month;
	if (day < 0)
		this->dayBirth = 0;
	else
		this->dayBirth = day;
}

const int DateOfBirth::GetYearBirth() {
	return yearBirth;
}

const int DateOfBirth::GetMonthBirth() {
	return monthBirth;
}

const int DateOfBirth::GetDayBirth() {
	return dayBirth;
}

void DateOfBirth::SetYearBirth(int year) {
	this->yearBirth = year;
}

void DateOfBirth::SetMonthBirth(int month) {
	this->monthBirth = month;
}

void DateOfBirth::SetDayBirth(int day) {
	this->dayBirth = day;
}
