#include "Player.h"
Player::Player() = default;

Player::~Player() = default;


Player::Player(string fio, DateOfBirth dateOfBirth, string composition, bool lastMatch, bool nationalTeam, int countYellCart) :
	fio(fio), dateOfBirth(dateOfBirth), composition(composition), lastMatch(lastMatch), nationalTeam(nationalTeam), countYellCart(countYellCart) {}


void Player::getElement() 
{
	cout << "ФИО: " << fio << "\nДата рождения: " << setw(2) << dateOfBirth.GetDayBirth() << "."
		<< setw(2) << setfill('0') << dateOfBirth.GetMonthBirth() << "." << dateOfBirth.GetYearBirth()
		<< "\nСостав: " << composition << endl;
	cout << "Участие: ";

	if (lastMatch)
		cout << "Да" << endl;
	else
		cout << "Нет" << endl;
	cout << "Состоит в команде: ";
	if (nationalTeam)
		cout << "Да" << endl;
	else
		cout << "Нет" << endl;
	cout << "Количество карточек: " << countYellCart << endl << endl;
}


string Player::GetFIO() {
	return fio;
}


string Player::GetComposition() {
	return composition;
}

int Player::GetYearBirth() {
	return dateOfBirth.GetYearBirth();
}

bool Player::GetLastMatch() {
	return lastMatch;
}

bool Player::GetNationalTeam() {
	return nationalTeam;
}

int Player::GetCountYellCart() {
	return countYellCart;
}

void Player::SetFIO() {
	cout << "Новые ФИО: ";
	string fio;
	cin.ignore(1);
	getline(cin, fio);
	this->fio = fio;
}


void Player::SetComposition() {
	string gender;
	while (true) {
		cout << "Состав(Основной/Дополнительный): ";
		cin >> composition;
		if (composition == "Основной" || composition == "Дополнительный") {
			this->composition = composition;
			break;
		}
		else {
			cout << "Состав введён неверно" << endl;
		}
	}
}


void Player::SetDateOfBirth() 
{
	int year, month, day;

	while (true) 
	{
		InputInt("Год рождения: ", (year));
		InputInt("Месяц рождения: ", (month));
		InputInt("День рождения: ", (day));

		if (year < 1970 || year > 2004)
			cout << "Некоректная дата рождения" << endl;
		else 
		{
			if (month < 0 || month > 12)
				cout << "Некоректная дата рождения" << endl;
			else if (day < 0 || day > 31)
				cout << "Некоректная дата рождения" << endl;
			else 
			{
				dateOfBirth.SetYearBirth(year);
				dateOfBirth.SetMonthBirth(month);
				dateOfBirth.SetDayBirth(day);
				break;
			}
		}
	}
}
void Player::SetLastMatch() 
{
	string str;
	cin.ignore(1, '\n');

	while (true) 
	{
		cout << "Участие в последнем матче(Да/Нет): ";
		getline(cin, str);

		if (str == "Да") 
		{
			this->lastMatch = 1;
			break;
		}
		else if (str == "Нет") 
		{
			this->lastMatch = 0;
			break;
		}
		else
			cout << "Информация введена неверно" << endl;
	}
}
void Player::SetNationalTeam()
{
	string str;
	cin.ignore(1, '\n');

	while (true) 
	{
		cout << "Состоит в сборной(Да/Нет): ";
		getline(cin, str);

		if (str == "Да") 
		{
			this->nationalTeam = 1;
			break;
		}
		else if (str == "Нет") 
		{
			this->nationalTeam = 0;
			break;
		}
		else
			cout << "Информация введена неверно" << endl;
	}
}
void Player::SetCountYellCart() 
{
	int count;

	while (true)
	{
		InputInt("Количество жёлтых карточек: ", count);
		if (count > 0) 
		{
			this->countYellCart = count;
			break;
		}
		else
			cout << "Значение введено неверно" << endl;
	}
}
void Player::InputInt(string messege, int& value) 
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
bool Player::InputSuccess() 
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

