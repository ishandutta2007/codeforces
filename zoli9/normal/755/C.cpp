#include <bits/stdc++.h>
using namespace std;
int n;
int ans=0;
bool bejar[10009];
vector<int> G[10009];
void dfs(int x)
{
    bejar[x]=true;
    for(int sz: G[x]) if(!bejar[sz]) dfs(sz);
}
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int a;
        cin>>a;
        G[i].push_back(a);
        G[a].push_back(i);
    }
    for(int i=1; i<=n; i++)
    {
        if(!bejar[i])
        {
            ans++;
            dfs(i);
        }
    }
    cout<<ans<<endl;
    return 0;
}