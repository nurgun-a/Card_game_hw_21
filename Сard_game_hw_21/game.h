#define _CRT_SECURE_NO_WARNIGS
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <vector>
#include <list>
#include <conio.h>

using namespace std;

enum ConsoleColor {
	Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray,
	LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};

struct Card
{
	int num;//6-14
	int mast;//1-4
	Card(){}
	Card(int n, int m)
	{
		num = n;
		mast = m;
	}
	friend ostream& operator << (ostream& os, Card& c);
	int num_get()
	{
		return num;
	}
};

class game
{
public:
	game(){}
	void kolda( list<Card>& l);
	void new_Game(int kol);
	void razdacha(list<Card>*& pl, int k, list<Card>& l);
	void sbros_c(list<Card>*& pleyr, int k, Card*& tmp);
	void win_r(list<Card>*& pleyr, int k, Card*& tmp);
	void win_g(list<Card>*& pleyr, int k);
};
void SetColor(int text, int background);
void Show_menu();