#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int n, m;

const int maxn = 2e6 + 6;
vector<int> G[maxn][10];

typedef long long LL;
const LL mod = 1e9 + 7;
int tot;

bool vis[maxn];
LL dis[maxn];

void add(int from, int to, int weight){
    int nxt = to;
    while(weight >= 10){
        int node = ++tot;
        int value = weight % 10;
        weight /= 10;
        G[node][value].push_back(nxt); 
        nxt = node;
    }
    G[from][weight].push_back(nxt);
}

void bfs(){
    vector<vector<int> > Q1, Q2;
    vis[1] = true;
    Q1.push_back(vector<int>(1, 1));
    while(!Q1.empty()){
        for(auto q : Q1){
            for(int digit = 0;digit < 10;digit++){
                vector<int> t(0);
                for(auto x : q){
                    for(auto dst: G[x][digit]){
                        if(!vis[dst]){
                            vis[dst] = true;
                            dis[dst] = (dis[x] * 10 + digit) % mod;
                            t.push_back(dst);
                        }
                    }
                }
                if(!t.empty()) Q2.push_back(t);
            }
        }
        Q1 = Q2; Q2.clear();
    }
}

int main(){
    cin >> n >> m;
    tot = n;
    for(int i = 1;i <= m;i++){
        int u, v, w;
        scanf("%d%d", &u, &v);
        add(u, v, i);
        add(v, u, i);
    }
    bfs();
    for(int i = 2;i <= n;i++){
        printf("%lld\n", dis[i]);
    }
    return 0;
}