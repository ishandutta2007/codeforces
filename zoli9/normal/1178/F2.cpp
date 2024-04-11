#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll MOD=998244353;
int n, m;
ll dp[1009][1009];
bool dpvolt[1009][1009];
int mini[1009][1009];
vector<int> szin;
vector<int> elso;
vector<int> utolso;

ll calc(int x, int y)
{
    if(y<x) return 1LL;
    if(dpvolt[x][y]) return dp[x][y];
    dpvolt[x][y]=true;
    if(x==y)
    {
        if(elso[szin[x]]==x && utolso[szin[x]]==x)
        {
            return dp[x][y]=1;
        }
        else
        {
            return dp[x][y]=0;
        }
    }
    ll leftopt=0;
    ll rightopt=0;
    int c=mini[x][y];
    for(int i=x; i<=elso[c]; i++)
    {
        ll leftakt=(calc(x, i-1)*calc(i, elso[c]-1))%MOD;
        leftopt=(leftopt+leftakt)%MOD;
    }
    for(int j=utolso[c]; j<=y; j++)
    {
        ll rightakt=(calc(utolso[c]+1, j)*calc(j+1, y))%MOD;
        rightopt=(rightopt+rightakt)%MOD;
    }
    if(leftopt==0 || rightopt==0)
    {
        return dp[x][y]=0;
    }
    dp[x][y]=1;
    int elozo=elso[c];
    for(int i=elso[c]+1; i<=utolso[c]; i++)
    {
        if(szin[i]==c)
        {
            dp[x][y]=(dp[x][y]*calc(elozo+1, i-1))%MOD;
            elozo=i;
        }
    }
    dp[x][y]=(dp[x][y]*leftopt)%MOD;
    dp[x][y]=(dp[x][y]*rightopt)%MOD;
    return dp[x][y];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    elso.assign(n+1, -1);
    utolso.assign(n+1, -1);
    for(int i=0; i<m; i++)
    {
        int aktszin;
        cin>>aktszin;
        if(szin.size()==0 || aktszin!=szin.back()) szin.push_back(aktszin);
    }
    if(szin.size()>2*n+2)
    {
        cout<<0<<endl;
        return 0;
    }
    n=szin.size();

    for(int i=0; i<n; i++)
    {
        if(elso[szin[i]]==-1) elso[szin[i]]=i;
        utolso[szin[i]]=i;
    }
    for(int i=0; i<n; i++)
    {
        mini[i][i]=szin[i];
        for(int j=i+1; j<n; j++)
        {
            mini[i][j]=min(mini[i][j-1], szin[j]);
        }
    }
    cout<<calc(0, n-1)<<endl;





    return 0;
}