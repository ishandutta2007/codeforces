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
void cetak(T t, V... v) {cout << t; if (sizeof...(v)) cerr << ", "; cetak(v...);}
 
#define debug(x...) cout<< '(' << #x << ") = ("; cetak(x) 
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())

const int MOD = 1e9 + 7;
const int mx = 1e5 + 10;


inline int add(int u, int v) {
    return (u += v) >= MOD ? u - MOD : u;
}
 
inline int sub(int u, int v) {
    return (u -= v) < 0 ? u + MOD : u;
}
 
inline int mul(int u, int v) {
    return (long long)u * v % MOD;
}

int POW(int a, int b){
    int ret = 1;
    while(b > 0){
        if(b & 1) ret = mul(ret, a);
        b >>= 1;
        a = mul(a, a);
    }
    return ret;
}

struct segmenTree{
    
    int n;
    vector<int> bit1, bit2;

    segmenTree(){
        n = 100000 + 3;
        bit1.resize(n, 0);
        bit2.resize(n, 0);
    }

    void upd(vector<int> &bit, int x, int val){
        for(; x < n; x += x & -x) bit[x] = add(bit[x], val);
    }

    void upd(int l, int r, int val){
        upd(bit1, l, val);
        upd(bit1, r + 1, sub(0, val));
        upd(bit2, l, mul(val, l - 1));
        upd(bit2, r + 1, sub(0, mul(val, r)));
    }

    int get(vector<int> &bit, int x){
        int ret = 0;
        for(; x; x -= x & -x) ret = add(ret, bit[x]);
        return ret;
    }

    int get(int x){
        int ret = mul(get(bit1, x), x);
        int ter = get(bit2, x);
        ret = sub(ret, ter);
        return ret;
    }

    int get(int l, int r){
        int ret = sub(get(r), get(l - 1));
        return ret;
    }

} st1, st2;

int n, sz[mx], l[mx], r[mx], level[mx];
set<int> g[mx];

int find_center(int now, int par, int dari){
    for(int i : g[now]){
        if(i == par) continue;
        if(sz[i] * 2 > sz[dari]) return find_center(i, now, dari);
    }
    return now;
}

void DFS(int now, int par){
    sz[now] = 1;
    for(int i : g[now]){
        if(i == par) continue;
        DFS(i, now);
        sz[now] += sz[i];
    }
}

void dfs(int now, int par, vector<int> &ve){
    ve.pb(now);
    for(int i : g[now]){
        if(i == par) continue;
        level[i] = level[now] + 1;
        dfs(i, now, ve);
    }
}

int jaw = 0, tot = 1;
int inv[mx];
void centroid(int now){
    DFS(now, 0);
    if(sz[now] <= 1) return;
    int center = find_center(now, now, now);
    for(int i : g[center]){
        g[i].erase(center);
    }
    vector<vector<int>> gabung;
    for(int i : g[center]){
        vector<int> ve;
        level[i] = 1;
        dfs(i, 0, ve);
        gabung.pb(ve);
    }
    st2.upd(l[center], r[center], POW(r[center] - l[center] + 1, MOD - 2));
    for(auto ve : gabung){
        for(int i : ve){
            auto sa = st1.get(l[i], r[i]);
            auto du = st2.get(l[i], r[i]);
            du = mul(du, level[i]);
            sa = add(sa, du);
            jaw = add(jaw, mul(sa, inv[i]));
        }
        for(int i : ve){
            st1.upd(l[i], r[i], mul(level[i], inv[i]));
            st2.upd(l[i], r[i], inv[i]);
        }
    }
    st2.upd(l[center], r[center], sub(MOD, POW(r[center] - l[center] + 1, MOD - 2)));
    for(auto ve : gabung){
        for(int i : ve){
            st1.upd(l[i], r[i], sub(MOD, mul(level[i], inv[i])));
            st2.upd(l[i], r[i], sub(MOD, inv[i]));
        }
    }
    for(int i : g[center]) centroid(i);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        // l[i] = rand() % n;
        // r[i] = rand() % n;
        // if(l[i] > r[i]) swap(l[i], r[i]);
        cin >> l[i] >> r[i];
    }
    for(int i = 2; i <= n; i++){
        int u, v;
        cin >> u >> v;
        // u = i;
        // v = rand() % (i - 1) + 1;
        g[u].insert(v);
        g[v].insert(u);
    }
    for(int i = 1; i <= n; i++){
        inv[i] = POW(r[i] - l[i] + 1, MOD - 2);
        tot = mul(tot, r[i] - l[i] + 1);
    }
    centroid(1);
    cout << mul(jaw, tot) << endl;
}