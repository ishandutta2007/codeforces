#include <bits/stdc++.h>
using namespace std;
int n;
int p[59][59];
int valasz[59];
bool foglalt[59];
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin>>p[i][j];
        }
        p[i][i]=1;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(foglalt[j]) continue;
            bool jo=true;
            for(int k=1; k<=n; k++)
            {
                if(p[j][k]>i)
                {
                    jo=false;
                    break;
                }
            }
            if(jo)
            {
                valasz[j]=i;
                for(int k=1; k<=n; k++)
                {
                    p[j][k]=i+1;
                    p[k][j]=i+1;
                }
                foglalt[j]=true;
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        cout<<valasz[i]<<" ";
    }
    return 0;
}