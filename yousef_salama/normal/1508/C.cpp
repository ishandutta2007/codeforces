#include <bits/stdc++.h>
using namespace std;

struct edge{
    int u, v, w;
    bool operator <(const edge& e){
        return w < e.w;
    }
};

const int MAXN = 200000;

int parent[MAXN];
int findr(int u){
    if(u == parent[u])return u;
    else return parent[u] = findr(parent[u]);
}

vector <int> g[MAXN];
set <int> unvisited;

void dfs(int i, int src){
    parent[i] = src;
    unvisited.erase(i);

    int l = 0, j = 0;

    while(true){
        auto d = unvisited.lower_bound(l);
        if(d == unvisited.end())break;

        l = *d;

        while(j < (int)g[i].size() && g[i][j] < l)j++;

        if(j < (int)g[i].size() && g[i][j] == l){
            l++;
        }else{
            dfs(l, src);
        }
    }
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    vector <edge> edges(m);
    set < pair <int, int> > s;
    long long total_xor = 0;
    
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
        edges[i].u--, edges[i].v--;
        if(edges[i].u > edges[i].v)swap(edges[i].u, edges[i].v);

        s.insert(make_pair(edges[i].u, edges[i].v));
        total_xor ^= edges[i].w;
    }
    sort(edges.begin(), edges.end());

    if(1LL * n * (n - 1) / 2 - m <= n - 1){
        vector < pair <int, int> > unassigned;
        for(int u = 0; u < n; u++)
        for(int v = u + 1; v < n; v++)
            if(!s.count(make_pair(u, v)))unassigned.push_back(make_pair(u, v));

        long long mn = 1LL << 60;

        long long cur = 0;
        iota(parent, parent + n, 0);

        for(auto[u, v] : unassigned){
            int ur = findr(u);
            int vr = findr(v);

            if(ur != vr){
                parent[vr] = ur;
            }
        }
        for(auto[u, v, w] : edges){
            int ur = findr(u);
            int vr = findr(v);

            if(ur != vr){
                parent[vr] = ur;
                cur += w;
            }
        }
        mn = min(mn, cur + total_xor);

        for(int z = 0; z < (int)unassigned.size(); z++){
            cur = 0;
            iota(parent, parent + n, 0);

            for(int i = 0; i < (int)unassigned.size(); i++)if(i != z){
                int ur = findr(unassigned[i].first);
                int vr = findr(unassigned[i].second);

                if(ur != vr){
                    parent[vr] = ur;
                }
            }
            for(auto[u, v, w] : edges){
                int ur = findr(u);
                int vr = findr(v);

                if(ur != vr){
                    parent[vr] = ur;
                    cur += w;
                }
            }

            mn = min(mn, cur);
        }
        printf("%lld\n", mn);
    }else{
        memset(parent, -1, sizeof parent);

        for(auto[u, v, w] : edges){
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(int i = 0; i < n; i++){
            unvisited.insert(i);
            sort(g[i].begin(), g[i].end());
        }
        for(int i = 0; i < n; i++)
            if(parent[i] == -1)dfs(i, i);

        long long cur = 0;
        for(auto[u, v, w] : edges){
            int ur = findr(u);
            int vr = findr(v);

            if(ur != vr){
                parent[vr] = ur;
                cur += w;
            }
        }
        printf("%lld\n", cur);
    }

    return 0;
}