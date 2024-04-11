#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;

vector <int> g[MAXN];
vector < pair <int, int> > edges;
bool vis[MAXN];
int d[MAXN], depth[MAXN], rem[MAXN], len[MAXN];

void dfs(int u){
    vis[u] = true;

    vector < pair <int, int> > cur;

    for(int v : g[u]){
        if(vis[v]){
            if(depth[v] < depth[u] - 1){
                d[u]++;
                d[v]--;
            }
        }else{
            depth[v] = depth[u] + 1;
            dfs(v);
            d[u] += d[v];

            if(d[v] == 0){
                cur.push_back(make_pair(len[v], rem[v]));
            }
        }
    }

    sort(cur.rbegin(), cur.rend());
    if(u == 0 || d[u] > 0){
        for(int i = 0; i + 1 < (int)cur.size(); i += 2){
            edges.push_back(make_pair(cur[i].second, cur[i + 1].second));
        }
        if(cur.size() % 2 != 0 && cur.back().first > 1){
            edges.push_back(make_pair(cur.back().second, u));
        }
    }else{
        if(cur.size() % 2 == 0){
            if(cur.empty()){
                len[u] = 1;
                rem[u] = u;
            }else{
                if(cur.back().first == 1){
                    for(int i = 0; i + 2 < (int)cur.size(); i += 2){
                        edges.push_back(make_pair(cur[i].second, cur[i + 1].second));
                    }
                    len[u] = cur[(int)cur.size() - 2].first + 1;
                    rem[u] = cur[(int)cur.size() - 2].second;
                }else{
                    for(int i = 0; i + 1 < (int)cur.size(); i += 2){
                        edges.push_back(make_pair(cur[i].second, cur[i + 1].second));
                    }
                    len[u] = 1;
                    rem[u] = u;
                }
            }
        }else{
            for(int i = 0; i + 1 < (int)cur.size(); i += 2){
                edges.push_back(make_pair(cur[i].second, cur[i + 1].second));
            }
            len[u] = cur.back().first + 1;
            rem[u] = cur.back().second;
        }
    }

}

int main(){
    while(true){
        int n, m;
        scanf("%d %d", &n, &m);
        if(n == 0 && m == 0)break;

        for(int i = 0; i < n; i++){
            g[i].clear();
            d[i] = 0;
            rem[i] = -1;
            vis[i] = false;
        }

        while(m--){
            int s;
            scanf("%d", &s);

            int prv = -1;
            for(int i = 0; i < s; i++){
                int u;
                scanf("%d", &u);
                u--;

                if(prv != -1){
                    g[prv].push_back(u);
                    g[u].push_back(prv);
                }
                prv = u;
            }
        }

        edges.clear();
        depth[0] = 0;
        dfs(0);

        printf("%d\n", (int)edges.size());
        for(int i = 0; i < (int)edges.size(); i++)
            printf("%d %d\n", edges[i].first + 1, edges[i].second + 1);
    }
    return 0;
}