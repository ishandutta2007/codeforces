#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int n, m;

const int maxn = 2e5 + 5;
pair<int, pi> e[maxn];

int fa[maxn], dep[maxn];
int fa1[maxn];
bool a[4005][4005];
ll ans;
int type[maxn];

void init(){
    for(int i = 1;i <= n;i++){
        fa[i] = i;
    }
}

int Find(int x){
    return x == fa[x] ? x : fa[x] = Find(fa[x]);
}

void Union(int u, int v, int w){
    int fx = Find(u);
    int fy = Find(v);
    if(fx == fy)
        return;
    fa[fx] = fy;
    ans += w;
}

int deg[maxn];
vector<int> G[maxn];
bool vis[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    int W = 0;
    for(int i = 1;i <= m;i++){
        cin >> e[i].se.fi >> e[i].se.se >> e[i].fi; 
        W ^= e[i].fi;
    }
    sort(e + 1, e + 1 + m);
    if(n >= 4000){
        for(int i = 1;i <= m;i++){
            int u = e[i].se.fi;
            int v = e[i].se.se;
            deg[u]++;
            deg[v]++;
            G[u].push_back(v);
            G[v].push_back(u);
        } 
        int u = 1;
        for(int i = 1;i <= n;i++){
            if(deg[i] < deg[u])
               u = i; 
        }
        init();
        ans = 0;
        for(int i = 1;i <= n;i++){
            if(i == u)
                continue;
            bool ok = false;
            for(auto v : G[u]){
                if(v == i)
                   ok = true; 
            }
            if(!ok)
                Union(i, u, 0);
        }
        for(auto v : G[u]){
            for(auto v1 : G[v]){
                vis[v1] = true;
            }
            for(int i = 1;i <= n;i++){
                if(i == v or vis[i])
                    continue;
                Union(i, v, 0);
            }
            for(auto v1 : G[v]){
                vis[v1] = false;
            }
        }
        for(int i = 1;i <= m;i++){
            int u = e[i].se.fi;
            int v = e[i].se.se;
            int w = e[i].fi;
            Union(u, v, w);
        }
        cout << ans << endl;
    }else{
        init();
        for(int i = 1;i <= m;i++){
            int u = e[i].se.fi;
            int v = e[i].se.se;
            int w = e[i].fi;
            a[u][v] = a[v][u] = 1;
        }
        bool flag = false;
        for(int i = 1;i <= n;i++){
            for(int j = i + 1;j <= n;j++){
                if(!a[i][j]){
                    int fx = Find(i);
                    int fy = Find(j);
                    if(fx == fy)
                        flag = true;
                    else{
                        fa[fx] = fy;
                    }
                }
            }
        }
        ans = 0;
        if(flag){
            for(int i = 1;i <= m;i++){
                int u = e[i].se.fi;
                int v = e[i].se.se;
                int w = e[i].fi;
                int fx = Find(u);
                int fy = Find(v);
                if(fx == fy)
                    continue;
                else{
                    ans += w;
                    fa[fx] = fy;
                }
            }
            cout << ans << endl;
        }else{
            for(int i = 1;i <= m;i++){
                int u = e[i].se.fi;
                int v = e[i].se.se;
                int w = e[i].fi;
                int fx = Find(u);
                int fy = Find(v);
                if(fx != fy){
                    type[i] = 1;
                    ans += w;
                    fa[fx] = fy;
                }
            }
            init();
            for(int i = 1;i <= m;i++){
                int u = e[i].se.fi;
                int v = e[i].se.se;
                int w = e[i].fi;
                int fx = Find(u);
                int fy = Find(v);
                if(fx == fy){
                    type[i] = 2;
                }else{
                    fa[fx] = fy;
                }
            }
            int x = (1 << 30);
            for(int i = 1;i <= m;i++){
                int u = e[i].se.fi;
                int v = e[i].se.se;
                int w = e[i].fi;
                if(type[i] == 0){
                    type[i] = 3;
                    x = min(x, w);
                }
            }
            ans += min(W, x);
            cout << ans << endl;
        }
    }
    return 0;
}