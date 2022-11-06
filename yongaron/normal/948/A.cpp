#include <iostream>

using namespace std;

char pole[505][505];
int r, c, dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

int main()
{
    ios::sync_with_stdio(0);
    cin>>r>>c;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cin>>pole[i][j];
            if(pole[i][j] == '.')
                pole[i][j] = 'D';
        }
    }
    bool ok = true;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            for(int l = 0; l < 4; l++)
            {
                if(pole[i][j] == 'S' && i+dy[l] >= 0 && i+dy[l] < r && j+dx[l] >= 0 && j+dx[l] < c)
                {
                    if(pole[i+dy[l]][j+dx[l]] == 'W')
                        ok = false;
                }
            }
        }
    }
    if(!ok)
    {
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cout<<pole[i][j];
        }
        cout<<endl;
    }
    return 0;
}

/*

6 6
..S...
..S.W.
.S....
..W...
...W..
...S..

*/