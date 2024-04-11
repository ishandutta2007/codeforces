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

int t;
int n, m;
const int maxn = 1e6 + 5;

vector<int> G[maxn];
vector<int> rG[maxn];
bool vis[maxn];
int sccno[maxn];
stack<int> S;
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
    for(int i = 1;i <= n;i++){
        vis[i] = 0;
        sccno[i] = 0;
    }
    for(int i = 1;i <= n;i++){
        if(!vis[i]){
            dfs1(i);
        }
    }
    int cnt = 0;
    while(!S.empty()){
        int now = S.top(); S.pop();
        if(sccno[now] == 0){
            dfs2(now, ++cnt);
        }
    }
    return cnt;
}

int main(){
    cin >> t;
    while(t--){
        while(!S.empty())
            S.pop();
        cin >> n >> m;
        for(int i = 1;i <= n;i++){
            G[i].clear();
            rG[i].clear();
        }
        for(int i = 1;i <= m;i++){
            int u, v;
            scanf("%d%d", &u, &v);
            if(u != v)
                G[u].push_back(v);
        }
        int cnt = scc();
        if(cnt == 1){
            puts("No");
        }else{
            puts("Yes");
            vector<int> jury, contestant;
            for(int i = 1;i <= n;i++){
                if(sccno[i] == 1){
                    jury.push_back(i);
                }else{
                    contestant.push_back(i);
                }
            }
            cout << jury.size() << " " << contestant.size() << endl;
            for(int i = 0;i < jury.size();i++){
                printf("%d%c", jury[i], i == jury.size() - 1 ? '\n' : ' ');
            }
            for(int i = 0;i < contestant.size();i++){
                printf("%d%c", contestant[i], i == contestant.size() - 1 ? '\n' : ' ');
            }
        }
    }
    return 0;
}