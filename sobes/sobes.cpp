#include "Function.h"
#include "Player.h"
#include "DateOfBirth.h"
#include<Windows.h>

int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	vector <Player> ListPlayers;

	Player Nikkolai("Nikkolai Niki Rtyo ", DateOfBirth(2002, 3, 30), "Дополнительный", 1, 1, 1);
	Player Oleg("Oleg  Alexandrovich Ruzhansri", DateOfBirth(2000, 5, 30), "Основной", 1, 1, 3);

	ListPlayers.push_back(Nikkolai);
	ListPlayers.push_back(Oleg);

	Menu(ListPlayers);
}
