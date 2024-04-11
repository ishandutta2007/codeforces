#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n, m;
bool kesz=false;
string s[60];
bool bejar[60][60];

int mely(int x, int y)
{

    bejar[x][y]=true;
    int db=0;
    for(int i=x-1; i<=x+1; i++)
    {
        for(int j=y-1; j<=y+1; j++)
        {
            if(abs(i-x)+abs(j-y)==1)
            {
                if(i>=0 && i<n && j>=0 && j<m)
                {
                    if(s[i][j]==s[x][y])
                    {
                        if(bejar[i][j])
                        {
                           db++;
                           if(db==2)
                           {

                               kesz=true;
                               return 0;
                           }
                        }
                        else
                           {
                               mely(i, j);
                           }
                    }
                }
            }
        }
    }
    return 0;
}

int main()
{
    //freopen("be2.txt", "r", stdin);
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        cin>>s[i];
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(!bejar[i][j] && !kesz)
            {
                mely(i, j);
            }
        }
    }
    if(!kesz)
    {
        cout<<"No";
        return 0;
    }
cout<<"Yes";
    return 0;
}