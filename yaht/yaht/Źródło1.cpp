#include <iostream>
#include <time.h>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

using namespace std;
void wodowanie(int o);
void wodowanie2(int o);
void bariera();
void bariera2();
void bariera3();
void wyswietlacz();
void sprawdzaczbat();
void sprawdzacztab();
void bot();
void bot2();
int tab[10][10];
int bat[10][10];
int m4 = 0;
int m3 = 0;
int m2 = 0;
int  y, x, traf = 0, stronyy = 0, wystarczy;
char rama;
int tr=0;
int  a, b;
int win = 0;
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			tab[i][j] = 0;
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			bat[i][j] = 0;
		}
	}


	wodowanie(4);
	bariera();
	for (int i = 0; i < 2; i++)
	{
		wodowanie(3);
		bariera();
	}
	for (int i = 0; i < 3; i++)
	{
		wodowanie(2);
		bariera();
	}
	for (int i = 0; i < 4; i++)
	{
		wodowanie(1);
		bariera();
	}


	wodowanie2(4);
	bariera2();
	for (int i = 0; i < 2; i++)
	{
		wodowanie2(3);
		bariera2();
	}
	for (int i = 0; i < 3; i++)
	{
		wodowanie2(2);
		bariera2();
	}
	for (int i = 0; i < 4; i++)
	{
		wodowanie2(1);
		bariera2();
	}
	char poziom;
	int poziomki;

	cout << "Siemanko, witam w moich statkach!" << '\n' << "wybierz poziom trudnosci" << endl;
	cout << "1 - Dziecko we mgle" << '\n' << "2 - prawie ai" << endl;

poziomek:
	poziom = _getch();
	if (poziom == '1')
		poziomki = 1;
	else if (poziom == '2')
		poziomki = 2;
	else
	{
		cout << "nawet nie probuj byq" << endl;
		goto poziomek;
	}
	system("cls");
	cout << '\n' << '\n' << '\n' << '\n' << "        powodzenia marynarzu" << endl;
	Sleep(2000);
	system("cls");
	wyswietlacz();

	srand(time(NULL));
	while (true)
	{

		cout << "wprowadz litere wiersza:";
	start2:
		rama = _getch();
		if (rama == 'a' || rama == 'A')
			x = 1;
		else if (rama == 'b' || rama == 'B')
			x = 2;
		else if (rama == 'c' || rama == 'C')
			x = 3;
		else if (rama == 'd' || rama == 'D')
			x = 4;
		else if (rama == 'e' || rama == 'E')
			x = 5;
		else if (rama == 'f' || rama == 'F')
			x = 6;
		else if (rama == 'g' || rama == 'G')
			x = 7;
		else if (rama == 'h' || rama == 'H')
			x = 8;
		else if (rama == 'i' || rama == 'I')
			x = 9;
		else if (rama == 'j' || rama == 'J')
			x = 10;
		else {
			cout << '\n' << "wprowadz poprawna litere mordo" << endl;
			goto start2;
		}
		cout << rama << endl;
		cout << '\n' << "wprowadz liczbe kolumny:";
	start7:
		while (!(cin >> y))
		{
			cout << "we nie swiruj wariacie" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			goto start7;
		}
		if (!(y == 1 || y == 2 || y == 3 || y == 4 || y == 5 || y == 6 || y == 7 || y == 8 || y == 9 || y == 10))
		{
			cout << "calm ur horses cowboy";
			goto start7;
		}

		x--;
		y--;

		if (bat[x][y] == 7) {
			bat[x][y] = 6;
		}
		else if (bat[x][y] == 0) {
			bat[x][y] = 8;
		}
		else if (bat[x][y] == 6 || bat[x][y] == 8) {
			cout << "wariacie juz tu strzelales" << endl;
			goto start2;
		}
		system("cls");
		wyswietlacz();
		sprawdzaczbat();
		if (win == 0)
			return 0;

		Sleep(1000);

		if (poziomki == 1)
		{
			bot2();
			sprawdzacztab();
			if (win == 0)
				return 0;

		}
		else if (poziomki == 2)
		{
			bot();
			sprawdzacztab();
			if (win == 0)
				return 0;
		}

		system("cls");
		wyswietlacz();
	}

	return 0;
}

