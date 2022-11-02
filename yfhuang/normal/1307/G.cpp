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

const int N = 105, M = 200005;
int n, m;
int tot, head[N], to[M], nxt[M], cap[M], cost[M];

void addedge(int u, int v, int c, int co){
    to[tot] = v, nxt[tot] = head[u], cap[tot] = c, cost[tot] = co, head[u] = tot++;
} 
typedef long long LL;
int dis[N];
int fa[N];
bool inque[N];

const int INF = 1e9;

vector<pair<int, int> > paths;

bool go(int source, int target){
    for(int i = 0;i < n;i++){
        dis[i] = INF;
    }
    dis[source] = 0;
    inque[source] = true;
    queue<int> q;
    q.push(source);
    while(q.size()){
        int u = q.front();
        inque[u] = false;
        q.pop();
        for(int i = head[u];~i;i = nxt[i]){
            if(cap[i]){
                int v = to[i];
                int ndis = dis[u] + cost[i];
                if(dis[v] > ndis){
                    dis[v] = ndis;
                    fa[v] = i;
                    if(!inque[v]){
                        inque[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }
    if(dis[target] == INF){
        return false;
    }
    int f = 1e9;
    int u = target;
    while(u != source){
        int e = fa[u];
        f = min(f, cap[e]);
        u = to[e ^ 1];
    }
    paths.emplace_back(f, dis[target]);
    u = target;
    while(u != source){
        int e = fa[u];
        cap[e] -= f, cap[e ^ 1] += f;
        u = to[e ^ 1];
    }
    return true;
}

int main(){
    cin >> n >> m;
    int s = 0, t = n - 1;
    tot = 0;
    memset(head, -1, sizeof(head));
    for(int i = 1;i <= m;i++){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        u--, v--;
        addedge(u, v, 1, w);
        addedge(v, u, 0, -w);
    }
    while(go(s, t)){
        continue;
    }
    int q;
    cin >> q;
    for(int i = 1;i <= q;i++){
        int x;
        scanf("%d", &x);
        double ans = 1e18;
        int f = 0;
        LL sum = 0;
        for(int j = 0;j < paths.size();j++){
            auto p = paths[j];
            sum += 1LL * p.first * p.second;
            f += 1LL * p.first;
            ans = min(ans, 1.0 * (sum + x) / f);
            if(j == paths.size() - 1 or ans < paths[j + 1].second){ 
                printf("%.10lf\n", ans);
                break;
            }
        }
    }
    return 0;
}