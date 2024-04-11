#include <bits/stdc++.h>
using namespace std;
long long MOD=998244353;
int n;
vector<int> G[200009];
bool bejar[200009];
long long dp[200009];
long long fact[200009];
void dfs(int x)
{
    bejar[x]=true;
    dp[x]=1;
    long long gyerekek=0;
    for(int sz: G[x])
    {
        if(!bejar[sz])
        {
            dfs(sz);
            gyerekek++;
            dp[x]=(dp[x]*dp[sz])%MOD;
        }
    }
    if(gyerekek==0)
    {
        dp[x]=1;
        return;
    }
    if(x==1)
    {
        dp[1]=(dp[1]*(long long)(n))%MOD;
        dp[1]=(dp[1]*fact[gyerekek])%MOD;
    }
    else
    {
        dp[x]=(dp[x]*fact[gyerekek+1])%MOD;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<n; i++)
    {
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    fact[0]=1;
    fact[1]=1;
    for(long long i=2; i<=n+1; i++)
    {
        fact[i]=(fact[i-1]*i)%MOD;
    }
    dfs(1);
    cout<<dp[1]<<endl;
    return 0;
}