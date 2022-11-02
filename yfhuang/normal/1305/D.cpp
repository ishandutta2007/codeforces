#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

int n;
const int maxn = 1005;

vector<int> G[maxn];
bool vis[maxn];
bool dfs(int now, int fa, int u, int v, int root, bool f){
    if(now == u or now == v)
        f = false;
    if(now == root)
        f = true;
    //cout << now << " " << f << endl;
    bool flag = f;
    for(auto to : G[now]){
        if(to == fa){
            continue;
        }
        flag &= dfs(to, now, u, v, root, f);
    }
    if(now == root)
        flag = true;
    if(!flag){
        vis[now] = false;
    }
    return flag;
}

void dfs1(int now, int fa, bool f){
    f &= vis[now];
    for(auto to : G[now]){
        if(to == fa){
            continue;
        }
        dfs1(to, now, f);
    }
    if(!f)
        vis[now] = false;
}

int u[maxn], v[maxn];

int ask(int u, int v){
    cout << "? " << u << " " << v << endl;
    fflush(stdout);
    int w;
    cin >> w;
    return w;
}

int main(){
    cin >> n;
    for(int i = 1;i < n;i++){
        scanf("%d%d", &u[i], &v[i]);
    }
    for(int i = 1;i <= n;i++){
        vis[i] = true;
    }
    int sz = n;
    while(sz > 1){
        for(int i = 1;i <= n;i++)
            G[i].clear();
        for(int i = 1;i < n;i++){
            if(vis[u[i]] and vis[v[i]]){
                G[u[i]].push_back(v[i]);
                G[v[i]].push_back(u[i]);
            }
        }
        int core;
        if(sz > 2){
            for(int i = 1;i <= n;i++){
                if(G[i].size() > 1){
                    core = i;
                    break;
                }
            }
        }else{
            for(int i = 1;i <= n;i++){
                if(G[i].size() > 0){
                    core = i;
                    break;
                }
            }
        }
        int root;
        if(sz > 2){
            root  = ask(G[core][0], G[core][1]);
            dfs(root, root, G[core][0], G[core][1], root, true);
            dfs1(root, root, true);
        }else{
            root = ask(core, G[core][0]);
            dfs(root, root, core, G[core][0], root, true);
            dfs1(root, root, true);
        }
        sz = 0;
        for(int i = 1;i <= n;i++){
            if(vis[i] == true){
                sz++;
            }
        }
        //cout << sz << endl;
    }
    for(int i = 1;i <= n;i++){
        if(vis[i]){
            cout << "! " << i << endl;
            fflush(stdout);
            break;
        }
    }
    return 0;
}