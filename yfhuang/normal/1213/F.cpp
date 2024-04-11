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

int n, k;

const int maxn = 2e5 + 5;

int p[maxn], q[maxn];

vector<int> G[maxn];
vector<int> rG[maxn];

stack<int> S;
bool vis[maxn];
int sccno[maxn];
void dfs1(int u){
    vis[u] = true;
    for(auto v : rG[u]){
        if(!vis[v]){
            dfs1(v);
        }
    }
    S.push(u);
}

void dfs2(int u, int id){
    sccno[u] = id;
    for(auto v : G[u]){
        if(sccno[v] == 0){
            dfs2(v, id);
        }
    } 
}

int scc(){
    for(int i = 1;i <= n;i++){
        for(auto v : G[i]){
            rG[v].push_back(i);
        }
    }
    memset(vis, 0, sizeof(vis)); 
    for(int i = 1;i <= n;i++){
        if(!vis[i]){
            dfs1(i);
        }
    }
    memset(sccno, 0, sizeof(sccno));
    int cnt = 0; 
    while(!S.empty()){
        int now = S.top(); S.pop();
        if(sccno[now] == 0){
            dfs2(now, ++cnt);
        }
    }
    return cnt;
}

char s[maxn];

int main(){
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        scanf("%d", &p[i]);
    }
    for(int i = 1;i <= n;i++){
        scanf("%d", &q[i]);
    }
    for(int i = 1;i < n;i++){
        G[p[i]].push_back(p[i + 1]);
        G[q[i]].push_back(q[i + 1]);
    }
    int cnt = scc();
    if(cnt >= k){
        puts("YES");
        for(int i = 1;i <= n;i++){
            sccno[i]--;
            int id = min(k - 1, sccno[i]);
            s[i] = 'z' - id;
        }
        printf("%s\n", s + 1);
    }else{
        puts("NO");
    }
    return 0;
}