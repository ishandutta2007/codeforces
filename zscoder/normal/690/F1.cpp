#include<bits/stdc++.h>
using namespace std;
int d[10001];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        int u, v; cin>>u>>v;
        d[u]++; d[v]++;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans += ((d[i])*(d[i] - 1))/2;
    }
    cout<<ans;
}