#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <vector>
using namespace std;

int n;

const int maxn = 2e5 + 5;
vector<int> G[maxn];
/*
int dp[maxn][5];

//dp[i][2] = dp[j][2] + 1, dp

void upd(int &a, int b){
    if(b > a)
        a = b;
}

map<pair<int,int> 
void dfs(int u, int fa){
    //cout << u << " " << fa << endl;
    dp[u][1] = 0;
    dp[u][2] = 0;
    dp[u][3] = 0;
    for(auto v : G[u]){
        if(v == fa)
            continue;
        dfs(v, u);
    }
    for(auto v : G[u]){
        if(v == fa)
            continue;
        upd(dp[u][3], dp[v][3]);
        upd(dp[u][3], dp[v][2] + dp[u][1] + 1);
        upd(dp[u][3], dp[u][2] + dp[v][1] + 1);
        upd(dp[u][2], dp[v][2] + 1);
        upd(dp[u][2], dp[u][1] + dp[v][1] + 1);
        //upd(dp[u][2], dp[v][2] + 2);
        upd(dp[u][1], dp[v][1] + 1);
    }
}
*/
int dep[2][maxn];
void dfs(int u, int fa, int d, int id){
    dep[id][u] = d;
    for(auto v : G[u]){
        if(v == fa)
            continue;
        dfs(v, u, d + 1, id);
    }
}
int main(){
    cin >> n;
    for(int i = 1;i < n;i++){
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 1, 0, 0);
    int u = 1;
    for(int i = 1;i <= n;i++){
        if(dep[0][i] >= dep[0][u]){
            u = i;
        }
    }
    dfs(u, u, 0, 1);
    int v = u;
    for(int i = 1;i <= n;i++){
        if(dep[1][i] >= dep[1][v]){
            v = i;
        }
    }
    dfs(v, v, 0, 0);
    //for(int i = 1;i <= n;i++){
        //cout << i << " " << dp[i][1] << " " << dp[i][2] << " " << dp[i][3] << endl;
    //}
    //cout << dp[1][3] << endl;
    int r = dep[1][v]; 
    vector<int> ans;
    ans.push_back(u);
    ans.push_back(v);
    int w;
    for(int i = 1;i <= n;i++){
        if(i != u and i != v){
            w = i;
            break;
        }
    }
    for(int i = 1;i <= n;i++){
        if(dep[1][w] + dep[0][w] < dep[1][i] + dep[0][i]){
            w = i;
        } 
    } 
    ans.push_back(w);
    long long dis = dep[1][w] + dep[0][w] + dep[1][v];
    cout << dis / 2 << endl;
    for(int i = 0;i < 3;i++){
        printf("%d%c", ans[i], i == 2 ? '\n' : ' ');
    }
    return 0;
}