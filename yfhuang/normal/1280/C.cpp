#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int T;
int n;

const int maxn = 2e5 + 5;
int a[maxn], b[maxn], t[maxn], dep[maxn], sz[maxn];
vector<int> G[maxn];
void dfs(int u, int fa, int d){
    dep[u] = d;
    sz[u] = 1;
    for(auto v : G[u]){
        if(v == fa)
            continue;
        dfs(v, u, d + 1);
        sz[u] += sz[v]; 
    }
}

long long sqr(long long x){
    return x * x;
}

int main(){
    cin >> T;
    while(T--){
        cin >> n;
        n *= 2;
        for(int i = 1;i <= n;i++){
            G[i].clear();
        }
        for(int i = 1;i < n;i++){
            scanf("%d%d%d", &a[i], &b[i], &t[i]);
            G[a[i]].push_back(b[i]);
            G[b[i]].push_back(a[i]);
        }
        dfs(1, 1, 1);
        long long G = 0, B = 0;
        for(int i = 1;i < n;i++){
            if(dep[a[i]] > dep[b[i]])
                swap(a[i], b[i]);
            B += 1LL * min(sz[b[i]], n - sz[b[i]]) * t[i];
            G += 1LL * (sz[b[i]] & 1) * t[i];
        }
        printf("%lld %lld\n", G, B);
    }

    return 0;
}