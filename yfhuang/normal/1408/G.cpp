#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cassert>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

const int maxn = 1505;

int fa[maxn], sz[maxn], edge[maxn];

int Find(int x){
    return x == fa[x] ? fa[x] : fa[x] = Find(fa[x]);
}

int dp[maxn][maxn];
int tmp[maxn * 2];
const int mod = 998244353;

void merge(int x, int y){
    memset(tmp, 0, sizeof(tmp));
    for(int i = 1;i <= sz[x];i++){
        for(int j = 1;j <= sz[y];j++){
            tmp[i + j] = (tmp[i + j] + 1LL * dp[x][i] * dp[y][j]) % mod;
        }
    }
    memcpy(dp[x], tmp, maxn * sizeof(int));
    sz[x] += sz[y];
    edge[x] += edge[y];
    fa[y] = x; 
}

int n, m;
int u[maxn * maxn], v[maxn * maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++){
        fa[i] = i;
        dp[i][1] = 1;
        sz[i] = 1;
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            int a;
            cin >> a;
            if(i < j)
                u[a] = i, v[a] = j;
        }
    }
    for(int i = 1;i <= n * (n - 1) / 2;i++){
        int fx = Find(u[i]);
        int fy = Find(v[i]);
        if(fx != fy)
            merge(fx, fy);
        edge[fx]++;
        if(edge[fx] == sz[fx] * (sz[fx] - 1) / 2)
            dp[fx][1] = (dp[fx][1] + 1) % mod;
    } 
    int root = Find(1);
    for(int i = 1;i <= n;i++){
        cout << dp[root][i] << " ";
    }
    return 0;
}