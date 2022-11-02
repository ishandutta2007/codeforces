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

const int maxn = 1e5 + 5;
int cnt[maxn], len[maxn];
vector<int> G[maxn];
vector<int> E[maxn];
int id[maxn];
int tot;
void dfs(int u, int fa){
    id[u] = ++tot;
    for(auto v : G[u]){
        if(v == fa)
            continue;
        dfs(v, u);
        E[id[u]].push_back(id[v]);
    } 
}

int n;

int calc(int k){
    for(int i = n;i >= 1;i--){
        cnt[i] = 0;
        len[i] = 0;
        int v1 = 0, v2 = 0;
        for(auto v : E[i]){
            if(len[v] > v1){
                v2 = v1;
                v1 = len[v];
            }else{
                v2 = max(len[v], v2);
            }
            cnt[i] += cnt[v];
        }
        if(v1 + v2 + 1 >= k){
            len[i] = 0;
            cnt[i]++;
        }else{
            len[i] = v1 + 1;
        }
    }
    return cnt[1];
}


int main(){
    cin >> n;
    for(int i = 1;i < n;i++){
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    int m = sqrt(1.0 * n);
    for(int i = 1;i <= m;i++){
        int ans = calc(i);
        printf("%d\n", ans);
    }
    for(int i = m + 1;i <= n;){
        int val = calc(i);
        int l = i, r = n;
        while(l < r){
            int mid = (l + r + 1) >> 1;
            if(calc(mid) == val)
                l = mid;
            else
                r = mid - 1;
        }
        for(;i <= r;i++){
            printf("%d\n", val);
        }
    }
    return 0;
}