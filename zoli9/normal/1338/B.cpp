#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

int n;
vi G[100009];
int szint[100009];
vi levelek;
bool was[100009];

void dfs(int x)
{
    was[x]=true;
    for(int sz: G[x])
    {
        if(!was[sz])
        {
            szint[sz]=szint[x]+1;
            dfs(sz);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<n; i++)
    {
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i=1; i<=n; i++)
    {
        if(G[i].size()==1)
        {
            levelek.push_back(i);
        }
    }
    szint[1]=0;
    dfs(1);
    int ans1=1;
    for(int i=1; i<levelek.size(); i++)
    {
        if(szint[levelek[i]]%2!=szint[levelek[0]]%2) ans1=3;
    }
    int ans2=n-1;
    for(int i=1; i<=n; i++)
    {
        if(G[i].size()==1) continue;
        int numleaf=0;
        for(int sz: G[i])
        {
            if(G[sz].size()==1) numleaf++;
        }
        if(numleaf>1)
        {
            ans2-=(numleaf-1);
        }
    }
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}