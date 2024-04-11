#include <iostream>
using namespace std;
int n, m, k;
bool v[1002][1002];
bool jo=false;
int ertek;
int main()
{
    cin>>n>>m>>k;
    if(n==1 || m==1)
    {
        jo=true;
        ertek=0;

    }
    for(int i=0; i<=n+1; i++)
    {
        for(int j=0; j<=m+1; j++)
        {
            v[i][j]=false;
        }
    }
    for(int i=1; i<=k; i++)
    {
        int a, b;
        cin>>a>>b;
        v[a][b]=true;

        if(v[a][b-1] && v[a-1][b] && v[a-1][b-1])
        {
            if(!jo)
            {
                jo=true;
                ertek=i;
            }
        }

        if(v[a][b+1] && v[a+1][b] && v[a+1][b+1])
        {
            if(!jo)
            {
                jo=true;
                ertek=i;
            }
        }


        if(v[a][b-1] && v[a+1][b] && v[a+1][b-1])
        {
            if(!jo)
            {
                jo=true;
                ertek=i;
            }
        }

        if(v[a][b+1] && v[a-1][b] && v[a-1][b+1])
        {
            if(!jo)
            {
                jo=true;
                ertek=i;
            }
        }
    }

if(jo)
{
    cout<<ertek;
    return 0;
}
    cout<<0;
    return 0;
}