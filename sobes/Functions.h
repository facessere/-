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
			cout << "Ошибка, значение введено неверно" << endl;
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
		InputInt("Год : ", (year));
		InputInt("Месяц : ", (month));
		InputInt("День : ", (day));

		if (year < 1970 || year > 2004)
			cout << "Некоректная дата рождения" << endl;
		else 
		{
			if (month < 0 || month > 12)
				cout << "Некоректная дата рождения" << endl;
			else if (day < 0 || day > 31)
				cout << "Некоректная дата рождения" << endl;
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

	cout << "Введите данные об игроке" << endl;
	cout << "ФИО: ";

	cin.ignore(1, '\n');
	getline(cin, name);

	while (true) 
	{
		cout << "Состав(Основной/Дополнительный): ";
		getline(cin, composition);
		if (composition == "Основной" || composition == "Дополнительный")
			break;
		else
			cout << "Данные введены неверно" << endl;
	}

	SetDateOfBirth(yearBirth, monthBirth, dayBirth);

	cin.ignore(1, '\n');
	while (true) 
	{
		cout << "Участие в последней игре(Да/Нет): ";
		getline(cin, info);

		if (info == "Да") 
		{
			lastMatch = 1;
			break;
		}
		else if (info == "Нет") {
			lastMatch = 0;
			break;
		}
		else
			cout << "Данные введены неверно" << endl;
	}

	while (true) 
	{
		cout << "Участие в сборной(Да/Нет): ";
		getline(cin, info);
		if (info == "Да") {
			nationalTeam = 1;
			break;
		}
		else if (info == "Нет") {
			nationalTeam = 0;
			break;
		}
		else
			cout << "Данные введены неверно" << endl;
	}

	while (true) 
	{
		InputInt("Количество жёлтых карточек: ", countYellCart);

		if (countYellCart >= 0) 
		{
			break;
		}
		else
			cout << "Данные введены неверно" << endl;
	}
	cout << "Данные успешно добавлены";

	return Player(name, DateOfBirth(yearBirth, monthBirth, dayBirth), composition, lastMatch, nationalTeam, countYellCart);
}


void DelListPlayerInList(vector <Player>& ListPlayers) 
{
	if (ListPlayers.size() != 0) 
	{
		int number;
		cout << "Выберите номер игрока из списка для удаления информации: ";
		cin >> number;

		if (!InputSuccess()) 
		{
			cout << "Ошибка, значение введено неверно" << endl;
			DelListPlayerInList(ListPlayers);
		}
		else if (number > ListPlayers.size() || number < 1) 
		{
			cout << "Данного номера не существует" << endl;
			DelListPlayerInList(ListPlayers);
		}
		else 
		{
			ListPlayers.erase(ListPlayers.begin() + (number - 1));
			cout << "Данные успешно удалены" << endl;
		}
	}
	else
		cout << "В базе данных нет данных, необходмо добавить информацию" << endl;
}


void ShowInfoListPlayer(vector <Player>& ListPlayers) 
{
	cout << "\tВыберите действие:" << "\n1-Показать всю информацию" << "\n2-Список игроков основного состава, которые участвовали в последней игре, имеющих одну желтую карточку" << "\n0-Назад" << endl;
	bool numFound = 0;
	switch (_getch())

	{
	case '0':
		Menu(ListPlayers);
		break;
	case '1':
		ClearConsole();
		cout << "\tИнформация об игроках:" << endl;
		for (int i = 0; i < ListPlayers.size(); i++)
		{
			cout << "Номер игрока в списке: " << i + 1 << endl;
			ListPlayers[i].getElement();
		}
		BackToMenu(ListPlayers);
		break;
	case '2':
		ClearConsole();
		for (int i = 0; i < ListPlayers.size(); i++)
		{
			if (ListPlayers[i].GetComposition() == "Основной" && ListPlayers[i].GetLastMatch() && ListPlayers[i].GetCountYellCart())
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
		cout << "\tВыберите вид сортировки:" << "\n1-По году рождения" << "\n2-По количеству жёлтых карточек" << "\n0-Назад" << endl;
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
			cout << "Список отсортирован";
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
			cout << "Список отсортирован";
			break;
		default:
			SelectSort(ListPlayers);
			break;
		}
	}
	else
		cout << "База данных пустая, сначала добавьте данные" << endl;
}


void EditInfoListPlayer(vector<Player>& ListPlayers) 
{
	int numPlayer;
	bool validKeyBar = 0;

	InputInt("Введите номер игрока в списке: ", numPlayer);
	cout << numPlayer;

	if (numPlayer > 0 && numPlayer <= ListPlayers.size())
	{
		ClearConsole();
		cout << "\tВыберите поле для редактирования" << "\n1-ФИО" << "\n2-Дата рождения" << "\n3-Состав" << "\n4-Участие в последнем матче" << "\n5-Участие в сборной" << "\n6-Количество жёлтых карточек" << "\n0-Назад" << endl;
		while (!validKeyBar) {
			switch (_getch())
			{
			case '0':
				Menu(ListPlayers);
				break;
			case '1':
				ListPlayers[numPlayer - 1].SetFIO();
				cout << "Данные успешно изменены" << endl;
				validKeyBar = 1;
				break;
			case '2':
				ListPlayers[numPlayer - 1].SetDateOfBirth();
				cout << "Данные успешно изменены" << endl;
				validKeyBar = 1;
				break;
			case '3':
				ListPlayers[numPlayer - 1].SetComposition();
				cout << "Данные успешно изменены" << endl;
				validKeyBar = 1;
				break;
			case '4':
				ListPlayers[numPlayer - 1].SetLastMatch();
				cout << "Данные успешно изменены" << endl;
				validKeyBar = 1;
				break;
			case '5':
				ListPlayers[numPlayer - 1].SetNationalTeam();
				cout << "Данные успешно изменены" << endl;
				validKeyBar = 1;
				break;
			case '6':
				ListPlayers[numPlayer - 1].SetCountYellCart();
				cout << "Данные успешно изменены" << endl;
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
	cout << "\n0-Назад" << endl;
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
	cout << "\tВыберите действие:" << "\n1-Просмотр иформации об игроках" << "\n2-Добавить игрока в список" << "\n3-Удалить игрока из списка" << "\n4-Сортировка списка" << "\n5-Редактировать информацию об игроке" << "\n0-Выход" << endl;
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
			cout << "В базе нет данных, необходмо добавить информацию" << endl;
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
