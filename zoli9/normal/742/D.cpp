#include <bits/stdc++.h>
using namespace std;
int n;
int m;
int w;
int sulyok[1009];
int dp[1009][1009]; //i.komptol, max j suly
int bea[1009];
bool bejar[1009];
vector<int> G[1009];
vector<vector<int> > komp;
vector<int> kompwosszeg;
vector<int> kompbosszeg;
vector<int> aktkomp;
void dfs(int x)
{
    bejar[x]=true;
    aktkomp.push_back(x);
    for(int sz: G[x])
    {
        if(!bejar[sz]) dfs(sz);
    }
}
int main()
{
    cin>>n>>m>>w;
    for(int i=1; i<=n; i++) cin>>sulyok[i];
    for(int i=1; i<=n; i++) cin>>bea[i];
    for(int i=1; i<=m; i++)
    {
        int x, y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i=1; i<=n; i++)
    {
        if(!bejar[i])
        {
            aktkomp.clear();
            dfs(i);
            komp.push_back(aktkomp);
        }
    }

    for(int i=0; i<komp.size(); i++)
    {
        kompwosszeg.push_back(0);
        kompbosszeg.push_back(0);
        for(int j=0; j<komp[i].size(); j++)
        {
            kompwosszeg[i]+=sulyok[komp[i][j]];
            kompbosszeg[i]+=bea[komp[i][j]];
        }
    }
    int kk=komp.size();
    for(int i=0; i<kk; i++)
    {
        dp[i][0]=0;
    }
    for(int ww=1; ww<=w; ww++)
    {
        if(kompwosszeg[0]<=ww)
        {
            dp[0][ww]=kompbosszeg[0];
            continue;
        }
        for(int j=0; j<komp[0].size(); j++)
        {
            if(sulyok[komp[0][j]]<=ww) dp[0][ww]=max(dp[0][ww], bea[komp[0][j]]);
        }
    }
    for(int i=1; i<kk; i++)
    {
        for(int ww=1; ww<=w; ww++)
        {
            dp[i][ww]=dp[i-1][ww];
            if(kompwosszeg[i]<=ww) dp[i][ww]=max(dp[i][ww], kompbosszeg[i]+dp[i-1][ww-kompwosszeg[i]]);
            for(int j=0; j<komp[i].size(); j++)
            {
                if(sulyok[komp[i][j]]<=ww) dp[i][ww]=max(dp[i][ww], bea[komp[i][j]]+dp[i-1][ww-sulyok[komp[i][j]]]);
            }
        }
    }
    cout<<dp[kk-1][w]<<endl;
    return 0;
}