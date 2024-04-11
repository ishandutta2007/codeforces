#include <bits/stdc++.h>
using namespace std;
int n;
int opr[300009];
vector<int> G[300009];
int children[300009];
int dp[300009];
void dfs(int x)
{
    if(G[x].size()==0)
    {
        children[x]=1;
        dp[x]=1;
        return;
    }
    int minwaste=-1;
    for(int sz: G[x])
    {
        dfs(sz);
        children[x]+=children[sz];
        if(opr[x]==0)
        {
            dp[x]+=(dp[sz]-1);
        }
        else
        {
            if(minwaste==-1 || children[sz]-dp[sz]<minwaste) minwaste=children[sz]-dp[sz];
        }
    }
    if(opr[x]==0) dp[x]++;
    else dp[x]=children[x]-minwaste;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>opr[i];
    }
    for(int i=2; i<=n; i++)
    {
        int num;
        cin>>num;
        G[num].push_back(i);
    }
    dfs(1);
    cout<<dp[1]<<endl;
    return 0;
}