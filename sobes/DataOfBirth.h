#pragma once
using namespace std;

class DateOfBirth 
{
private:
	int yearBirth;
	int monthBirth;
	int dayBirth;

public:

	DateOfBirth(int year = 0, int mont = 0, int day = 0);

	const int GetYearBirth();
	const int GetMonthBirth();
	const int GetDayBirth();


	void SetYearBirth(int year);

	void SetMonthBirth(int month);

	void SetDayBirth(int day);
};
