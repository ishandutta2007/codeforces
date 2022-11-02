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
#include <random>
#include <chrono>
using namespace std;

const int maxn = 1e6 + 5;

int n, k;
int p[maxn], c[maxn];
int a[maxn];
vector<int> G[maxn];

int dp[maxn], dp1[maxn];
int in[maxn];
bool chosen[maxn];

bool cmp(int i, int j){
    return c[i] < c[j];
}

int stamp;

void dfs(int u){
    stamp += chosen[u];
    in[u] = stamp;
    for(auto v : G[u]){
        dfs(v);
    }
}

void dfs1(int u, int fa){
    if(fa != -1){
        dp[u] = min(dp[u], dp[fa] + 1);
    }
    if(chosen[u]){
        dp[u] = min(dp[u], dp1[fa] + in[u]);
    }
    dp1[u] = min(dp1[fa], dp[u] - in[u] + chosen[u]);
    for(auto v : G[u]){
        dfs1(v, u);
    }
}

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        char str[5];
        scanf("%d%s", &p[i], str);
        c[i] = str[0] - 'a';
        G[p[i]].push_back(i);
    }
    for(int i = 0;i <= n;i++){
        sort(G[i].begin(), G[i].end(), cmp);
    }
    cin >> k;
    for(int i = 1;i <= k;i++){
        scanf("%d", &a[i]);
        chosen[a[i]] = true;
    }
    dfs(0);
    stamp = 0;
    memset(dp, 0x3f, sizeof(dp));
    memset(dp1, 0x3f, sizeof(dp1));
    dp[0] = 0;
    dfs1(0, -1);
    for(int i = 1;i <= k;i++){
        printf("%d%c", dp[a[i]], i == k ? '\n' : ' ');
    }
    return 0;
}