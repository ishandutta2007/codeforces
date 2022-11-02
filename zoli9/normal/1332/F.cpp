#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

ll MOD=998244353;

ll felpiros[300009];
ll piros[300009];
ll feher[300009];
ll prodfeher[300009];
vi G[300009];
int n;
int dad[300009];

void dfs(int x)
{
    bool leaf=true;
    for(int sz: G[x])
    {
        if(dad[x]!=sz)
        {
            dad[sz]=x;
            leaf=false;
            dfs(sz);
        }
    }
    if(leaf)
    {
        piros[x]=0;
        felpiros[x]=1;
        feher[x]=1;
        return;
    }
    felpiros[x]=1;
    feher[x]=1;
    prodfeher[x]=1;
    for(int sz: G[x])
    {
        if(dad[x]==sz) continue;
        felpiros[x]=(felpiros[x]*((2*feher[sz]+piros[sz])%MOD))%MOD;
        prodfeher[x]=(prodfeher[x]*(feher[sz]+piros[sz]))%MOD;
        feher[x]=(feher[x]*((2*feher[sz]+piros[sz]+felpiros[sz])%MOD))%MOD;
    }
    piros[x]=(felpiros[x]-prodfeher[x]+MOD)%MOD;
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
    dfs(1);
    /*for(int i=1; i<=n; i++)
    {
        cout<<i<<endl;
        cout<<"feher: "<<feher[i]<<" piros: "<<piros[i]<<" felpiros: "<<felpiros[i]<<endl;
    }*/
    cout<<(piros[1]+feher[1]-1+MOD)%MOD<<endl;

    return 0;
}