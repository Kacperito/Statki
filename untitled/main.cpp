#include <iostream>
#include <time.h>
#include <cstdlib>



using namespace std;
void wodowanie(int o);
void bariera();
int tab[10][10];

int main()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            tab[i][j] = 0;
            cout.width(2);
            cout << tab[i][j]<<" ";
        }
        cout<<endl;
    }

    wodowanie(4);
    bariera();
    cout<<"done 4"<<endl;
    for (int i=0;i<2;i++)
    {
        wodowanie(3);
        bariera();
    }
    cout<<"done 3"<<endl;
    for (int i=0;i<3;i++)
    {
        wodowanie(2);
        bariera();
    }
    cout<<"done 2"<<endl;
    for (int i=0;i<4;i++)
    {
        wodowanie(1);
        bariera();
    }
    cout<<"done 1"<<endl;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout.width(2);
            if (tab[i][j]==-1)
                tab[i][j]=0;
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }



    return 0;
}

void wodowanie(int o)
{
    srand(time(NULL));
    int r, d, a;

        start:
        int l=0;
        r = rand() % 10;
        d = rand() % 10;
        a = rand() % 2 + 1;
        cout << r << " " << d << " " <<a<< endl;

    if (a==1) {
        if (r + o < 10) {
            for (int i = 0; i < o; i++) {
                if (tab[r + i][d] == 0) {
                    l++;
                    cout << l << endl;
                } else
                    goto start;
            }
                for (int i = 0; i < o; i++)
                    tab[r + i][d] = 7;

        }
        else goto start;
    }
    else if (a==2){
            if (d + o < 10) {
                for (int i = 0; i < o; i++) {
                    if (tab[r][d + i] == 0) {
                        l++;
                        cout<<l<<endl;
                    } else goto start;
                }
                    for (int i = 0; i < o; i++)
                        tab[r][d + i] = 7;

            }
            else goto start;
        }
}

void bariera()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (tab[i][j] == 7)
            {
                for (int y = -1; y < 2; y++)
                {
                    for (int x = -1; x < 2; x++)
                    {
                        if (tab[i+y][j+x]==-1 || tab[i+y][j+x]==0)
                        {
                            if (0<=(i+y) && (i+y)<10 && 0<=(j+x) && (j+x)<10)
                                tab[i + y][j + x] = -1;
                        }
                    }

                }
            }
        }
        cout << endl;
    }


}