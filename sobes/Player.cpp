#include "Player.h"
Player::Player() = default;

Player::~Player() = default;


Player::Player(string fio, DateOfBirth dateOfBirth, string composition, bool lastMatch, bool nationalTeam, int countYellCart) :
	fio(fio), dateOfBirth(dateOfBirth), composition(composition), lastMatch(lastMatch), nationalTeam(nationalTeam), countYellCart(countYellCart) {}


void Player::getElement() 
{
	cout << "���: " << fio << "\n���� ��������: " << setw(2) << dateOfBirth.GetDayBirth() << "."
		<< setw(2) << setfill('0') << dateOfBirth.GetMonthBirth() << "." << dateOfBirth.GetYearBirth()
		<< "\n������: " << composition << endl;
	cout << "�������: ";

	if (lastMatch)
		cout << "��" << endl;
	else
		cout << "���" << endl;
	cout << "������� � �������: ";
	if (nationalTeam)
		cout << "��" << endl;
	else
		cout << "���" << endl;
	cout << "���������� ��������: " << countYellCart << endl << endl;
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
	cout << "����� ���: ";
	string fio;
	cin.ignore(1);
	getline(cin, fio);
	this->fio = fio;
}


void Player::SetComposition() {
	string gender;
	while (true) {
		cout << "������(��������/��������������): ";
		cin >> composition;
		if (composition == "��������" || composition == "��������������") {
			this->composition = composition;
			break;
		}
		else {
			cout << "������ ����� �������" << endl;
		}
	}
}


void Player::SetDateOfBirth() 
{
	int year, month, day;

	while (true) 
	{
		InputInt("��� ��������: ", (year));
		InputInt("����� ��������: ", (month));
		InputInt("���� ��������: ", (day));

		if (year < 1970 || year > 2004)
			cout << "����������� ���� ��������" << endl;
		else 
		{
			if (month < 0 || month > 12)
				cout << "����������� ���� ��������" << endl;
			else if (day < 0 || day > 31)
				cout << "����������� ���� ��������" << endl;
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
		cout << "������� � ��������� �����(��/���): ";
		getline(cin, str);

		if (str == "��") 
		{
			this->lastMatch = 1;
			break;
		}
		else if (str == "���") 
		{
			this->lastMatch = 0;
			break;
		}
		else
			cout << "���������� ������� �������" << endl;
	}
}
void Player::SetNationalTeam()
{
	string str;
	cin.ignore(1, '\n');

	while (true) 
	{
		cout << "������� � �������(��/���): ";
		getline(cin, str);

		if (str == "��") 
		{
			this->nationalTeam = 1;
			break;
		}
		else if (str == "���") 
		{
			this->nationalTeam = 0;
			break;
		}
		else
			cout << "���������� ������� �������" << endl;
	}
}
void Player::SetCountYellCart() 
{
	int count;

	while (true)
	{
		InputInt("���������� ����� ��������: ", count);
		if (count > 0) 
		{
			this->countYellCart = count;
			break;
		}
		else
			cout << "�������� ������� �������" << endl;
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
			cout << "������, �������� ������� �������" << endl;
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

