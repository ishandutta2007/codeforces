#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

int n;
const int maxn = 2e5 + 5;
int u[maxn], v[maxn];

typedef pair<int, int> pii;
vector<pii> G[maxn];

typedef long long LL;
LL dp[maxn][3];
LL pre[maxn], suf[maxn];
LL mod = 998244353;

void dfs(int u, int fa, int id){
    //cout << u << " " << fa << " " << id << endl;
    int d = 0;
    int sz = 0;
    for(auto v : G[u]){
        if(v.first == fa)
            continue;
        sz++;
        if(v.second < id){
            d = sz;
        }
        dfs(v.first, u, v.second); 
    }
    vector<int> son(0);
    for(auto v : G[u]){
        if(v.first != fa){
            son.push_back(v.first);
        }
    }
    pre[0] = 1;
    suf[sz + 1] = 1;
    for(int i = 1;i <= sz;i++){
        int v = son[i - 1];
        pre[i] = pre[i - 1] * (dp[v][0] + dp[v][1]) % mod;
    }
    for(int i = sz;i >= 1;i--){
        int v = son[i - 1];
        suf[i] = (suf[i + 1]) * (dp[v][0] + dp[v][2]) % mod;
    }
    dp[u][0] = 0, dp[u][1] = 1, dp[u][2] = 0;
    for(int i = 1;i <= d;i++){
        int v = son[i - 1];
        dp[u][0] = (dp[u][0] + pre[i - 1] * dp[v][2] % mod * suf[i + 1]) % mod; 
    }
    dp[u][1] = pre[d] * suf[d + 1] % mod;
    dp[u][2] = pre[sz];
    for(int i = d + 1;i <= sz;i++){
        int v = son[i - 1];
        dp[u][2] = (dp[u][2] + pre[i - 1] * dp[v][2] % mod * suf[i + 1]) % mod;
    }
    //cout << u << " " << dp[u][0] << " " << dp[u][1] << " " << dp[u][2] << endl;
}

int main(){
    cin >> n;
    for(int i = 1;i < n;i++){
        scanf("%d%d", &u[i], &v[i]);
        G[u[i]].push_back(make_pair(v[i], i));
        G[v[i]].push_back(make_pair(u[i], i));
    }
    dfs(1, 1, n);
    cout << (dp[1][0] + dp[1][1]) % mod << endl;
    return 0;
}