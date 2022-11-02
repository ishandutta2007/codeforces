#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n, m;
ll w[200009];
vi G[200009];
vi Gy[200009];
int ido;
int eler[200009];
int apa[200009];
int l[200009];
bool bejar[200009];
bool hid[200009];
bool vissza[200009];
ll dp1[200009];
ll dp2[200009];
void dfs(int x)
{
    bejar[x]=true;
    ido++;
    eler[x]=ido;
    l[x]=ido;
    for(int sz: G[x])
    {
        if(!bejar[sz])
        {
            apa[sz]=x;
            Gy[x].push_back(sz);
            dfs(sz);
            l[x]=min(l[x], l[sz]);
            if(vissza[sz]) vissza[x]=true;
        }
        else if(sz!=apa[x])
        {
            l[x]=min(l[x], eler[sz]);
        }
    }
    if(l[x]==eler[x])
    {
        hid[x]=true;
    }
    else
    {
        vissza[x]=true;
    }
}
void szamol(int x)
{
    bejar[x]=true;
    for(int sz: Gy[x])
    {
        szamol(sz);
        if(vissza[sz])
        {
            dp2[x]+=dp2[sz];
        }
    }
    for(int sz: Gy[x])
    {
        if(vissza[sz])
        {
            dp1[x]=max(dp1[x], dp2[x]-dp2[sz]+dp1[sz]);
        }
        else
        {
            dp1[x]=max(dp1[x], dp2[x]+dp1[sz]);
        }
    }
    dp1[x]+=w[x];
    dp2[x]+=w[x];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>w[i];
    }
    for(int i=1; i<=m; i++)
    {
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int kezd;
    cin>>kezd;
    dfs(kezd);
    for(int i=1; i<=n; i++)
    {
        bejar[i]=false;
    }
    szamol(kezd);
    cout<<dp1[kezd]<<endl;
    return 0;
}