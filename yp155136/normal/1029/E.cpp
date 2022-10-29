#include <bits/stdc++.h>
using namespace std;

const int N = 200006;

vector<int> G[N];

int dp[3][N];
int depth[N];

vector<int> sonss[N];

void dfs(int now,int par,int cur_depth)
{
    depth[now] = cur_depth;
    vector<int> sons;
    for (int i:G[now])
    {
        if (i == par) continue;
        sons.push_back(i);
        dfs(i,now,cur_depth+1);
    }
    if (sons.size() == 0)
    {
        dp[0][now] = 1;
        dp[1][now] = 0;
        dp[2][now] = 1;
        if (cur_depth == 3)
        {
            dp[0][now] = dp[2][now] = 0;
        }
        return;
    }
    sonss[now] = sons;
    dp[0][now] = 1;
    int sum=0;
    for (int i:sons)
    {
        dp[0][now] += min({dp[0][i],dp[1][i],dp[2][i]} );
        sum += min({dp[0][i],dp[2][i]});
    }
    dp[1][now] = sum;
    /*for (int i:sons)
    {
        dp[1][now] = min(dp[1][now],sum - min({dp[0][i],dp[2][i]}) + dp[0][i]);
    }*/
    //cout << "now = " << now << " , dp0 = " << dp[0][now] << " , dp1 = " << dp[1][now] << " , depth = " << depth[now] << endl;
    sum = 0;
    for (int i:sons)
    {
        sum += min(dp[0][i],dp[2][i]);
    }
    dp[2][now] = dp[0][now];
    for (int i:sons)
    {
        dp[2][now] = min(dp[2][now],sum - min(dp[0][i],dp[2][i]) + dp[0][i]);
    }
    //cout << "dp2 = " << dp[2][now] << endl;

}

int main ()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<n;++i)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1,1,1);
    int ans=0;
    for (int i=1;i<n;++i)
    {
        if (depth[i] == 3)
        {
            int tmp = min(dp[0][i],dp[2][i]);
            int tmp2 = 0;
            for (int j:sonss[i])
            {
                tmp2 += dp[2][j];
            }
            ans += min(tmp,tmp2);
            //ans += min(dp[0][i],dp[2][i]);
        }
    }
    printf("%d\n",ans);
}