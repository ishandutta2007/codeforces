#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int test;
vi G[300009];
bool bejar[300009];
int ans;
int n;
int dfs(int x)
{
    bejar[x]=true;
    int w=(int)(G[x].size())-1;
    ans=max(ans, w+2);
    for(int sz: G[x])
    {
        if(bejar[sz]) continue;
        int ws=dfs(sz);
        ans=max(ans, w+ws+2);
        w=max(w, ws+(int)(G[x].size())-1);
    }
    return w;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n;
        ans=0;
        for(int i=1; i<=n; i++)
        {
            G[i].clear();
            bejar[i]=false;
        }
        for(int i=1; i<n; i++)
        {
            int a, b;
            cin>>a>>b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        dfs(1);
        cout<<ans<<endl;
    }


    return 0;
}