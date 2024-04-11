#include "bits/stdc++.h"
using namespace std;
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define ALL(x) x.begin(),x.end()
 
template <typename T>
void cetak(T t){cout << t << ')' << endl;}
template <typename T, typename... V>
void cetak(T t, V... v) {cout << t; if (sizeof...(v)) cout << ", "; cetak(v...);}
 
#define debug(x...) cout << '(' << #x << ") = ("; cetak(x) 
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())

const int MOD = 1e9 + 7;
const int mx = 3e5 + 10;

vector<pair<int, int>> g[mx];

long long jaw = 0, sz[mx], n, ans;

void dfs(int now, int par, int tadi){
    sz[now] = 1;
    for(auto i : g[now]){
        if(i.f == par) continue;
        dfs(i.f, now, i.s);
        sz[now] += sz[i.f];
    }
    if(par > 0){
        int satu = sz[now];
        int dua = n * 2 - satu;
        jaw += 1LL * min(satu, dua) * tadi;
    }
}

void DFS(int now, int par, int ambil){
    if(ambil){
        for(auto i : g[now]){
            if(i.f == par) continue;
            if(sz[i.f] & 1){
                ans += i.s;
                DFS(i.f, now, 1);
            }
            else{
                DFS(i.f, now, 0);
            }
        }
    }
    else{
        for(auto i : g[now]){
            if(i.f == par) continue;
            if(sz[i.f] & 1){
                ans += i.s;
                DFS(i.f, now, 1);
            }
            else{
                DFS(i.f, now, 0);
            }
        }
    }
}

void solve(){
    cin >> n;
    jaw = 0;
    ans = 0;
    for(int i = 1; i <= n + n; i++) g[i].clear();
    for(int i = 1; i < n * 2; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dfs(1, 0, 0);
    DFS(1, 0, 0);
    cout << ans << ' ' << jaw << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}