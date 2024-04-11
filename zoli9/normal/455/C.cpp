#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int n, m, q;
int apa[300009];
int melyseg[300009];
int atmero[300009];
int szint[300009];
vector<int> p[300009];
bool bejar[300009];
bool bejar2[300009];
int sor[300009];
int sk, sv, akt;
int unio(int x, int y)
{
    if(melyseg[x]>melyseg[y])
    {
        apa[y]=x;
    }
    else if(melyseg[y]>melyseg[x])
    {
        apa[x]=y;
    }
    else
    {
        apa[x]=y;
        melyseg[y]++;
    }
    return 0;
}
int unio2(int x, int y) // atmero valtoztat
{
    int uj;
    uj=max(max(atmero[x], atmero[y]), (atmero[x]+1)/2+(atmero[y]+1)/2+1); // uj atmero hossza
    if(melyseg[x]>melyseg[y])
    {
        apa[y]=x;
        atmero[x]=uj;
    }
    else if(melyseg[y]>melyseg[x])
    {
        apa[x]=y;
        atmero[y]=uj;
    }
    else
    {
        apa[x]=y;
        melyseg[y]++;
        atmero[y]=uj;
    }
    return 0;
}
int holvan(int x)
{
    if(apa[x]==-1) return x;
    int y=holvan(apa[x]);
    apa[x]=y;
    return y;
    // return apa[x]=holvan(apa[x]);
}
int main()
{
    cin>>n>>m>>q;
    for(int i=1; i<=n; i++)
    {
        apa[i]=-1;
        melyseg[i]=1;
    }
    for(int i=1; i<=m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        p[a].push_back(b);
        p[b].push_back(a);
        if(holvan(a)!=holvan(b)) unio(holvan(a), holvan(b));
    }
    for(int i=1; i<=n; i++)
    {
        if(!bejar[i])
        {
            sk=1;
            sv=1;
            sor[1]=i;
            szint[i]=0;
            bejar[i]=true;
            while(sk<=sv)
            {
                akt=sor[sk];
                for(int j=0; j<p[akt].size(); j++)
                {
                    int sz=p[akt][j];
                    if(!bejar[sz])
                    {
                        sv++;
                        sor[sv]=sz;
                        szint[sz]=szint[akt]+1;
                        bejar[sz]=true;
                    }
                }
                sk++;
            }
            sk=1;
            sv=1;
            bejar2[akt]=true;
            sor[1]=akt;
            szint[akt]=0;
            while(sk<=sv)
            {
                akt=sor[sk];
                for(int j=0; j<p[akt].size(); j++)
                {
                    int sz=p[akt][j];
                    if(!bejar2[sz])
                    {
                        sv++;
                        sor[sv]=sz;
                        szint[sz]=szint[akt]+1;
                        bejar2[sz]=true;
                    }
                }
                sk++;
            }
            atmero[holvan(i)]=szint[akt];
            //cout<<szint[akt]<<" ";
        }
    }
    for(int i=1; i<=q; i++)
    {
        int d, e, f;
        scanf("%d", &d);
        scanf("%d", &e);
        if(d==1)
        {
            printf("%d\n", atmero[holvan(e)]);
        }
        else
        {
            scanf("%d", &f);
            if(holvan(e)!=holvan(f)) unio2(holvan(e), holvan(f));
        }
    }
    return 0;
}