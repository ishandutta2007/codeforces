#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

const int mod = 1e9 + 7;
const int i2 = (mod + 1) / 2;

const int maxn = 205;
ll prob[maxn][maxn];
int n;
int fa[maxn];
int dep[maxn];
int sz[maxn];
vector<int> G[maxn];
ll invn;

void add(ll &a, ll b){
    a += b;
    if(a >= mod)
        a -= mod;
}

ll qpow(ll a, ll p){
    ll ret = 1;
    while(p > 0){
        if(p & 1){
            ret = ret * a % mod;
        }
        a = a * a % mod;
        p >>= 1;
    }
    return ret;
}

void init(){
    memset(prob, 0, sizeof(prob)); 
    for(int i = 0;i < maxn;i++){
        prob[0][i] = 1;
    }
    for(int i = 1;i < maxn;i++){
        prob[i][0] = 0;
        for(int j = 1;j < maxn;j++){
            prob[i][j] = (prob[i-1][j] + prob[i][j-1]) * i2 % mod; 
        }
    }
}

void dfs(int u, int f, int d){
    fa[u] = f;
    dep[u] = d;
    sz[u] = 1;
    for(auto v : G[u]){
        if(v == f)
            continue;
        dfs(v, u, d + 1);
        sz[u] += sz[v];
    }
}

int lca(int u, int v){
    if(dep[u] > dep[v])
        swap(u, v);
    while(dep[u] < dep[v]){
        v = fa[v];
    }
    while(u != v){
        u = fa[u];
        v = fa[v];
    }
    return u;
}

int len(int u, int v){
    int w = lca(u, v);
    return dep[u] + dep[v] - 2 * dep[w] + 1;
}

ll query(int u, int v){
    ll sgn = 1;
    if(dep[u] > dep[v]){
        swap(u, v);
        sgn = -1;
    }
    vector<ll> U, V;
    int w = lca(u, v);
    int m = len(u, v);
    int lenv = dep[v] - dep[w];
    int lenu = dep[u] - dep[w];
    int prev = -1;
    while(v != w){
        V.push_back(sz[v] - (prev == -1 ? 0 : sz[prev]));
        prev = v;
        v = fa[v];
    }
    if(lenu == 0){
        V.push_back(n - (prev == -1 ? 0 : sz[prev]));
    }
    int preu = -1;
    while(u != w){
        U.push_back(sz[u] - (preu == -1 ? 0 : sz[preu])); 
        preu = u;
        u = fa[u];
    }
    if(lenu != 0){
        V.push_back(n - sz[prev] - sz[preu]);
    }
    reverse(U.begin(), U.end());
    for(auto val : U){
        V.push_back(val);
    }
    assert(V.size() == m);
    ll ans = 0;
    for(int i = 0;i < m;i++){
        if(sgn == 1)
            add(ans, V[i] * prob[i][m-1-i] % mod);  
        else
            add(ans, V[i] * prob[m-1-i][i] % mod);
    } 
    return ans;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    invn = qpow(n, mod - 2);
    init();
    for(int i = 1;i < n;i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 1, 1);
    ll ans = 0;
    for(int x = 1;x <= n;x++){
        for(int y = x + 1;y <= n;y++){
            add(ans, query(x, y));
        }
    }
    ans = ans * invn % mod;
    cout << ans << endl;
    return 0;
}