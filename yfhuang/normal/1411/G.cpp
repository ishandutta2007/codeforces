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

const int mod = 998244353;
const int maxn = 1e5 + 5;

int sg[maxn];
bool vis[512];
int ans[512];
int a[512][513];
vector<int> G[maxn];

void dfs(int u){
    for(auto v : G[u]){
        if(sg[v] == -1){
            dfs(v);
        }
    }
    memset(vis, 0, sizeof(vis));
    for(auto v : G[u]){
        vis[sg[v]] = true;
    }
    for(int i = 0;i < 512;i++){
        if(!vis[i]){
            sg[u] = i;
            break;
        }
    }
}

int qpow(int a, int n){
    int ret = 1;
    while(n > 0){
        if(n & 1){
            ret = 1LL * ret * a % mod;
        }
        a = 1LL * a * a % mod;
        n >>= 1;
    }
    return ret;
}

void gauss(int n){
    for(int i = 0;i < n;i++){
        int pivot = i;
        for(int j = i;j < n;j++){
            if(a[j][i] != 0){
                pivot = j;
                break;
            }
        }
        swap(a[i], a[pivot]);
        int inv = qpow(a[i][i], mod - 2);
        for(int j = i + 1;j < n;j++){
            int tmp = (mod - 1LL * inv * a[j][i] % mod) % mod; 
            for(int k = i;k <= n;k++){
                a[j][k] = (a[j][k] + 1LL * tmp * a[i][k]) % mod;
            }
        }
    }
    for(int i = n - 1;i >= 0;i--){
        for(int j = i + 1;j < n;j++){
            a[i][n] = (a[i][n] + 1LL * a[i][j] * ans[j]) % mod;
        }
        ans[i] = (mod - 1LL * a[i][n] * qpow(a[i][i], mod - 2) % mod) % mod;
    }
}

int cnt[512];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }
    memset(sg, -1, sizeof(sg));
    for(int i = 1;i <= n;i++){
        dfs(i);
    }
    for(int i = 1;i <= n;i++){
        cnt[sg[i]]++;
    }
    int inv = qpow(n + 1, mod - 2);
    for(int i = 0;i < 512;i++){
        for(int j = 0;j < 512;j++) a[i][i ^ j] = 1LL * cnt[j] * inv % mod;
        a[i][512] = (i != 0) * inv;
        a[i][i] = (a[i][i] + mod - 1) % mod;
    }
    gauss(512);
    cout << ans[0] << endl; 
    return 0;
}