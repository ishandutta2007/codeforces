#include <iostream>

using namespace std;

char pole[10][10];

void nacti();
void vyres();

int main()
{
    nacti();
    vyres();
    return 0;
}

void nacti()
{
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            cin>>pole[i][j];
}
void vyres()
{
    int x;
    int o;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(j < 6)
            {
                x = o = 0;
                for(int k = j, h = 0; k < 10, h < 5; k++, h++)
                {
                    if(pole[i][k] == 'X')
                        x++;
                    else if(pole[i][k] == 'O')
                        o++;
                }
                if(x == 4 && o == 0)
                {
                    cout<<"YES"<<endl;
                    return;
                }
            }
            if(i < 6)
            {
                x = o = 0;
                for(int k = i, h = 0; h < 5; k++, h++)
                {
                    if(pole[k][j] == 'X')
                        x++;
                    else if(pole[k][j] == 'O')
                        o++;
                }
                if(x == 4 && o == 0)
                {
                    cout<<"YES"<<endl;
                    return;
                }
            }
            if(i < 6 && j < 6)
            {
                x = o = 0;
                for(int k = i, l = j, h = 0; h < 5; k++, l++, h++)
                {
                    if(pole[k][l] == 'X')
                        x++;
                    else if(pole[k][l] == 'O')
                        o++;
                }
                if(x == 4 && o == 0)
                {
                    cout<<"YES"<<endl;
                    return;
                }
            }
            if(i < 6 && j > 3)
            {
                x = o = 0;
                for(int k = i, l = j, h = 0; h < 5; k++, l--, h++)
                {
                    if(pole[k][l] == 'X')
                        x++;
                    else if(pole[k][l] == 'O')
                        o++;
                }
                if(x == 4 && o == 0)
                {
                    cout<<"YES"<<endl;
                    return;
                }
            }
        }
    }
    cout<<"NO"<<endl;
}