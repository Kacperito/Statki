#include <iostream>
#include <time.h>
#include <cstdlib>
#include <conio.h>

using namespace std;
void wodowanie(int o);
void wodowanie2(int o);
void bariera();
void bariera2();
void wyswietlacz();
void sprawdzaczbat();
void sprawdzacztab();
int tab[10][10];
int bat[10][10];
int  y, x, rama2;
char rama;
int  a, b;
int win=0;


int main()
{
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            tab[i][j] = 0;
        }
    }
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            bat[i][j] = 0;
        }
    }


    wodowanie(4);
    bariera();
    //cout<<"done 4"<<endl;
    for (int i=0;i<2;i++)
    {
        wodowanie(3);
        bariera();
    }
    //cout<<"done 3"<<endl;
    for (int i=0;i<3;i++)
    {
        wodowanie(2);
        bariera();
    }
    //cout<<"done 2"<<endl;
    for (int i=0;i<4;i++)
    {
        wodowanie(1);
        bariera();
    }
    //cout<<"done 1"<<endl;


    wodowanie2(4);
    bariera2();
    //cout<<"done 4"<<endl;
    for (int i=0;i<2;i++)
    {
        wodowanie2(3);
        bariera2();
    }
    //cout<<"done 3"<<endl;
    for (int i=0;i<3;i++)
    {
        wodowanie2(2);
        bariera2();
    }
    //cout<<"done 2"<<endl;
    for (int i=0;i<4;i++)
    {
        wodowanie2(1);
        bariera2();
    }
    //cout<<"done 1"<<endl;



    cout<<"open fire"<<endl;
    srand(time(NULL));
while (true)
{
    wyswietlacz();

    cout<<"wprowadz litere wiersza:";
    start2:
    rama=getch();
        if(rama== 'a' || rama=='A')
            x=1;
        else if(rama== 'b' || rama=='B')
            x=2;
        else if(rama== 'c' || rama=='C')
            x=3;
        else if(rama== 'd' || rama=='D')
            x=4;
        else if(rama== 'e' || rama=='E')
            x=5;
        else if(rama== 'f' || rama=='F')
            x=6;
        else if(rama== 'g' || rama=='G')
            x=7;
        else if(rama== 'h' || rama=='H')
            x=8;
        else if(rama== 'i' || rama=='I')
            x=9;
        else if(rama== 'j' || rama=='J')
            x=10;
        else {
            cout << "wprowadz poprawna litere mordo" << endl;
            goto start2;
        }
        cout<<"wprowadz liczbe kolumny:";
        start7:
        while((cin>>rama2))
        {
            if(rama2<0 || rama2>11) {
                cout << "liczbe z zakresu byq" << endl;
                goto start7;
            }
            else
                y=rama2;
        }
        cout<<y<<endl;
        x--;
        y--;

    if (bat[x][y] == 7) {
        cout << "essa" << endl;
        bat[x][y] = 6;
    } else if (bat[x][y] == 0) {
        cout << "l2p" << endl;
        bat[x][y] = 8;
    } else if (bat[x][y] == 6 || bat[x][y] == 8) {
        cout << "wariacie juz tu strzelales" << endl;
        goto start2;
    }
    sprawdzaczbat();
    if (win == 0)
        return 0;

    start3:
    a = rand() % 10;
    b = rand() % 10;
    int traf = 0;

    if (tab[a][b] == 7) {
        cout << "jebany farciarz" << endl;
        tab[a][b] = 6;
        traf = 1;
    } else if (tab[a][b] == 0) {
        cout << "ez" << endl;
        tab[a][b] = 8;
    } else if (tab[a][b] == 6 || tab[a][b] == 8) {
        goto start3;
    }
    sprawdzacztab();
    if (win == 0)
        return 0;

    //system("cls");
}











    return 0;
}

