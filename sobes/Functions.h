#pragma once
#include<iostream>
#include<string>
#include "Player.h"
#include "DateOfBirth.h"
#include <conio.h>
#include<Windows.h>

using namespace std;


bool InputSuccess();
 
void InputInt(string messege, int& value);

void Menu(vector<Player> ListPlayer);

void BackToMenu(vector<Player> ListPlayer);

void ClearConsole();

void AddListPlayerInList(vector <Player>& ListPlayer, const Player& Player);

void DelListPlayerInList(vector <Player>& ListPlayer);

void ShowInfoListPlayer(vector <Player>& ListPlayer);

void SelectSort(vector<Player>& ListPlayer);

void EditInfoListPlayer(vector<Player>& ListPlayer);

void SetDateOfBirth(int& year, int& month, int& day);

Player AddInfoListPlayer();



void ClearConsole() 
{
	system("cls");
}


bool InputSuccess() 
{
	if (!cin) 
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		return 0;
	}
	else
		return 1;
}

void InputInt(string messege, int& value) 
{
	while (true) 
	{
		cout << messege;
		cin >> value;

		if (!InputSuccess()) 
		{
			cout << "������, �������� ������� �������" << endl;
		}
		else
			break;
	}
}


void AddListPlayerInList(vector <Player>& ListPlayers, const Player& Player) 
{
	ListPlayers.push_back(Player);
}


void SetDateOfBirth(int& year, int& month, int& day) 
{
	while (true) 
	{
		InputInt("��� : ", (year));
		InputInt("����� : ", (month));
		InputInt("���� : ", (day));

		if (year < 1970 || year > 2004)
			cout << "����������� ���� ��������" << endl;
		else 
		{
			if (month < 0 || month > 12)
				cout << "����������� ���� ��������" << endl;
			else if (day < 0 || day > 31)
				cout << "����������� ���� ��������" << endl;
			else
				break;
		}
	}
}
Player AddInfoListPlayer() 
{
	string name, composition, info;

	int countYellCart = 0, yearBirth = 0, monthBirth = 0, dayBirth = 0;
	bool lastMatch, nationalTeam;

	ClearConsole();

	cout << "������� ������ �� ������" << endl;
	cout << "���: ";

	cin.ignore(1, '\n');
	getline(cin, name);

	while (true) 
	{
		cout << "������(��������/��������������): ";
		getline(cin, composition);
		if (composition == "��������" || composition == "��������������")
			break;
		else
			cout << "������ ������� �������" << endl;
	}

	SetDateOfBirth(yearBirth, monthBirth, dayBirth);

	cin.ignore(1, '\n');
	while (true) 
	{
		cout << "������� � ��������� ����(��/���): ";
		getline(cin, info);

		if (info == "��") 
		{
			lastMatch = 1;
			break;
		}
		else if (info == "���") {
			lastMatch = 0;
			break;
		}
		else
			cout << "������ ������� �������" << endl;
	}

	while (true) 
	{
		cout << "������� � �������(��/���): ";
		getline(cin, info);
		if (info == "��") {
			nationalTeam = 1;
			break;
		}
		else if (info == "���") {
			nationalTeam = 0;
			break;
		}
		else
			cout << "������ ������� �������" << endl;
	}

	while (true) 
	{
		InputInt("���������� ����� ��������: ", countYellCart);

		if (countYellCart >= 0) 
		{
			break;
		}
		else
			cout << "������ ������� �������" << endl;
	}
	cout << "������ ������� ���������";

	return Player(name, DateOfBirth(yearBirth, monthBirth, dayBirth), composition, lastMatch, nationalTeam, countYellCart);
}


void DelListPlayerInList(vector <Player>& ListPlayers) 
{
	if (ListPlayers.size() != 0) 
	{
		int number;
		cout << "�������� ����� ������ �� ������ ��� �������� ����������: ";
		cin >> number;

		if (!InputSuccess()) 
		{
			cout << "������, �������� ������� �������" << endl;
			DelListPlayerInList(ListPlayers);
		}
		else if (number > ListPlayers.size() || number < 1) 
		{
			cout << "������� ������ �� ����������" << endl;
			DelListPlayerInList(ListPlayers);
		}
		else 
		{
			ListPlayers.erase(ListPlayers.begin() + (number - 1));
			cout << "������ ������� �������" << endl;
		}
	}
	else
		cout << "� ���� ������ ��� ������, ��������� �������� ����������" << endl;
}


void ShowInfoListPlayer(vector <Player>& ListPlayers) 
{
	cout << "\t�������� ��������:" << "\n1-�������� ��� ����������" << "\n2-������ ������� ��������� �������, ������� ����������� � ��������� ����, ������� ���� ������ ��������" << "\n0-�����" << endl;
	bool numFound = 0;
	switch (_getch())

	{
	case '0':
		Menu(ListPlayers);
		break;
	case '1':
		ClearConsole();
		cout << "\t���������� �� �������:" << endl;
		for (int i = 0; i < ListPlayers.size(); i++)
		{
			cout << "����� ������ � ������: " << i + 1 << endl;
			ListPlayers[i].getElement();
		}
		BackToMenu(ListPlayers);
		break;
	case '2':
		ClearConsole();
		for (int i = 0; i < ListPlayers.size(); i++)
		{
			if (ListPlayers[i].GetComposition() == "��������" && ListPlayers[i].GetLastMatch() && ListPlayers[i].GetCountYellCart())
				ListPlayers[i].getElement();
		}
		BackToMenu(ListPlayers);
		break;
	default:
		ClearConsole();
		ShowInfoListPlayer(ListPlayers);
		break;
	}

}


