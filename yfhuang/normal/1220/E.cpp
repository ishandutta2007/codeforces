    #include <cstdio>
    #include <algorithm>
    #include <iostream>
    #include <cstring>
    #include <vector>
     
    using namespace std;
     
    const int maxn = 4e5 + 5;
     
    int p[maxn], head[maxn], last[maxn], id[maxn], e;
    int dfn[maxn], low[maxn], fa[maxn], in[maxn];
    bool vis[maxn], isBridge[maxn];
    int n, m, idx;
     
    void add(int x, int y, int i){
        head[++e] = y;id[e] = i;
        last[e] = p[x];
        p[x] = e;
    }
     
    void tarjan(int x, int peid = -1){
        vis[x] = true;
        dfn[x]=low[x]=++idx;
        for(int j = p[x];j;j=last[j]){
            int y = head[j], eid=id[j];
            if(eid==peid) continue;
            if(!vis[y]){
                tarjan(y, eid);
                low[x] =  min(low[x], low[y]);
            }else
                low[x] = min(low[x], dfn[y]);
        }
        if(peid != -1 && low[x] == dfn[x])
            isBridge[peid] = true;
    }
     
    int start;
    int a[maxn], b[maxn];
    int w[maxn];
     
    int Find(int x){
        return x == fa[x] ? x : fa[x] = Find(fa[x]);
    }
     
    int sz[maxn];
    void Union(int u, int v){
        int fx = Find(u);
        int fy = Find(v);
        if(fx != fy){
            sz[fy] += sz[fx];
            fa[fx] = fy;
        }
    }
     
    long long dp[maxn];
    long long dp1[maxn];
    vector<int> G[maxn];
    long long sccw[maxn];
    bool yes[maxn];
    void dfs(int u, int f){
        yes[u] = (sz[u] > 1);
        long long sum = sccw[u], best = 0; 
        for(int i = 0;i < G[u].size();i++){
            int v = G[u][i];
            if(v == f)
                continue;
            dfs(v, u);
            sum += dp1[v];
            best = max(best, dp[v] - dp1[v]);
            yes[u] |= yes[v];
        }
        dp1[u] = yes[u] ? sum : 0;
        dp[u] = sum + best;
    }
    int main(){
        cin >> n >> m;
        e = 0;
        idx = 0;
        for(int i = 1;i <= n;i++){
            scanf("%d", &w[i]);
        }
        for(int i = 1;i <= m;i++){
            scanf("%d%d", &a[i], &b[i]);
            add(a[i], b[i], i);
            add(b[i], a[i], i);
        }
        for(int i = 1;i <= n;i++)
            if(!dfn[i])
                tarjan(i);
        for(int i = 1;i <= n;i++){
            fa[i] = i;
            sz[i] = 1;
        }
        for(int i = 1;i <= m;i++){
            if(!isBridge[i])
                Union(a[i], b[i]);
        }
        for(int i = 1;i <= m;i++){
            if(isBridge[i]){
                int fx = Find(a[i]);
                int fy = Find(b[i]);
                G[fx].push_back(fy);
                G[fy].push_back(fx);
            }
        }
        for(int i = 1;i <= n;i++){
            int fx = Find(i);
            sccw[fx] += w[i];
        } 
        cin >> start;
        start = Find(start);
        dfs(start, start);
        cout << dp[start] << endl;
        return 0;
    }