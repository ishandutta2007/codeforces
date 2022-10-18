#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300005;

struct edge{
    int v, dir, index;
    edge(int v, int dir, int index): v(v), dir(dir), index(index){}
};

vector <edge> g[MAXN];
bool vis[MAXN];
int init_dir[MAXN], dir[MAXN];

int dfs(int u){
    vis[u] = true;

    int ret = 1;
    for(edge e : g[u]){
        if(vis[e.v])continue;

        dir[e.index] = e.dir;
        ret += dfs(e.v);
    }
    return ret;
}

int dfs2(int u){
    vis[u] = true;

    int ret = 1;
    for(edge e : g[u]){
        if(vis[e.v])continue;

        if(e.dir == 0){
            ret += dfs2(e.v);
        }else{
            dir[e.index] = -e.dir;
        }
    }
    return ret;
}

int main(){
    int n, m, s;
    scanf("%d %d %d", &n, &m, &s);
    s--;

    for(int i = 0; i < m; i++){
        int t, u, v;
        scanf("%d %d %d", &t, &u, &v);
        u--, v--;

        if(t == 1){
            g[u].push_back(edge(v, 0, i));
            init_dir[i] = 0;
        }else{
            g[u].push_back(edge(v, 1, i));
            g[v].push_back(edge(u, -1, i));
            init_dir[i] = 1;
        }
    }
    printf("%d\n", dfs(s));
    for(int i = 0; i < m; i++){
        if(dir[i] == 1)printf("+");
        else if(dir[i] == -1)printf("-");
        else if(init_dir[i] != 0)printf("+");
    }
    printf("\n");

    memset(vis, false, sizeof vis);
    memset(dir, 0, sizeof dir);

    printf("%d\n", dfs2(s));
    for(int i = 0; i < m; i++){
        if(dir[i] == 1)printf("+");
        else if(dir[i] == -1)printf("-");
        else if(init_dir[i] != 0)printf("+");
    }
    printf("\n");

    return 0;
}