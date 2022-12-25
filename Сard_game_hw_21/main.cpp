#include "game.h"

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	//system("color 70");
	SetColor(0, 15);
	game g1;
	char k;
	int kk=6;
	bool key = 1;
	bool key2 = 1;
	do
	{
		system("cls");
		Show_menu();
		do
		{			
			cout << "Введите кол-во игроков (от 2 до 6)" << endl;
			cout << "Enter: "; cin >> k; system("cls");
			if (k < '2' || k>'6') cout << "Error" << endl;
			else 
			{ 
				if (k == '2') kk = 2;
				else if (k == '3') kk = 3;
				else if (k == '4') kk = 4;
				else if (k == '5') kk = 5;
				else if (k == '6') kk = 6;
				key = 0; 
			}
		} while (key);
		g1.new_Game(kk);
		cout << "Возодновить игру?\n1 - Да\n0 - Выйти" << endl;
		cout << "Enter: "; cin >> key2; cout << endl;
	} while (key2);
	system("cls");
	cout << "\n\n\t\t\t\t\t\tThe end!!!\n\n" << endl;
}