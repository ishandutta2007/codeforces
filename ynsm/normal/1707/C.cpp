#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 500500, LOG = 20;

int n, m, a[N], b[N];

vector< int > g[N], G[N];
bool was[N], ans[N];
int p[N];

int tin[N], tout[N], timer;
int up[N][LOG];

int P[N];

int pp(int v){return p[v] == v ? v : p[v] = pp(p[v]);}

void dfs(int v, int p){
    tin[v] = ++timer;
    up[v][0] = p;
    for(int i = 1; i < LOG; i++)
        up[v][i] = up[ up[v][i - 1] ][i - 1];
    for(auto e : g[v]){
        int to = a[e] ^ b[e] ^ v;
        if(to == p)
            continue;
        dfs(to, v);
    }
    tout[v] = timer;
}
bool upper(int v, int u){
    return tin[v] <= tin[u] && tin[u] <= tout[v];
}
int lca(int v,int u){
    if(upper(v, u))
        return v;
    if(upper(u, v))
        return u;
    for(int i = LOG - 1; i >= 0; i--)
        if(!upper(up[v][i], u))
            v = up[v][i];
    return up[v][0];
}

void solve() {
    cin >> n >> m;

    int need = 0;
    timer = 0;
    for(int i = 0; i < N; i++){
        p[i] = i;
        ans[i] = true;
    }

    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        G[a[i]].pb(i);
        G[b[i]].pb(i);
        if(pp(a[i]) == pp(b[i]))
            was[i] = 0;
        else
            was[i] = 1, p[pp(a[i])] = pp(b[i]);
    }
    for(int i = 0; i < m; i++){
        if(was[i]){
            g[a[i]].pb(i);
            g[b[i]].pb(i);
        }
    }
    dfs(0, 0);

    for(int i = 0; i < m; i++)
        if(!was[i]){
            int l = lca(a[i], b[i]);
            if(l == b[i])
                swap(a[i], b[i]);
            if(l == a[i]){
                P[tin[b[i]]]++;
                P[tout[b[i]] + 1]--;
                int u = b[i];
                for(int j = LOG - 1; j >= 0; j--)
                    if(!upper(up[u][j], a[i]))
                        u = up[u][j];
                P[0]++;
                P[tin[u]]--;
                P[tout[u] + 1]++;
            }else{
                P[tin[a[i]]]++;
                P[tout[a[i]] + 1]--;
                P[tin[b[i]]]++;
                P[tout[b[i]] + 1]--;
            }
            need++;
        }
    for(int i = 1; i < N; i++)
        P[i] += P[i - 1];
    for(int i = 0; i < n; i++)
        if(P[tin[i]] != need)
            ans[i] = 0;

    for(int i = 0; i < n; i++)
        cout << ans[i];
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    for(int i = 1; i <= t; i++) {
//        cout << "Case #" << i << endl;
        solve();
    }
}