void wodowanie(int o)
{
	srand(time(NULL));
	int r, d, p;

start:
	int l = 0;
	r = rand() % 10;
	d = rand() % 10;
	p = rand() % 2 + 1;

	if (p == 1) {
		if (r + o <= 10) {
			for (int i = 0; i < o; i++) {
				if (tab[r + i][d] == 0) {
					l++;
				}
				else
					goto start;
			}
			for (int i = 0; i < o; i++)
				tab[r + i][d] = 7;

		}
		else goto start;
	}
	else if (p == 2) {
		if (d + o <= 10) {
			for (int i = 0; i < o; i++) {
				if (tab[r][d + i] == 0) {
					l++;
				}
				else goto start;
			}
			for (int i = 0; i < o; i++)
				tab[r][d + i] = 7;

		}
		else goto start;
	}
}

void wodowanie2(int o)
{
	srand(time(NULL));
	int r, d, p, r2, d2;

start:
	int l = 0;
	r = rand() % 100;
	d = rand() % 100;
	p = rand() % 2 + 1;
	r2 = rand() % 10;
	d2 = rand() % 10;
	r = (r * r2) % 10;
	d = (d * d2) % 10;

	if (p == 1) {
		if (r + o <= 10) {
			for (int i = 0; i < o; i++) {
				if (bat[r + i][d] == 0) {
					l++;
				}
				else
					goto start;
			}
			for (int i = 0; i < o; i++)
				bat[r + i][d] = 7;

		}
		else goto start;
	}
	else if (p == 2) {
		if (d + o <= 10) {
			for (int i = 0; i < o; i++) {
				if (bat[r][d + i] == 0) {
					l++;
				}
				else goto start;
			}
			for (int i = 0; i < o; i++)
				bat[r][d + i] = 7;

		}
		else goto start;
	}
}



void bariera() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (tab[i][j] == 7) {
				for (int y = -1; y < 2; y++) {
					for (int x = -1; x < 2; x++) {
						if (0 <= (i + y) && (i + y) < 10 && 0 <= (j + x) && (j + x) < 10) {
							if (tab[i + y][j + x] == -1 || tab[i + y][j + x] == 0)
								tab[i + y][j + x] = -1;
						}
					}

				}
			}
		}
	}
}

void bariera2() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (bat[i][j] == 7) {
				for (int y = -1; y < 2; y++) {
					for (int x = -1; x < 2; x++) {
						if (0 <= (i + y) && (i + y) < 10 && 0 <= (j + x) && (j + x) < 10) {
							if (bat[i + y][j + x] == -1 || bat[i + y][j + x] == 0)
								bat[i + y][j + x] = -1;
						}
					}

				}
			}
		}
	}
}

void bariera3() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (tab[i][j] == 6) {
				for (int y = -1; y < 2; y++) {
					for (int x = -1; x < 2; x++) {
						if (0 <= (i + y) && (i + y) < 10 && 0 <= (j + x) && (j + x) < 10) {
							if (tab[i + y][j + x] == 0)
								tab[i + y][j + x] = 4;
						}
					}

				}
			}
		}
	}
}


