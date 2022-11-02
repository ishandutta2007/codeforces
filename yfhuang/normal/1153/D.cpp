#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 3e5 + 5;

int t[maxn], f[maxn];
int n;
vector<int> G[maxn];
int deg[maxn];

int dfs(int u){
    int ret = 0;
    if(deg[u] == 0)
        return 1;
    else{
        if(t[u] == 0){
            for(auto v : G[u]){
                ret += dfs(v);
            }
        }else{
            ret = 1e9;
            for(auto v : G[u]){
                ret = min(ret, dfs(v));
            }
        }
        return ret;
    }
}

int main(){
    while(cin >> n){
        memset(deg, 0, sizeof(deg));
        for(int i = 1;i <= n;i++){
            scanf("%d", &t[i]);
            G[i].clear();
        }
        for(int i = 2;i <= n;i++){
            scanf("%d", &f[i]);
            deg[f[i]]++;
            G[f[i]].push_back(i);
        }
        int k = 0;
        for(int i = 1;i <= n;i++){
            if(deg[i] == 0)
                k++;
        }
        cout << k + 1 - dfs(1) << endl;
    } 
    return 0;
}