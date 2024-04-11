#include <bits/stdc++.h>
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
typedef int (*func)(int, int);


const int MOD = 1e9 + 7;

int add(int x, int y){
    int ret = x + y;
    if(ret >= MOD) ret -= MOD;
    return ret;
}
int sub(int x, int y){
    int ret = x - y;
    if(ret < 0) ret += MOD;
    return ret;
}
int mul(int x, int y){
    return (long long)x * y % MOD;
}


const int mx = 1e5 + 10;


struct LCA{
    int n, idx;
    const int LOG = 20;
    vector<int> in, out, level;
    vector<vector<int>> P, G;
    
    LCA(){
        cin >> n;

        P.resize(n, vector<int>(LOG, 0));
        G.resize(n);
        in.resize(n);
        out.resize(n);
        level.resize(n, 0);

        for(int i = 1; i < n; i++){
            int u, v;
            cin >> u >> v;
            u -= 1; v -= 1;
            G[v].pb(u);
            G[u].pb(v);
        }
        idx = -1;
        dfs(0, 0);
    }

    LCA(vector<vector<int>> g){
        n = sz(g);
        G = g;

        P.resize(n, vector<int>(LOG, 0));
        in.resize(n);
        out.resize(n);
        level.resize(n, 0);
        
        idx = -1;
        dfs(0, 0);
    }

    void dfs(int now, int par){
        P[now][0] = par;
        for(int i = 1; i < LOG; i++)
            P[now][i] = P[P[now][i - 1]][i - 1];
        in[now] = ++idx;
        for(int i : G[now]){
            if(i == par) continue;
            level[i] = level[now] + 1;
            dfs(i, now);
        }
        out[now] = idx;
    }

    int is_ancestor(int p, int q){ // is p an ancestor of q?
        return in[p] <= in[q] && out[q] <= out[p];
    }

    int query(int p, int q){
        if(is_ancestor(p, q)) return p;
        if(is_ancestor(q, p)) return q;
        for(int i = LOG - 1; i >= 0; i--)
            if(!is_ancestor(P[p][i], q))
                p = P[p][i];
        return P[p][0];
    }

    int dist(int p, int q){
        return level[p] + level[q] - 2 * level[query(p, q)];
    }


};

vector<pair<int, int>> compress_tree(LCA &lca, vector<int> important){
    sort(ALL(important), [&](int i, int j){ return lca.in[i] < lca.in[j]; });
    important.erase(unique(ALL(important)), important.end());
    int siz = important.size();
    for(int i = 1; i < siz; i++){
        important.pb(lca.query(important[i], important[i - 1]));
    }
    sort(ALL(important), [&](int i, int j){ return lca.in[i] < lca.in[j]; });
    important.erase(unique(ALL(important)), important.end());
    vector<pair<int, int>> ret;

    for(int i = 0; i < sz(important); i++){
        if(i == 0) ret.pb({important[i], important[i]});
        else ret.pb({lca.query(important[i], important[i - 1]), important[i]});
    }
    return ret;
}

void solve(){
    int n, q;

    cin >> n;
    vector<vector<int>> g(n);

    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        u -= 1; v -= 1;
        g[v].pb(u);
        g[u].pb(v);
    }

    LCA lca(g);
    vector<int> di(n), virus(n);

    cin >> q;
    

    while(q--){
        int k, m;

        cin >> k >> m;
        vector<int> v(k), s(k), u(m);

        for(int i = 0; i < k; i++){
            cin >> v[i] >> s[i];
            v[i] -= 1;
        }
        for(int &i : u) cin >> i, i -= 1;

        vector<int> gabung;
        for(int i : v) gabung.pb(i);
        for(int i : u) gabung.pb(i);

        auto ve = compress_tree(lca, gabung);
        int N = sz(ve);
        vector<vector<int>> G(N);
        for(int i = 0; i < N; i++){
            di[ve[i].s] = i;
            virus[i] = -1;
        }
        for(int i = 1; i < N; i++){
            int x = di[ve[i].s];
            int p = di[ve[i].f];
            G[x].pb(p);
            G[p].pb(x);
        }

        priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq;

        for(int i = 0; i < k; i++){
            pq.push({{0, i}, di[v[i]]});
        }

        while(!pq.empty()){
            int i = pq.top().s;
            int id = pq.top().f.s;

            pq.pop();

            if(virus[i] == -1){
                virus[i] = id;
                for(int j : G[i]){
                    int dist = lca.dist(v[id], ve[j].s);
                    int kapan = (dist - 1) / s[id] + 1;
                    pq.push({{kapan, id}, j});
                }
            }
        }

        for(int i : u) cout << virus[di[i]] + 1 << ' ';
        cout << '\n';

    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}