void wyswietlacz()
{
	/* for (int i = 0; i < 10; i++)
	 {
		 for (int j = 0; j < 10; j++)
		 {
			 cout.width(2);
			 if (bat[i][j]==-1)
				 bat[i][j]=0;
			 cout << bat[i][j] << " ";
		 }
		 cout << endl;
	 }
	 cout<<endl;
	 */
	int ramy[11];
	for (int i = 0; i < 11; i++) {
		ramy[i] = i;
		SetConsoleTextAttribute(color, 14);
		cout << ramy[i] << "  ";
	}
	cout << endl;

	for (int i = 0; i < 10; i++)
	{
		SetConsoleTextAttribute(color, 14);
		switch (i)
		{
		case 0:
			cout << "A" << " ";
			break;
		case 1:
			cout << "B" << " ";
			break;
		case 2:
			cout << "C" << " ";
			break;
		case 3:
			cout << "D" << " ";
			break;
		case 4:
			cout << "E" << " ";
			break;
		case 5:
			cout << "F" << " ";
			break;
		case 6:
			cout << "G" << " ";
			break;
		case 7:
			cout << "H" << " ";
			break;
		case 8:
			cout << "I" << " ";
			break;
		case 9:
			cout << "J" << " ";
			break;
		}
		SetConsoleTextAttribute(color, 15);
		for (int j = 0; j < 10; j++)
		{
			cout.width(2);
			switch (bat[i][j])
			{
			case 0:
				cout << bat[i][j] << " ";
				break;
			case -1:
				bat[i][j] = 0;
				cout << bat[i][j] << " ";
				break;
			case 7:
				cout << "0" << " ";
				break;
			case 6:
				SetConsoleTextAttribute(color, 11);
				cout << "+" << " ";
				SetConsoleTextAttribute(color, 15);
				break;
			case 8:
				cout << "-" << " ";
				break;
			}


		}
		cout << endl;
	}

	cout << endl << endl;

	for (int i = 0; i < 11; i++) {
		SetConsoleTextAttribute(color, 14);
		cout << ramy[i] << "  ";
	}
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		SetConsoleTextAttribute(color, 14);
		switch (i)
		{
		case 0:
			cout << "A" << " ";
			break;
		case 1:
			cout << "B" << " ";
			break;
		case 2:
			cout << "C" << " ";
			break;
		case 3:
			cout << "D" << " ";
			break;
		case 4:
			cout << "E" << " ";
			break;
		case 5:
			cout << "F" << " ";
			break;
		case 6:
			cout << "G" << " ";
			break;
		case 7:
			cout << "H" << " ";
			break;
		case 8:
			cout << "I" << " ";
			break;
		case 9:
			cout << "J" << " ";
			break;
		}
		SetConsoleTextAttribute(color, 15);
		for (int j = 0; j < 10; j++)
		{
			cout.width(2);
			switch (tab[i][j])
			{
			case 0:
				cout << tab[i][j] << " ";
				break;
			case -1:
				tab[i][j] = 0;
				cout << tab[i][j] << " ";
				break;
			case 4:
				cout << "0" << " ";
				break;
			case 7:
				SetConsoleTextAttribute(color, 11);
				cout << tab[i][j] << " ";
				SetConsoleTextAttribute(color, 15);
				break;
			case 6:
				SetConsoleTextAttribute(color, 12);
				cout << "+" << " ";
				SetConsoleTextAttribute(color, 15);
				break;
			case 8:
				cout << "-" << " ";
				break;
			}
		}
		cout << endl;
	}
	SetConsoleTextAttribute(color, 15);
}


void sprawdzacztab() {
	win = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (tab[i][j] == 7)
				win++;
		}
	}
	if (win == 0)
		cout << "defeat" << endl;
}

void sprawdzaczbat()
{
	win = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (bat[i][j] == 7)
				win++;
		}
	}
	if (win == 0)
		cout << "Victory" << endl;
}

