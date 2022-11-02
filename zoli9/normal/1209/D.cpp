#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n, m;
bool w[100009];
vi G[100009];
void dfs(int x)
{
    w[x]=true;
    for(int sz: G[x]) if(!w[sz]) dfs(sz);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int ans=n;
    for(int i=1; i<=n; i++)
    {
        if(!w[i])
        {
            ans--;
            dfs(i);
        }
    }
    cout<<m-ans<<endl;
    return 0;
}