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

int n, m, k;

const int maxn = 4e4 + 5;

int maxv[maxn << 2];
int addv[maxn << 2];
int v[maxn];
int dp[55][maxn];
#define lson o*2,l,mid
#define rson o*2+1,mid+1,r

void pushup(int o){
    maxv[o] = max(maxv[o*2],maxv[o*2+1]);
}

void pushdown(int o){
    if(addv[o]){
        addv[o*2] += addv[o];
        addv[o*2+1] += addv[o];
        maxv[o*2] += addv[o];
        maxv[o*2+1] += addv[o];
        addv[o] = 0;
    }
}

void build(int o, int l, int r){
    addv[o] = 0;
    if(l == r){
        maxv[o] = v[l];
        return;
    }
    int mid = (l + r) / 2;
    build(lson);
    build(rson);
    pushup(o);
}

void update(int o, int l, int r, int ql, int qr, int v){
    if(ql <= l && r <= qr){
        maxv[o] += v;
        addv[o] += v;
        return;
    }
    int mid = (l + r) / 2;
    pushdown(o);
    if(ql <= mid)
        update(lson, ql, qr, v);
    if(qr > mid)
        update(rson, ql, qr, v);
    pushup(o);
}

int querymax(int o, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr){
        return maxv[o];
    }
    int mid = (l + r) / 2;
    pushdown(o);
    if(qr <= mid)
        return querymax(lson, ql, qr);
    if(ql > mid)
        return querymax(rson, ql, qr);
    return max(querymax(lson, ql, qr), querymax(rson, ql, qr));
}

int g[55][maxn];
int pre[55][maxn];

void solve(){
    for(int i = 1;i <= m;i++){
        dp[1][i] = pre[1][i + k - 1] - pre[1][i - 1] + pre[2][i + k - 1] - pre[2][i - 1];        
    }
    for(int i = 2;i <= n;i++){
        for(int j = 1;j <= m;j++){
            v[j] = dp[i - 1][j];
        }
        build(1, 1, m);
        for(int j = 1;j <= k;j++){
            update(1, 1, m, 1, j, -g[i][j]);
        }
        dp[i][1] = querymax(1, 1, m, 1, m) + pre[i][k] - pre[i][0] + pre[i + 1][k] - pre[i + 1][0];
        for(int j = 2;j <= m;j++){
            int l = max(1, j - k);
            int r = j - 1; 
            update(1, 1, m, l, r, g[i][j - 1]); 
            update(1, 1, m, j, j + k - 1, -g[i][j + k - 1]);
            dp[i][j] = querymax(1, 1, m, 1, m) + pre[i][j + k - 1] - pre[i][j - 1] + pre[i + 1][j + k - 1] - pre[i + 1][j - 1];
        }
    }
}

int main(){
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            scanf("%d", &g[i][j]);
            pre[i][j] = pre[i][j - 1] + g[i][j];
        }
    }
    solve();
    int ans = 0;
    for(int i = 1;i <= m;i++){
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;
    return 0;
}