#include "game.h"

void game::kolda( list<Card>& l)
{
	vector<Card> v;
	for (int i = 1; i < 5; i++)
	{
		for (int j = 6; j < 15; j++)
		{
			v.push_back(Card(j, i));
		}
	}
	int n1;
	auto it = v.begin();
	for (int i = 0; i < 36; i++)
	{
		n1 = rand() % v.size();
		l.push_back(v[n1]);
		it = v.begin();
		advance(it, n1);
		v.erase(it);
	}
}

void game::new_Game(int kol)
{	
	list<Card> kld;
	kolda(kld);
	list<Card> *pleyr= new list<Card>[kol];	
	razdacha(pleyr,kol,kld);	

	Card *tmp=new Card[kol];
	int raund = 0; 
	if(kol>4) raund = 6;	
	else if(kol<4) raund = 10; 
	else if(kol==4) raund = 9;
	
	for (int i = 0; i < raund; i++)
	{	
		system("cls");
		
		sbros_c(pleyr,kol,tmp);
		cout << endl;
		cout << "\t\t\t\t    Раунд " << i + 1 << endl << endl;
		win_r(pleyr, kol, tmp);		
	}
	win_g(pleyr, kol);	
}

void game::razdacha(list<Card>*& pl, int k, list<Card>& l)
{
	while (!l.empty())
	{
		for (int i = 0; i < k; i++)
		{
			pl[i].push_back(l.front());
			l.pop_front();
			if (l.empty()) break;
		}
	}
}

void game::sbros_c(list<Card>*& pleyr, int k, Card*& tmp)
{
	for (int i = 0; i < k; i++)
	{
		cout << "Игрок " << i + 1 << " | ---> ";
		cout << pleyr[i].front() << "<--- ";			
		tmp[i] = pleyr[i].front();
		pleyr[i].pop_front();
		for (auto it = pleyr[i].begin(); it != pleyr[i].end(); it++)
		{
			cout << *it;
		}
		cout << endl;
		cout << "------------------------------------------------------------------" << endl;
	}
}

void game::win_r(list<Card>*& pleyr, int k, Card*& tmp)
{
	int w = 0;
	for (int i = 0; i < k; i++)
	{
		if (tmp[i].num > tmp[w].num)
			w = i;
	}
	cout << endl;
	cout << "\t\t\t\t" <<  "Выиграл Игрок " << w + 1 << endl;
	cout << "------------------------------------------------------------------" << endl;
	for (int i = 0; i < k; i++)
	{
		pleyr[w].push_back(tmp[i]);
		cout << tmp[i] ;			
	}
	cout <<"---> "<< endl;
	cout << "---------------" << endl;
	for (auto it = pleyr[w].begin(); it != pleyr[w].end(); it++)
	{
		cout << *it;
	}
	cout << endl << endl;
	
	_getch();
}

void game::win_g(list<Card>*& pleyr, int k)
{
	int w = 0;
	//********************************************
	for (int i = 0; i < k; i++)
	{
		if (pleyr[i].size() > pleyr[w].size())
			w = i;
	}
	cout << endl;
	cout << "**************************************************************************************" << endl;
	cout << "\t\t\t\tВыиграл Игрок " << w + 1 << endl << endl;


	for (auto it = pleyr[w].begin(); it != pleyr[w].end(); it++)
	{
		cout << *it;
	}
	cout << "\n*************************************************************************************" << endl;
}

ostream& operator<<(ostream& os, Card& c)
{
	char mm;
	switch (c.num)
	{
	case 6:
	{
		if (c.mast == 1) { mm = 3; SetColor(4, 15);}
		else if (c.mast == 2) mm = 6;
		else if (c.mast == 3) {mm = 4; SetColor(4, 15);}
		else if (c.mast == 4) mm = 5;
		
		os << '[' << c.num << " " << mm << ']';
		SetColor(0, 15);
	}break;
	case 7:
	{
		if (c.mast == 1) { mm = 3; SetColor(4, 15); }
		else if (c.mast == 2) mm = 6;
		else if (c.mast == 3) { mm = 4; SetColor(4, 15); }
		else if (c.mast == 4) mm = 5;

		os << '[' << c.num << " " << mm << ']';
		SetColor(0, 15);
	}break;
	case 8:
	{
		if (c.mast == 1) { mm = 3; SetColor(4, 15); }
		else if (c.mast == 2) mm = 6;
		else if (c.mast == 3) { mm = 4; SetColor(4, 15); }
		else if (c.mast == 4) mm = 5;

		os << '[' << c.num << " " << mm << ']';
		SetColor(0, 15);
	}break;
	case 9:
	{
		if (c.mast == 1) { mm = 3; SetColor(4, 15); }
		else if (c.mast == 2) mm = 6;
		else if (c.mast == 3) { mm = 4; SetColor(4, 15); }
		else if (c.mast == 4) mm = 5;

		os << '[' << c.num << " " << mm << ']';
		SetColor(0, 15);
	}break;
	case 10:
	{
		if (c.mast == 1) { mm = 3; SetColor(4, 15); }
		else if (c.mast == 2) mm = 6;
		else if (c.mast == 3) { mm = 4; SetColor(4, 15); }
		else if (c.mast == 4) mm = 5;

		os << '[' << c.num <<  mm << ']';
		SetColor(0, 15);
	}break;
	case 11:
	{
		if (c.mast == 1) { mm = 3; SetColor(4, 15); }
		else if (c.mast == 2) mm = 6;
		else if (c.mast == 3) { mm = 4; SetColor(4, 15); }
		else if (c.mast == 4) mm = 5;

		os << "[В " << mm << ']';
		SetColor(0, 15);
	}break;
	case 12:
	{
		if (c.mast == 1) { mm = 3; SetColor(4, 15); }
		else if (c.mast == 2) mm = 6;
		else if (c.mast == 3) { mm = 4; SetColor(4, 15); }
		else if (c.mast == 4) mm = 5;

		os << "[Д " << mm << ']';
		SetColor(0, 15);
	}break;
	case 13:
	{
		if (c.mast == 1) { mm = 3; SetColor(4, 15); }
		else if (c.mast == 2) mm = 6;
		else if (c.mast == 3) { mm = 4; SetColor(4, 15); }
		else if (c.mast == 4) mm = 5;

		os << "[К " << mm << ']';
		SetColor(0, 15);
	}break;
	case 14:
	{
		if (c.mast == 1) { mm = 3; SetColor(4, 15); }
		else if (c.mast == 2) mm = 6;
		else if (c.mast == 3) { mm = 4; SetColor(4, 15); }
		else if (c.mast == 4) mm = 5;

		os << "[Т " << mm << ']';
		SetColor(0, 15);
	}break;

	default:
		break;
	}

	return os;
}

void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void Show_menu()
{
	cout << "Программа «Карточная игра»" << endl;
	cout << "Игроки кладут по одной карте. У кого карта больше," << endl;
	cout << "то тот игрок забирает все карты и кладет их в конец своей колоды. " << endl;
	cout << "При совпадении карт забирает первый игрок" << endl;
	cout << "Выигрывает игрок, который забрал все карты. " << endl << endl << endl;
}