void bot()
{
	if (traf == 4)
	{
			bariera3();
			goto start3;
	}
	if (tr == 4)
	{
		bariera3();
		goto start3;
	}

	if (traf == 3)
	{
		if (m4==1)
		{
			bariera3();
			goto start3;
		}

		switch (stronyy)
		{
		case 1:
			if ((a + traf) >= 10)
				goto ai1;
			else if (tab[a + traf][b] == 7) {
				tab[a + traf][b] = 6;
				traf++;
				tr++;
			}
			else if (tab[a + traf][b] == 0) {
				tab[a + traf][b] = 8;
			}
			else if (tab[a + traf][b] == 8 || tab[a + traf][b] == 6 || tab[a + traf][b] == 4) {
				goto ai1;
			}
			break;

		case 2:
			if ((a - traf) < 0)
				goto ai1;
			else if (tab[a - traf][b] == 7) {
				tab[a - traf][b] = 6;
				traf++;
				tr++;
			}
			else if (tab[a - traf][b] == 0) {
				tab[a - traf][b] = 8;
			}
			else if (tab[a - traf][b] == 8 || tab[a - traf][b] == 6 || tab[a - traf][b] == 4) {
				goto ai1;
			}
			break;

		case 3:
			if ((b + traf) >= 10)
				goto ai1;
			else if (tab[a][b + traf] == 7) {
				tab[a][b + traf] = 6;
				traf++;
				tr++;
			}
			else if (tab[a][b + traf] == 0) {
				tab[a][b + traf] = 8;
			}
			else if (tab[a][b + traf] == 8 || tab[a][b + traf] == 6 || tab[a][b + traf] == 4) {
				goto ai1;
			}
			break;

		case 4:
			if ((b - traf) < 0)
				goto ai1;
			else if (tab[a][b - traf] == 7) {
				tab[a][b - traf] = 6;
				traf++;
				tr++;
			}
			else if (tab[a][b - traf] == 0) {
				tab[a][b - traf] = 8;
			}
			else if (tab[a][b - traf] == 8 || tab[a][b - traf] == 6 || tab[a][b - traf] == 4) {
				goto ai1;
			}
			break;
		}
	}

	if (traf == 2)
	{
		if (m4==1 && ((m3 == 1 && tr == 3) || m3==2))
		{
			bariera3();
			goto start3;
		}
		switch (stronyy)
		{
		case 1:
			if ((a + traf) >= 10)
				goto ai1;
			else if (tab[a + traf][b] == 7) {
				tab[a + traf][b] = 6;
				stronyy = 1;
				traf++;
				tr++;
			}
			else if (tab[a + traf][b] == 0) {
				tab[a + traf][b] = 8;
			}
			else if (tab[a + traf][b] == 8 || tab[a + traf][b] == 4) {
				goto ai1;
			}
			break;

		case 2:
			if ((a - traf) < 0)
				goto ai1;
			else if (tab[a - traf][b] == 7) {
				tab[a - traf][b] = 6;
				stronyy = 2;
				traf++;
				tr++;
			}
			else if (tab[a - traf][b] == 0) {
				tab[a - traf][b] = 8;
			}
			else if (tab[a - traf][b] == 8 || tab[a - traf][b] == 4) {
				goto ai1;
			}
			break;

		case 3:
			if ((b + traf) >= 10)
				goto ai1;
			else if (tab[a][b + traf] == 7) {
				tab[a][b + traf] = 6;
				stronyy = 3;
				traf++;
				tr++;
			}
			else if (tab[a][b + traf] == 0) {
				tab[a][b + traf] = 8;
			}
			else if (tab[a][b + traf] == 8 || tab[a][b + traf] == 4) {
				goto ai1;
			}
			break;

		case 4:
			if ((b - traf) < 0)
				goto ai1;
			else if (tab[a][b - traf] == 7) {
				tab[a][b - traf] = 6;
				stronyy = 4;
				traf++;
				tr++;
			}
			else if (tab[a][b - traf] == 0) {
				tab[a][b - traf] = 8;
			}
			else if (tab[a][b - traf] == 8 || tab[a][b - traf] == 4) {
				goto ai1;
			}
			break;
		}
	}


	if (traf == 1)
	{
		if (m4 == 1 && m3 == 2 && ((m2==2 && tr == 2) || m2==3))
		{
			bariera3();
			goto start3;
		}
	ai1:
		traf = 1;
		wystarczy = 0;
		if (stronyy == 1 || stronyy == 2)
		{
			for (int i = 0; i < 2; i++)
			{
				switch (i)
				{
				case 0:
					if (tab[a + traf][b] == 8 || tab[a + traf][b] == 6 || (a + traf) >= 10 || tab[a + traf][b] == 4)
						wystarczy++;
					break;
				case 1:
					if (tab[a - traf][b] == 8 || tab[a - traf][b] == 6 || (a - traf) < 0 || tab[a - traf][b] == 4)
						wystarczy++;
					break;
				}
			}
			if (wystarczy == 2)
			{
				bariera3();
				goto start3;
			}
		}
		if (stronyy == 3 || stronyy == 4)
		{
			for (int i = 0; i < 2; i++)
			{
				switch (i)
				{
				case 0:
					if (tab[a][b + traf] == 8 || tab[a][b + traf] == 6 || (b + traf) >= 10 || tab[a][b + traf] == 4)
						wystarczy++;
					break;
				case 1:
					if (tab[a][b - traf] == 8 || tab[a][b - traf] == 6 || (b - traf) < 0 || tab[a][b - traf] == 4)
						wystarczy++;
					break;
				}
			}
			if (wystarczy == 2)
			{
				bariera3();
				goto start3;
			}
		}
		if (stronyy == 0)
		{
			for (int i = 0; i < 4; i++)
			{
				switch (i)
				{
				case 0:
					if (tab[a + traf][b] == 8 || tab[a + traf][b] == 6 || (a + traf) >= 10 || tab[a + traf][b] == 4)
						wystarczy++;
					break;
				case 1:
					if (tab[a - traf][b] == 8 || tab[a - traf][b] == 6 || (a - traf) < 0 || tab[a - traf][b] == 4)
						wystarczy++;
					break;
				case 2:
					if (tab[a][b + traf] == 8 || tab[a][b + traf] == 6 || (b + traf) >= 10 || tab[a][b + traf] == 4)
						wystarczy++;
					break;
				case 3:
					if (tab[a][b - traf] == 8 || tab[a][b - traf] == 6 || (b - traf) < 0 || tab[a][b - traf] == 4)
						wystarczy++;
					break;
				}
			}
			if (wystarczy == 4)
			{
				bariera3();
				goto start3;
			}
		}

	poza:
		int strony;
		switch (stronyy)
		{
		case 0:
			strony = rand() % 4 + 1;
			break;
		case 1:
			strony = 2;
			break;
		case 2:
			strony = 1;
			break;
		case 3:
			strony = 4;
			break;
		case 4:
			strony = 3;
			break;
		}

		switch (strony)
		{
		case 1:
			if ((a + traf) >= 10)
				goto poza;
			else if (tab[a + traf][b] == 7) {
				tab[a + traf][b] = 6;
				stronyy = 1;
				traf++;
				tr++;
			}
			else if (tab[a + traf][b] == 0) {
				tab[a + traf][b] = 8;
			}
			else if (tab[a + traf][b] == 6 || tab[a + traf][b] == 8 || tab[a + traf][b] == 4) {
				goto ai1;
			}
			break;

		case 2:
			if ((a - traf) < 0)
				goto poza;
			else if (tab[a - traf][b] == 7) {
				tab[a - traf][b] = 6;
				stronyy = 2;
				traf++;
				tr++;
			}
			else if (tab[a - traf][b] == 0) {
				tab[a - traf][b] = 8;
			}
			else if (tab[a - traf][b] == 6 || tab[a - traf][b] == 8 || tab[a - traf][b] == 4) {
				goto ai1;
			}
			break;

		case 3:
			if ((b + traf) >= 10)
				goto poza;
			else if (tab[a][b + traf] == 7) {
				tab[a][b + traf] = 6;
				stronyy = 3;
				traf++;
				tr++;
			}
			else if (tab[a][b + traf] == 0) {
				tab[a][b + traf] = 8;
			}
			else if (tab[a][b + traf] == 6 || tab[a][b + traf] == 8 || tab[a][b + traf] == 4) {
				goto ai1;
			}
			break;

		case 4:
			if ((b - traf) < 0)
				goto poza;
			else if (tab[a][b - traf] == 7) {
				tab[a][b - traf] = 6;
				stronyy = 4;
				traf++;
				tr++;
			}
			else if (tab[a][b - traf] == 0) {
				tab[a][b - traf] = 8;
			}
			else if (tab[a][b - traf] == 6 || tab[a][b - traf] == 8 || tab[a][b - traf] == 4) {
				goto ai1;
			}
			break;

		}

	}
	if (traf == 0)
	{
	start3:
		if (tr == 4)
			m4 = 1;
		if (tr == 3)
			m3++;
		if (tr == 2)
			m2++;

		stronyy = 0;
		a = rand() % 10;
		b = rand() % 10;
		traf = 0;
		tr = 0;

		if (tab[a][b] == 7) {
			tab[a][b] = 6;
			traf = 1;
			tr = 1;
		}
		else if (tab[a][b] == 0) {
			tab[a][b] = 8;
		}
		else if (tab[a][b] == 6 || tab[a][b] == 8 || tab[a][b] == 4) {
			goto start3;
		}
	}
}

void bot2()
{
start3:
	a = rand() % 10;
	b = rand() % 10;

	if (tab[a][b] == 7) {
		tab[a][b] = 6;
	}
	else if (tab[a][b] == 0) {
		tab[a][b] = 8;
	}
	else if (tab[a][b] == 6 || tab[a][b] == 8) {
		goto start3;
	}

}