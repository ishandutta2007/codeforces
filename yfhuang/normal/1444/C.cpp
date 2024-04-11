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

int n, m, k;
const int maxn = 1e6 + 5;

int c[maxn], fa[maxn], rk[maxn], stu[maxn], stv[maxn], strk[maxn], tot, tot1;
bool ok[maxn];

map<pi, vector<pi>> edge;

int Find(int x){
    return x == fa[x] ? x : Find(fa[x]);
}

void link(int u, int v){
    u = Find(u);
    v = Find(v);
    if(fa[u] == fa[v])
        return;
    if(rk[u] < rk[v])
        swap(u, v);
    stu[++tot] = u;
    stv[tot] = v;
    fa[v] = u;
    strk[tot] = (rk[u] == rk[v]);
    rk[u] += strk[tot];
}

void goback(){
    while(tot > tot1){
        rk[stu[tot]] -= strk[tot];
        fa[stv[tot]] = stv[tot];
        tot--;
    }
}

bool merge(int u, int v){
    if(Find(u) == Find(v)) return 0;
    link(u, v + n);
    link(u + n, v);
    return 1;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++){
        cin >> c[i];
    }
    for(int i = 1;i <= 2 * n;i++){
        fa[i] = i;
    }
    for(int i = 1;i <= k;i++){
        ok[i] = 1;
    }
    for(int i = 1;i <= m;i++){
        int u, v;
        cin >> u >> v;
        if(c[u] > c[v])
            swap(u, v);
        if(c[u] == c[v]){
            ok[c[u]] &= merge(u, v); 
        }else{
            edge[mp(c[u], c[v])].push_back(mp(u, v));
        }
    }
    ll ans = 0;
    for(int i = 1;i <= k;i++){
        ans += ok[i];
    }
    ans = 1LL * ans * (ans - 1) / 2;
    tot1 = tot;
    for(auto pair : edge){
        int x, y;
        tie(x, y) = pair.fi;
        if(ok[x] and ok[y]){
            for(auto edges : pair.se){
                tie(x, y) = edges;
                if(!merge(x, y)){
                    ans--;
                    break;
                }
            } 
            goback();
        }
    }
    cout << ans << endl;
    return 0;
}