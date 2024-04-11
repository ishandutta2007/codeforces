#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//(double)clock() / CLOCKS_PER_SEC;
int n, m;
vi G[300009];
bool vis[300009];
int col[300009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        cin>>n>>m;
        for(int i=1; i<=n; i++)
        {
            G[i].clear();
            vis[i]=false;
            col[i]=0;
        }
        for(int i=1; i<=m; i++)
        {
            int a, b;
            cin>>a>>b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        vi ans;
        queue<int> Q;
        Q.push(1);
        vis[1]=true;
        while(Q.size()>0)
        {
            int cur=Q.front();
            Q.pop();
            col[cur]=1;
            for(int nb: G[cur])
            {
                if(vis[nb])
                {
                    if(col[nb]) col[cur]=0;
                }
                else
                {
                    Q.push(nb);
                    vis[nb]=true;
                }
            }
            if(col[cur]==1) ans.push_back(cur);
        }
        bool ok=true;
        for(int i=1; i<=n; i++)
        {
            if(!vis[i])
            {
                ok=false;
                break;
            }
        }
        if(ok)
        {
            cout<<"YES"<<'\n';
            cout<<ans.size()<<'\n';
            for(int x: ans) cout<<x<<" ";
            cout<<'\n';
        }
        else
        {
            cout<<"NO"<<'\n';
        }
    }
    return 0;
}