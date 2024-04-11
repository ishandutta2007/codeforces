#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 15;

ll ans;

int n, m, K, adj[N][N], a[N], b[N], cnt;

bool vis[N], f[1<<6][7];

map <ll, int> mp;

queue <ll> q;

vector <int> id;

void solve_() {
    if (n == 2) {
        if (adj[1][2]) {
            ll s = 0;

            for (int j = 0; j < n; j++)
                s |= (min(a[j + 1], b[j + 1]))<<4*j;
            
            mp[s] = 1, q.push(s);
        }

        return;
    }
    
    memset(f, 0, sizeof(f));

    for (int i = 1; i <= cnt; i++)
        f[1<<i - 1][i] = 1;
    
    for (int i = 0; i < (1<<cnt); i++)  
        for (int j = 1; j <= cnt; j++)
            if (f[i][j]) {
                for (int k = 1; k <= cnt; k++)
                    if (!(i&(1<<k - 1))) {
                        if ((i|(1<<k - 1)) != (1<<cnt) - 1 || adj[a[k]][b[k]]) {
                            if (adj[a[k]][a[j]] && adj[b[k]][b[j]])
                                f[i|(1<<k - 1)][k] = 1;
                            
                            if (adj[a[k]][b[j]] && adj[b[k]][a[j]])
                                f[i|(1<<k - 1)][k] = 1;
                        }
                    }
            }
    
    for (int i = 1; i <= cnt; i++)
        if (f[(1<<cnt) - 1][i]) {
            ll s = 0;

            for (int j = 1; j <= cnt; j++)
                s |= min(a[j], b[j])*((1ll<<4*(a[j] - 1)) + (1ll<<4*(b[j] - 1)));
            
            mp[s] = 1, q.push(s);
            return;
        }
}

void dfs_() {
    if (cnt == n/2) {
        solve_();
        return;
    }

    for (int i = 1; i <= n; i++)
        if (!vis[i]) {
            vis[i] = 1, cnt++, a[cnt] = i;

            for (int j = i + 1; j <= n; j++)
                if (!vis[j]) {
                    vis[j] = 1;
                    b[cnt] = j;
                    dfs_();
                    vis[j] = 0;
                }
            
            cnt--, vis[i] = 0;
            return;
        }
}

ll merge_(ll s, int x, int y) {
    if (x > y)
        swap(x, y);

    for (int i = 0; i < n; i++)
        if (((s>>i*4)&15) == y)
            s += (x - y)*(1ll<<4*i);
    
    return s;
}

void init_(ll s) {
    id.clear();

    for (int i = 0; i < n; i++) 
        if (((s>>4*i)&15) == i + 1) 
            id.push_back(i + 1);
}

int main() {
    scanf("%d%d%d", &n, &m, &K);

    for (int u, v, i = 1; i <= m; i++) {
        scanf("%d%d", &u, &v);
        adj[u][v] = adj[v][u] = 1;
    }

    dfs_();

    while (!q.empty()) {
        ll u = q.front(); q.pop();
        init_(u);

        if (id.size() <= K) {
            ll res = 1;
       
            for (int i = K - id.size() + 1; i <= K; i++)
                res *= i;
            
            ans += res;
        }
        
        for (int i = 1; i < (int) id.size(); i++)
            for (int j = 0; j < i; j++) {
                ll v = merge_(u, id[j], id[i]);

                if (!mp.count(v))
                    mp[v] = 1, q.push(v);
            }
    }

    printf("%lld\n", ans);
}