#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 2005;

int cost[2][maxn][maxn];
int dp[maxn];
int sz[2][maxn];
int l[2][maxn], r[2][maxn]; 

vector<int> G[2][maxn];

void upd(int &a, int b){
    if(b > a)
        a = b;
}

void dfs(int type, int u){
    if(u != 1){
        sz[type][u] = 1;
    }
    for(auto v : G[type][u]){
        dfs(type, v);
        l[type][u] = min(l[type][u], l[type][v]);
        r[type][u] = max(r[type][u], r[type][v]);
        sz[type][u] += sz[type][v];
    }
    upd(cost[type][l[type][u]][r[type][u]], sz[type][u]); 
}
int n, a, b;

int main(){
    cin >> n;
    for(int t = 0;t < 2;t++){
        cin >> a;
        for(int i = 1;i <= a;i++){
            l[t][i] = n + 1;
            r[t][i] = 0;
        }
        for(int i = 2;i <= a;i++){
            int p;
            scanf("%d", &p);
            G[t][p].push_back(i);
        }
        for(int i = 1;i <= n;i++){
            int x;
            scanf("%d", &x);
            l[t][x] = r[t][x] = i;
        }
        dfs(t, 1);
    }
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < i;j++){
            dp[i] = max(dp[i], dp[j] + max(cost[0][j + 1][i], cost[1][j + 1][i]));
        }
    } 
    cout << dp[n] << endl;
    return 0;
}