#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;

vector <int> g[MAXN], gp[MAXN];
int dp[MAXN][2];
pair <int, int> path[MAXN][2];

void dfs(int u, int parent){
    for(int v : g[u]){
        if(v == parent)continue;
        dfs(v, u);
    }

    int sum0 = 0;
    vector < pair <int, int> > opts;

    for(int v : g[u]){
        if(v == parent)continue;
        
        sum0 += dp[v][0];
        opts.push_back(make_pair(dp[v][1] - dp[v][0], v));
    }
    sort(opts.rbegin(), opts.rend());

    dp[u][0] = sum0;
    path[u][0] = make_pair(-1, -1);

    if(opts.size() >= 1 && 1 + opts[0].first > 0){
        dp[u][0] = sum0 + 1 + opts[0].first;
        path[u][0] = make_pair(opts[0].second, -1);
    }
    if(opts.size() >= 2 && 1 + opts[1].first > 0){
        dp[u][0] = sum0 + 1 + opts[0].first + 1 + opts[1].first;
        path[u][0] = make_pair(opts[0].second, opts[1].second);
    }

    dp[u][1] = sum0;
    path[u][1] = make_pair(-1, -1);
    
    if(opts.size() >= 1 && 1 + opts[0].first > 0){
        dp[u][1] = sum0 + 1 + opts[0].first;
        path[u][1] = make_pair(opts[0].second, -1);
    }
}

vector < pair <int, int> > erased_edges;
void find_edges(int u, int parent, int d){
    for(int v : g[u]){
        if(v == parent)continue;

        if(v != path[u][d].first && v != path[u][d].second){
            erased_edges.push_back(make_pair(u, v));
            find_edges(v, u, 0);
        }else{
            gp[u].push_back(v);
            gp[v].push_back(u);
            find_edges(v, u, 1);
        }
    }
}

vector <int> endpoints;
vector <bool> vis;

void find_endpoints(int u){
    vis[u] = true;

    if(gp[u].size() <= 1)endpoints.push_back(u);

    for(int v : gp[u])
        if(!vis[v])find_endpoints(v);
}

int main(){
    int t;
    scanf("%d", &t);
    
    while(t--){
        int n;
        scanf("%d", &n);

        for(int i = 0; i < n; i++){
            g[i].clear();
            gp[i].clear();
        }

        for(int i = 0; i < n - 1; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            a--, b--;

            g[a].push_back(b);
            g[b].push_back(a);
        }

        dfs(0, -1);

        erased_edges.clear();
        find_edges(0, -1, 0);

        /*
        cout << dp[0][0] << endl;
        for(pair <int, int> e : erased_edges)
            cout << e.first + 1 << ',' << e.second + 1 << endl;
        */

        vis = vector <bool> (n, false);
        vector < pair <int, int> > added_edges;

        int last = -1;
        for(int i = 0; i < n; i++)if(!vis[i]){
            endpoints.clear();
            find_endpoints(i);

            if(last == -1){
                last = endpoints.back();
            }else{
                added_edges.push_back(make_pair(last, endpoints[0]));
                last = endpoints.back();
            }
        }

        printf("%d\n", (int)erased_edges.size());
        for(int i = 0; i < (int)erased_edges.size(); i++)
            printf("%d %d %d %d\n", erased_edges[i].first + 1, erased_edges[i].second + 1, added_edges[i].first + 1, added_edges[i].second + 1);
    }
    return 0;
}