void SelectSort(vector<Player>& ListPlayers) 
{
	ClearConsole();

	if (!ListPlayers.empty()) 
	{
		cout << "\t�������� ��� ����������:" << "\n1-�� ���� ��������" << "\n2-�� ���������� ����� ��������" << "\n0-�����" << endl;
		vector <Player> Sort(1);
		switch (_getch())
		{
		case '0':
			Menu(ListPlayers);
		case '1':
			for (int i = 0; i < ListPlayers.size() - 1; i++)
			{
				for (int j = i + 1; j < ListPlayers.size(); j++) {
					if (ListPlayers[i].GetYearBirth() > ListPlayers[j].GetYearBirth()) {
						Sort[0] = ListPlayers[i];
						ListPlayers[i] = ListPlayers[j];
						ListPlayers[j] = Sort[0];
					}
				}
			}
			cout << "������ ������������";
			break;
		case '2':
			for (int i = 0; i < ListPlayers.size() - 1; i++)
			{
				for (int j = i + 1; j < ListPlayers.size(); j++) {
					if (ListPlayers[i].GetCountYellCart() < ListPlayers[j].GetCountYellCart()) {
						Sort[0] = ListPlayers[i];
						ListPlayers[i] = ListPlayers[j];
						ListPlayers[j] = Sort[0];
					}
				}
			}
			cout << "������ ������������";
			break;
		default:
			SelectSort(ListPlayers);
			break;
		}
	}
	else
		cout << "���� ������ ������, ������� �������� ������" << endl;
}


void EditInfoListPlayer(vector<Player>& ListPlayers) 
{
	int numPlayer;
	bool validKeyBar = 0;

	InputInt("������� ����� ������ � ������: ", numPlayer);
	cout << numPlayer;

	if (numPlayer > 0 && numPlayer <= ListPlayers.size())
	{
		ClearConsole();
		cout << "\t�������� ���� ��� ��������������" << "\n1-���" << "\n2-���� ��������" << "\n3-������" << "\n4-������� � ��������� �����" << "\n5-������� � �������" << "\n6-���������� ����� ��������" << "\n0-�����" << endl;
		while (!validKeyBar) {
			switch (_getch())
			{
			case '0':
				Menu(ListPlayers);
				break;
			case '1':
				ListPlayers[numPlayer - 1].SetFIO();
				cout << "������ ������� ��������" << endl;
				validKeyBar = 1;
				break;
			case '2':
				ListPlayers[numPlayer - 1].SetDateOfBirth();
				cout << "������ ������� ��������" << endl;
				validKeyBar = 1;
				break;
			case '3':
				ListPlayers[numPlayer - 1].SetComposition();
				cout << "������ ������� ��������" << endl;
				validKeyBar = 1;
				break;
			case '4':
				ListPlayers[numPlayer - 1].SetLastMatch();
				cout << "������ ������� ��������" << endl;
				validKeyBar = 1;
				break;
			case '5':
				ListPlayers[numPlayer - 1].SetNationalTeam();
				cout << "������ ������� ��������" << endl;
				validKeyBar = 1;
				break;
			case '6':
				ListPlayers[numPlayer - 1].SetCountYellCart();
				cout << "������ ������� ��������" << endl;
				validKeyBar = 1;
				break;
			default:
				validKeyBar = 0;
				break;
			}
		}
	}
}


void BackToMenu(vector<Player> ListPlayers) 
{
	cout << "\n0-�����" << endl;
	while (true) 
	{
		if (_getch() == 48) {
			Menu(ListPlayers);
			break;
		}
	}
}


void Menu(vector<Player> ListPlayers) 
{
	ClearConsole();
	cout << "\t�������� ��������:" << "\n1-�������� ��������� �� �������" << "\n2-�������� ������ � ������" << "\n3-������� ������ �� ������" << "\n4-���������� ������" << "\n5-������������� ���������� �� ������" << "\n0-�����" << endl;
	switch (_getch())
	{
	case '0':
		exit(0);
		break;
	case '1':
		ClearConsole();
		if (ListPlayers.size() != 0) {
			ShowInfoListPlayer(ListPlayers);
			BackToMenu(ListPlayers);
		}
		else {
			cout << "� ���� ��� ������, ��������� �������� ����������" << endl;
			BackToMenu(ListPlayers);
		}
		break;
	case '2': {
		AddListPlayerInList(ListPlayers, AddInfoListPlayer());
		BackToMenu(ListPlayers);
		break; }
	case '3':
		ClearConsole();
		DelListPlayerInList(ListPlayers);
		BackToMenu(ListPlayers);
		break;
	case '4':
		SelectSort(ListPlayers);
		BackToMenu(ListPlayers);
		break;
	case '5':
		ClearConsole();
		EditInfoListPlayer(ListPlayers);
		BackToMenu(ListPlayers);
		break;
	default:
		Menu(ListPlayers);
		break;
	}
}
