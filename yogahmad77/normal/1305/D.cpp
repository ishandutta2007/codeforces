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
    const int LOG = 12;
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

    LCA(vector<vector<int>> g, int root){
        n = sz(g);
        G = g;

        P.resize(n, vector<int>(LOG, root));
        in.resize(n);
        out.resize(n);
        level.resize(n, 0);
        
        idx = -1;
        dfs(root, root);
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

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        u -= 1; v -= 1;
        g[v].pb(u);
        g[u].pb(v);
    }
    vector<pair<pair<int, int>, int>> ve;
    vector<int> ini;
    vector<int> sudah(n, 0);
    for(int i = 0; i < n; i++) if(sz(g[i]) == 1) ini.pb(i);
    while(sz(ini) > 1){
        map<int, int> itu;
        for(int i = 1; i < sz(ini); i += 2){
            int j = i - 1;
            sudah[ini[i]] = sudah[ini[j]] = 1;
            cout << "? " << ini[i] + 1 << ' ' << ini[j] + 1 << endl;
            int ret;
            cin >> ret;
            ret -= 1;
            if(ret == ini[i]){
                cout << "! " << ret + 1 << endl;
                return;
            }
            if(ret == ini[j]){
                cout << "! " << ret + 1 << endl;
                return;
            }
            itu[ret] = ini[i];
            ve.pb({{ini[i], ini[j]}, ret});
        }
        if(sz(ini) & 1) itu[ini.back()] = ini.back();
        ini.clear();
        for(auto x : itu) ini.pb(x.s);
    }
    for(int root = 0; root < n; root++){
        LCA lca(g, root);
        int ya = 1;
        for(auto x : ve){
            if(lca.query(x.f.f, x.f.s) != x.s){
                ya = 0;
                break;
            }
        }
        if(ya){
            cout << "! " << root + 1 << endl;
            return;
        }
    }
}

int main(){
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}