#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n, m;
int test;
vector<int> G[1000009];
vector<int> V[1000009];
int was[1000009];
int was2[1000009];
int wcnt, wcnt2;
int db;
int hagy;
void dfs(int x)
{
    was[x]=wcnt;
    for(int sz: G[x]) if(was[sz]<wcnt) dfs(sz);
    hagy=x;
}
void dfs2(int x)
{
    db++;
    was2[x]=wcnt2;
    for(int sz: V[x]) if(was2[sz]<wcnt2) dfs2(sz);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n>>m;
        wcnt++;
        for(int i=1; i<=n; i++)
        {
            G[i].clear();
            V[i].clear();
        }
        for(int i=1; i<=m; i++)
        {
            int a, b;
            cin>>a>>b;
            G[a].push_back(b);
            V[b].push_back(a);
        }
        hagy=0;
        for(int i=1; i<=n; i++)
        {
            if(was[i]<wcnt) dfs(i);
        }
        wcnt2++;
        db=0;
        dfs2(hagy);
        if(db==n || db==0)
        {
            cout<<"No"<<endl;
            continue;
        }
        cout<<"Yes"<<endl;
        cout<<n-db<<" "<<db<<endl;
        for(int i=1; i<=n; i++) if(was2[i]!=wcnt2) cout<<i<<" ";
        cout<<endl;
        for(int i=1; i<=n; i++) if(was2[i]==wcnt2) cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}