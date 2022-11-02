#include <bits/stdc++.h>
using namespace std;
int n, m;
int tav[1009][1009];
int s, b, KK, HH;
struct Ship
{
    int lo;
    int att;
    int fuel;
};
Ship ships[1009];
struct Base
{
    int lo;
    int def;
};
Base bases[1009];
bool sikerul(Ship ss, Base bb)
{
    return ss.att>=bb.def && ss.fuel>=tav[ss.lo][bb.lo];
}
vector<int> G[2009];
int Par[2009];
int bejarSzamol;
int bejar[2009];
int parositas;
bool utnoveles(int x)
{
    bejar[x]=bejarSzamol;
    for(int sz: G[x])
    {
        if(bejar[sz]<bejarSzamol)
        {
            bejar[sz]=bejarSzamol;
            if(Par[sz]==sz || utnoveles(Par[sz]))
            {
                Par[sz]=x;
                Par[x]=sz;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            tav[i][j]=-1;
        }
        tav[i][i]=0;
    }
    for(int i=1; i<=m; i++)
    {
        int a, b;
        cin>>a>>b;
        if(a!=b)
        {
            tav[a][b]=1;
            tav[b][a]=1;
        }
    }
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(tav[i][k]>=0 && tav[k][j]>=0)
                {
                    if(tav[i][j]==-1 || tav[i][j]>tav[i][k]+tav[k][j]) tav[i][j]=tav[i][k]+tav[k][j];
                }
            }
        }
    }
    cin>>s>>b>>KK>>HH;
    for(int i=1; i<=s; i++)
    {
        cin>>ships[i].lo>>ships[i].att>>ships[i].fuel;
    }
    for(int i=1; i<=b; i++)
    {
        cin>>bases[i].lo>>bases[i].def;
    }
    for(int i=1; i<=s; i++)
    {
        for(int j=1; j<=b; j++)
        {
            if(sikerul(ships[i], bases[j]))
            {
                G[i].push_back(s+j);
                G[s+j].push_back(i);
            }
        }
    }
    for(int i=1; i<=s+b; i++)
    {
        Par[i]=i;
    }
    for(int i=1; i<=s; i++)
    {
        bejarSzamol++;
        if(utnoveles(i))
        {
            parositas++;
        }
    }
    long long opcio0=(long long)(parositas)*(long long)(KK);
    long long opcios=(long long)(s)*(long long)(HH);
    cout<<min(opcio0, opcios)<<endl;
    return 0;
}