void wodowanie(int o)
{
    srand(time(NULL));
    int r, d, p;

        start:
        int l=0;
        r = rand() % 10;
        d = rand() % 10;
        p = rand() % 2 + 1;
      //  cout << r << " " << d << " " <<p<< endl;

    if (p==1) {
        if (r + o < 10) {
            for (int i = 0; i < o; i++) {
                if (tab[r + i][d] == 0) {
                    l++;
                    //cout << l << endl;
                } else
                    goto start;
            }
                for (int i = 0; i < o; i++)
                    tab[r + i][d] = 7;

        }
        else goto start;
    }
    else if (p==2){
            if (d + o < 10) {
                for (int i = 0; i < o; i++) {
                    if (tab[r][d + i] == 0) {
                        l++;
                        //cout<<l<<endl;
                    } else goto start;
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
    int l=0;
    r = rand() % 100;
    d = rand() % 100;
    p = rand() % 2 + 1;
    r2 = rand() % 10;
    d2 = rand() % 10;
    r=(r*r2)%10;
    d=(d*d2)%10;
    //cout << r << " " << d << " " <<p<< endl;

    if (p==1) {
        if (r + o < 10) {
            for (int i = 0; i < o; i++) {
                if (bat[r + i][d] == 0) {
                    l++;
                    //cout << l << endl;
                } else
                    goto start;
            }
            for (int i = 0; i < o; i++)
                bat[r + i][d] = 7;

        }
        else goto start;
    }
    else if (p==2){
        if (d + o < 10) {
            for (int i = 0; i < o; i++) {
                if (bat[r][d + i] == 0) {
                    l++;
                    //cout<<l<<endl;
                } else goto start;
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
                        if (tab[i + y][j + x] == -1 || tab[i + y][j + x] == 0) {
                            if (0 <= (i + y) && (i + y) < 10 && 0 <= (j + x) && (j + x) < 10)
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
                            if (bat[i + y][j + x] == -1 || bat[i + y][j + x] == 0) {
                                if (0 <= (i + y) && (i + y) < 10 && 0 <= (j + x) && (j + x) < 10)
                                    bat[i + y][j + x] = -1;
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
        //system ("cls");
        for (int i = 0; i < 11; i++) {
            ramy[i] = i;
            cout << ramy[i] << "  ";
        }
        cout<<endl;

        for (int i = 0; i < 10; i++)
        {
            switch (i)
            {
                case 0:
                    cout<< "A"<<" ";
                    break;
                case 1:
                    cout<< "B"<<" ";
                    break;
                case 2:
                    cout<< "C"<<" ";
                    break;
                case 3:
                    cout<< "D"<<" ";
                    break;
                case 4:
                    cout<< "E"<<" ";
                    break;
                case 5:
                    cout<< "F"<<" ";
                    break;
                case 6:
                    cout<< "G"<<" ";
                    break;
                case 7:
                    cout<< "H"<<" ";
                    break;
                case 8:
                    cout<< "I"<<" ";
                    break;
                case 9:
                    cout<< "J"<<" ";
                    break;
            }
            for (int j = 0; j < 10; j++)
            {
                cout.width(2);
                switch(bat[i][j])
                {
                    case 0:
                        cout<<bat[i][j]<< " ";
                        break;
                    case -1:
                        bat[i][j] = 0;
                        cout<<bat[i][j]<< " ";
                        break;
                    case 7:
                        cout << "0" << " ";
                        break;
                    case 6:
                        cout<< "+" << " ";
                        break;
                    case 8:
                        cout<< "-" << " ";
                        break;
                }


            }
            cout << endl;
        }

        cout<<endl<<endl;

        for (int i = 0; i < 11; i++) {
            cout << ramy[i] << "  ";
        }
        cout<<endl;

        for (int i = 0; i < 10; i++)
        {
            switch (i)
            {
                case 0:
                    cout<< "A"<<" ";
                    break;
                case 1:
                    cout<< "B"<<" ";
                    break;
                case 2:
                    cout<< "C"<<" ";
                    break;
                case 3:
                    cout<< "D"<<" ";
                    break;
                case 4:
                    cout<< "E"<<" ";
                    break;
                case 5:
                    cout<< "F"<<" ";
                    break;
                case 6:
                    cout<< "G"<<" ";
                    break;
                case 7:
                    cout<< "H"<<" ";
                    break;
                case 8:
                    cout<< "I"<<" ";
                    break;
                case 9:
                    cout<< "J"<<" ";
                    break;
            }
            for (int j = 0; j < 10; j++)
            {
                cout.width(2);
                switch(tab[i][j])
                {
                    case 0:
                        cout<<tab[i][j]<< " ";
                        break;
                    case -1:
                        tab[i][j] = 0;
                        cout<<tab[i][j]<< " ";
                        break;
                    case 7:
                        cout<<tab[i][j]<< " ";
                        break;
                    case 6:
                        cout<< "+" << " ";
                        break;
                    case 8:
                        cout<< "-" << " ";
                        break;
                }
            }
            cout << endl;
        }

    }


    void sprawdzacztab() {
    win=0;
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                if (tab[i][j]==7)
                    win++;
            }
        }
        if(win==0)
            cout<<"defeat"<<endl;
        }

        void sprawdzaczbat()
        {
    win=0;
            for(int i=0;i<10;i++)
            {
                for(int j=0;j<10;j++)
                {
                    if (bat[i][j]==7)
                        win++;
                }
            }
            if(win==0)
                cout<<"Victory"<<endl;
        }