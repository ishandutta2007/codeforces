#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
using namespace std;


const int maxn = 2e5 + 5;
int n;
int a[maxn];
vector<int> G[maxn];
vector<int> d[maxn];
map<int, int> dp[maxn];
int ret = 0;
void dfs(int u,int fa){
    for(auto x:d[a[u]]){
        int div = x;
        dp[u][div] = 1;
        ret = max(ret, 1);
    }
    for(auto v:G[u]){
        if(v == fa)
            continue;
        else{
            dfs(v, u);
            for(auto x:d[a[v]]){
                int div = x;
                auto it = dp[u].find(div);
                if(it != dp[u].end()){
                    ret = max(ret, it->second + dp[v][div]);
                    it->second = max(it->second, dp[v][div] + 1);
                }
            }
        }
    }
}

int main(){
    cin >> n;
    bool flag = false;
    for(int i = 2;i < maxn;i++){
        if(d[i].size() == 0){
            for(int j = i;j < maxn;j += i){
                d[j].push_back(i);
            }
        }
    }
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
        if(a[i] > 1)
            flag = true;
    }
    for(int i = 1;i < n;i++){
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if(flag){
        dfs(1, 1);
        printf("%d\n", ret);
    }else{
        printf("%d\n", 0);
    }
    return 0;
}