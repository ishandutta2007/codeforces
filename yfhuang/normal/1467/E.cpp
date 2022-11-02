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

const int maxn = 2e5 + 5;
int tin[maxn], tout[maxn], pre[maxn];
int tot;
int a[maxn];
vector<int> G[maxn];
map<int, int> cnt;

map<int, int> dfs(int u, int fa){
    map<int, int> res;
    tin[u] = ++tot;
    for(auto v : G[u]){
        if(v == fa)
            continue;
        auto res1 = dfs(v, u);
        if(res1.find(a[u]) != res1.end()){
            pre[1]++;
            pre[tin[v]]--;
            pre[tout[v] + 1]++;
        }
        if(res1.size() > res.size()) swap(res1, res);
        for(auto it : res1){
            res[it.fi] += it.se;
        }
    }
    tout[u] = tot;
    res[a[u]]++;
    if(res[a[u]] != cnt[a[u]]){
        pre[tin[u]]++;
        pre[tout[u] + 1]--;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    for(int i = 1;i < n;i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    int sum = 0;
    int ans = 0;
    for(int i = 1;i <= n;i++){
        sum += pre[i];
        if(!sum)
            ans++;
    }
    cout << ans << endl;
    return 0;
}