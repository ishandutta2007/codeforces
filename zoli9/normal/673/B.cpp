#include <bits/stdc++.h>
using namespace std;
int n, m;
int hol[100009];
int main()
{
    cin>>n>>m;
    hol[1]=1;
    hol[n]=2;
    for(int i=1; i<=m; i++)
    {
        int a, b;
        cin>>a>>b;
        int x=min(a, b);
        int y=max(a, b);
        if(hol[x]==2)
        {
            cout<<0;
            return 0;
        }
        if(hol[y]==1)
        {
            cout<<0;
            return 0;
        }
        hol[x]=1;
        hol[y]=2;
    }
    int utegy=1, elket=n;
    for(int i=1; i<=n; i++)
    {
        if(hol[i]==1) utegy=i;
    }
    for(int i=n; i>=1; i--)
    {
        if(hol[i]==2) elket=i;
    }
    if(utegy>=elket)
    {
        cout<<0;
        return 0;
    }
    cout<<elket-utegy;
    return 0;
}