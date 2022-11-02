#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

typedef long long LL;

const LL mod = 998244353LL;
const int maxn = 200000 + 5;
vector<int> G[maxn];

LL dp[maxn][3];
int n;
void dfs(int u){
    if(G[u].size() == 0){
        dp[u][2] = 1;
        return;
    }
    dp[u][0] = 1;
    for(auto v : G[u]){
        dfs(v);
        LL tmp[3];
        tmp[0] = dp[u][0] * (dp[v][0] + dp[v][2]);
        tmp[1] = dp[u][1] * (dp[v][0] + dp[v][2]) + dp[u][0] * (dp[v][1] + dp[v][2]);
        tmp[2] = (dp[u][1] + dp[u][2]) * (dp[v][1] + dp[v][2]) + dp[u][2] * (dp[v][0] + dp[v][2]);
        for(int j = 0;j < 3;j++){
            dp[u][j] = tmp[j] % mod;
        }
    }
} 

int main(){
    cin >> n;
    for(int i = 2;i <= n;i++){
        int p;
        scanf("%d", &p);
        G[p].push_back(i);
    } 
    dfs(1);
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < 3;j++){
            //cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    cout << (dp[1][0] + dp[1][2]) % mod << endl;
    return 0;
}