#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <vector>
using namespace std;
const int maxn = 1e5 + 5;
vector<int> G[maxn];
int n,m;
int k,x;
int dp[maxn][3][11];
int sum[maxn][11];
const int mod = 1e9 + 7;
void upd(int &a,int b){
    a += b;
    if(a >= mod) a -= mod;
    if(a < 0) a += mod;
}

void dfs(int u,int fa){
    dp[u][0][0] = k - 1;
    dp[u][2][0] = m - k;
    dp[u][1][1] = 1;
    for(auto v : G[u]){
        if(v == fa) continue;
        dfs(v,u);
        int a[3][11];
        memcpy(a,dp[u],sizeof(dp[u]));
        memset(dp[u],0,sizeof(dp[u]));
        for(int i = 0;i <= x;i++){
            for(int j = 0;j <= i;j++){
                upd(dp[u][0][i],a[0][j] * 1LL * sum[v][i - j] % mod);
                upd(dp[u][1][i],a[1][j] * 1LL * dp[v][0][i - j] % mod);
                upd(dp[u][2][i],a[2][j] * 1LL * (dp[v][0][i - j] + dp[v][2][i - j]) % mod);
            }
        }
    }
    for(int i = 0;i <= x;i++){
        upd(sum[u][i],dp[u][0][i]);
        upd(sum[u][i],dp[u][1][i]);
        upd(sum[u][i],dp[u][2][i]);
    }
}
int main(){
    cin >> n >> m;
    for(int i = 1;i < n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cin >> k >> x;
    dfs(1,1);
    int ans = 0;
    /*for(int i = 1;i <= n;i++){
        for(int j = 0;j <= 2;j++){
            for(int k = 0;k <= x;k++){
                printf("dp[%d][%d][%d] = %d\n",i,j,k,dp[i][j][k]);
            }
        }
    }*/
    for(int i = 0;i <= x;i++){
        upd(ans,sum[1][i]);
    }
    cout << ans << endl;
    return 0;
}