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

int n;
const int maxn = 2e5 + 5;
int a[maxn];

int ch[maxn * 30][2];
int dp[maxn * 30][2];
int cnt[maxn * 30];
int tot;

void insert(int v){
    int cur = 0;
    for(int i = 29;i >= 0;i--){
        int c = (v >> i) & 1;
        if(ch[cur][c] == -1){
            ch[cur][c] = ++tot;
        }
        cur = ch[cur][c]; 
    }
    dp[cur][0] = 0; 
    cnt[cur] = 1;
}

void dfs(int u){
    int l = ch[u][0], r = ch[u][1];
    if(l != -1)
        dfs(l);
    if(r != -1)
        dfs(r);
    if(l != -1){
        if(r != -1){
            dp[u][0] = min(dp[u][0], dp[l][0] + cnt[r]); 
            dp[u][0] = min(dp[u][0], dp[r][0] + cnt[l]);
            dp[u][1] = min(dp[u][1], dp[l][0] + dp[r][1]);
            dp[u][1] = min(dp[u][1], dp[l][0] + dp[r][0]);
            dp[u][1] = min(dp[u][1], dp[l][1] + dp[r][0]);
            cnt[u] = cnt[l] + cnt[r];
        }else{
            dp[u][0] = min(dp[u][0], dp[l][0]);
            dp[u][1] = min(dp[u][1], dp[l][1]);
            cnt[u] = cnt[l];
        }
    }else{
        if(r != -1){
            dp[u][0] = min(dp[u][0], dp[r][0]);
            dp[u][1] = min(dp[u][1], dp[r][1]);
            cnt[u] = cnt[r];
        }else{
            dp[u][0] = 0;
            cnt[u] = 1;
        }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    memset(ch, -1, sizeof(ch));
    memset(dp, 0x3f, sizeof(dp));
    tot = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        insert(a[i]);
    } 
    dfs(0);
    cout << min(dp[0][0], dp[0][1]) << endl;
    return 0;
}