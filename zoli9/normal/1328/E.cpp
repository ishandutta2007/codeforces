#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int n, m;
int reach[200009];
int leave[200009];
int dad[200009];
bool visited[200009];
int t;
vi G[200009];
void dfs(int x)
{
    t++;
    reach[x]=t;
    visited[x]=true;
    for(int sz: G[x])
    {
        if(!visited[sz])
        {
            dad[sz]=x;
            dfs(sz);
        }
    }
    leave[x]=t;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        G[i].clear();
        visited[i]=false;
    }
    t=0;
    for(int i=1; i<n; i++)
    {
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1);
    for(int i=1; i<=m; i++)
    {
        int numM;
        cin>>numM;
        int ans;
        cin>>ans;
        if(ans!=1) ans=dad[ans];
        bool ok=true;
        for(int j=2; j<=numM; j++)
        {
            int node;
            cin>>node;
            if(node!=1) node=dad[node];
            if(reach[node]<=reach[ans] && leave[ans]<=leave[node]) continue;
            if(reach[ans]<=reach[node] && leave[node]<=leave[ans])
            {
                ans=node;
            }
            else
            {
                ok=false;
            }
        }
        if(ok) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }


    return 0;
}