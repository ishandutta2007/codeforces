#include <bits/stdc++.h>
using namespace std;
int n, m;
int cnt=0;
int t[109][109];
int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            char d;
            cin>>d;
            t[i][j]=d-'0';
        }
    }
    for(int i=1; i<=n; i++)
    {
        bool jo=false;
        for(int j=1; j<=m; j++)
        {
            bool aa=true;
            for(int k=1; k<=n; k++)
            {
                if(t[k][j]>t[i][j]) aa=false;
            }
            if(aa)
            {
                jo=true;
                break;
            }
        }
        if(jo) cnt++;
    }
    cout<<cnt;
    return 0;
}