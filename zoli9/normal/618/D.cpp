#include <bits/stdc++.h>
using namespace std;
long long n;
long long x, y;
long long fok[200009];
long long felh[200009];
long long sk, sv;
long long sor[200009];
long long darab;
long long atmero;
unordered_set<int> s[200009];
int main()
{
    cin>>n>>x>>y;
    for(int i=1; i<=n-1; i++)
    {
        long long a, b;
        cin>>a>>b;
        s[a].insert(b);
        s[b].insert(a);
        fok[a]++;
        fok[b]++;
    }
    bool csillag=false;
    for(int i=1; i<=n; i++)
    {
        if(fok[i]==n-1) csillag=true;
    }
    darab=0;
    sk=1;
    sv=0;
    for(int i=1; i<=n; i++)
    {
        if(fok[i]==1)
        {
            sv++;
            sor[sv]=i;
        }
    }
    while(sk<=sv)
    {
        long long akt=sor[sk];
        if(s[akt].size()==0)
        {
            sk++;
            continue;
        }
        long long szom=(*s[akt].begin());
        if(felh[akt]<2 && felh[szom]<2)
        {
            darab++;
            felh[akt]++;
            felh[szom]++;
        }
        s[akt].erase(szom);
        s[szom].erase(akt);
        if(s[szom].size()==1)
        {
            sv++;
            sor[sv]=szom;
        }
        sk++;
    }

    if(x==y)
    {
        cout<<(n-1)*x;
    }
    else if(x>y)
    {
        if(csillag)
        {
            cout<<(x+(n-2)*y);
        }
        else
        {
            cout<<(n-1)*y;
        }
    }
    else
    {
        cout<<(darab*x+(n-1-darab)*y);
    }
    return 0;
}