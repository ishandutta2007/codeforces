#include <bits/stdc++.h>

using namespace std;
#define fi first
#define se second

map<int,int> L;
map<int,int> R;
map<int,int> both;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=0;i<n;i++)
    {
        int u,v; cin>>u>>v;
        L[u]++; R[v]++; L[v]+=0;
        if(u==v) both[u]++;
    }
    int ans=  int(1e9);
    for(auto it = L.begin(); it != L.end(); it++)
    {
        int col = it->fi; int cnt = it->se;
        int cnt2 = R[col];
        int res = both[col];
        cnt-=res; cnt2-=res;
        if(res+cnt+cnt2>=(n+1)/2)
        {
            ans = min(ans, max(0, (n+1)/2 - res - cnt));
        }
    }
    if(ans>=int(1e9)) cout<<-1<<'\n';
    else cout<<ans<<'\n';
}