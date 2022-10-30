#include<bits/stdc++.h>
#define maxn 100050
using namespace std;

int n;
vector<int> G[maxn];

int ans;
int dp[maxn][2];

void dfs(int i,int fa=0)    {
    vector<int> son1,son2;
    for (int j:G[i])    {
        if (fa==j) continue;
        dfs(j,i);
        dp[i][0]=max(dp[i][0],max(dp[j][0],dp[j][1]));
        dp[i][1]=max(dp[i][1],dp[j][0]+1);
        son1.push_back(max(dp[j][0],dp[j][1]));
        son2.push_back(dp[j][0]);
    }
    dp[i][0]=max(dp[i][0]+(int)son1.size()-1,0);
    dp[i][1]=max(dp[i][1],1);

    sort(son1.rbegin(),son1.rend());
    sort(son2.rbegin(),son2.rend());

    int mx,cnt;
    
    mx=0,cnt=G[i].size();
    for (int j=0;j<=1&&j<son1.size();++j)
        mx+=son1[j],--cnt;
    ans=max(ans,mx+cnt);

    mx=0,cnt=G[i].size();
    for (int j=0;j<=1&&j<son2.size();++j)
        mx+=son2[j],--cnt;
    ans=max(ans,mx+max(cnt,1));
}

int main()  {
    scanf("%d",&n);
    for (int k=1;k<n;++k)   {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(1);

    printf("%d\n",ans);
    return 0;
}