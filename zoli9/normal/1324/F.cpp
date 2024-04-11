#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int cl[200009];
vi G[200009];
int down[200009];
int up[200009];
int was[200009];
int wcnt;
int n;

void dfs(int x)
{
    was[x]=wcnt;
    down[x]=cl[x];
    for(int sz: G[x])
    {
        if(was[sz]<wcnt)
        {
            dfs(sz);
            down[x]+=max(0, down[sz]);
        }
    }
}

void dfs2(int x)
{
    was[x]=wcnt;
    for(int sz: G[x])
    {
        if(was[sz]<wcnt)
        {
            up[sz]=down[x]+up[x];
            if(down[sz]>0) up[sz]-=down[sz];
            up[sz]=max(up[sz], 0);
            dfs2(sz);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>cl[i];
        if(cl[i]==0) cl[i]--;
    }
    for(int i=1; i<n; i++)
    {
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    wcnt++;
    dfs(1);
    wcnt++;
    dfs2(1);
    for(int i=1; i<=n; i++)
    {
        cout<<down[i]+up[i]<<" ";
        //cout<<down[i]<<" ";
    }
    cout<<endl;


    return 0;
}