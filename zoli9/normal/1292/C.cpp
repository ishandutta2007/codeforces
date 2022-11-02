#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
vi G[3009];
int n;
ll dp[3009][3009];
int apa[3009][3009];
int subtree[3009][3009];
//int tav[3009][3009];
int root;
int colour[3009];
int dfsnum;

void dfs(int x)
{
    colour[x]=dfsnum;
    subtree[root][x]++;
    for(int sz: G[x])
    {
        if(colour[sz]<dfsnum)
        {
            apa[root][sz]=x;
            //tav[root][sz]=tav[root][x]+1;
            dfs(sz);
            subtree[root][x]+=subtree[root][sz];
        }
    }
}

ll calc(int i, int j)
{
    if(dp[i][j]>0) return dp[i][j];
    if(dp[j][i]>0) return dp[j][i];
    ll plusz=(ll)(subtree[i][j])*(ll)(subtree[j][i]);
    if(apa[i][j]==i)
    {
        return dp[i][j]=plusz;
    }
    dp[i][j]=max(calc(i, apa[i][j]), calc(j, apa[j][i]));
    dp[i][j]+=plusz;
    return dp[i][j];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<n; i++)
    {
        int aa, bb;
        cin>>aa>>bb;
        G[aa].push_back(bb);
        G[bb].push_back(aa);
    }
    for(int i=1; i<=n; i++)
    {
        root=i;
        dfsnum++;
        dfs(i);
    }
    ll ans=1;
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            //cout<<i<<"-"<<j<<": "<<calc(i, j)<<endl;
            ans=max(ans, calc(i, j));
        }
    }
    cout<<ans<<endl;
    return 0;
}