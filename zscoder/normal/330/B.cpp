#include <bits/stdc++.h>

using namespace std;

bool used[111111];
int main()
{
    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v; cin>>u>>v; used[u]=used[v]=1;
    }
    cout<<n-1<<'\n';
    int idx=-1;
    for(int i=1;i<=n;i++)
    {
        if(!used[i]) idx=i;
    }
    for(int i=1;i<=n;i++)
    {
        if(i!=idx) cout<<idx<<' '<<i<<'\n';
    }
}