#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
#include "DateOfBirth.h"

using namespace std;

class Player 
{
private:

	string fio = "";
	DateOfBirth dateOfBirth;
	string composition = "Дополнительный";
	bool lastMatch = 0;
	bool nationalTeam = 0;
	int countYellCart = 0;

public:

	Player();

	Player(string fio, DateOfBirth dateOfBirth, string composition, bool lastMatch, bool nationalTeam, int countYellCart);

	~Player();

	void getElement();

	int GetYearBirth();

	string GetFIO();

	string GetComposition();

	bool GetLastMatch();

	bool GetNationalTeam();

	int GetCountYellCart();

	void SetFIO();

	void SetComposition();

	void SetDateOfBirth();

	void SetLastMatch();

	void SetNationalTeam();

	void SetCountYellCart();

	void InputInt(string messege, int& value);

	bool InputSuccess();
};
