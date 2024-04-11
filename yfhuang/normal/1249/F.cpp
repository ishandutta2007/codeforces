#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, k;

typedef long long LL;
const int maxn = 205;
LL a[maxn];
LL dp[maxn][maxn];
vector<int> G[maxn];

void upd(LL &a, LL b){
    if(b > a)
        a = b;
}
void dfs(int u, int fa){
    dp[u][0] = a[u];
    for(auto v : G[u]){
        if(v != fa)
            dfs(v, u);
    }
    for(int dep = 0; dep < n;dep++){
        if(dep == 0){
            for(auto v : G[u]){
                if(v == u)
                    continue;
                dp[u][dep] += dp[v][max(0, k - dep - 1)];
            }
        }else{
            for(auto to : G[u]){
                if(to == fa)
                    continue;
                int cur = dp[to][dep - 1];
                for(auto v : G[u]){
                    if(v == fa or v == to)
                        continue;
                    cur += dp[v][max(dep - 1, k - dep - 1)];
                }
                upd(dp[u][dep], cur);
            }
        }
    }
    for(int dep = n - 1;dep > 0;dep--){
        upd(dp[u][dep - 1], dp[u][dep]);
    }
}
int main(){
    cin >> n >> k;
    k++;
    for(int i = 1;i <= n;i++){
        scanf("%lld", &a[i]);
    } 
    for(int i = 1;i < n;i++){
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    } 
    dfs(1, 0);
    cout << dp[1][0] << endl;
    return 0;
}