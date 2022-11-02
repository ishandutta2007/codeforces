#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n;
const int maxn = 5e5 + 5;
vector<int> G[maxn];
int l[maxn], r[maxn];

void input(){
    cin >> n;
    for(int i = 1;i < n;i++){
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

int timestamp;

void dfs(int u, int fa){
    for(int i = 0;i < G[u].size();i++){
        int v = G[u][i];
        if(v == fa)
            continue;
        r[v] = --timestamp;
    }
    l[u] = --timestamp;
    for(int i = G[u].size() - 1;i >= 0;i--){
        int v = G[u][i];
        if(v == fa)
            continue;
        dfs(v, u);
    }
}

int main(){
    input();
    timestamp = 2 * n + 1;
    r[1] = --timestamp;
    dfs(1, 1);
    for(int i = 1;i <= n;i++){
        printf("%d %d\n", l[i], r[i]);
    }
    return 0;
}