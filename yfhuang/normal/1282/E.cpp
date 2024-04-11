#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
#define F first
#define S second
int t;

int n;

typedef pair<int, int> pii;
map<pii, int> mp1;
map<pii, vector<int> > mp2;
const int maxn = 1e5 + 5;
int a[maxn][3];
vector<int> G[maxn];

bool vis[maxn];

void dfs(int u){
    if(vis[u])
        return;
    vis[u] = true;
    for(auto v : G[u])
        dfs(v);
    cout << u + 1 << " ";
}

void dfs2(int u, int fa){
    for(auto v : G[u]){
        if(v == fa)
            continue;
        dfs2(v, u);
    }
    cout << u + 1 << " ";
}

void solve(){
    mp2.clear();
    mp1.clear();
    for(int i = 0;i < n;i++){
        G[i].clear();
    }
    for(int i = 0;i < n - 2;i++){
        for(int j = 0;j < 3;j++){
            a[i][j]--;
        }
        for(int j = 0;j < 3;j++){
            int nxt = (j + 1) % 3;
            mp1[{a[i][j], a[i][nxt]}]++;
            mp1[{a[i][nxt], a[i][j]}]++;
            if(a[i][j] < a[i][nxt])
                mp2[{a[i][j], a[i][nxt]}].push_back(i);
            else
                mp2[{a[i][nxt], a[i][j]}].push_back(i);
        }
    }
    for(int i = 0;i < n - 2;i++){
        for(int j = 0;j < 3;j++){
            int nxt = (j + 1) % 3;
            if(mp1[{a[i][j], a[i][nxt]}] == 1){
                G[a[i][j]].push_back(a[i][nxt]);
                G[a[i][nxt]].push_back(a[i][j]);
            }
        }
    }
    fill(vis, vis + n, false);
    dfs(0);
    cout << endl;
    for(int i = 0;i < n;i++){
        G[i].clear();
    }
    for(auto it : mp2){
        if(it.F.F < it.F.S and it.S.size() == 2){
            G[it.S[0]].push_back(it.S[1]);
            G[it.S[1]].push_back(it.S[0]);
        } 
    }
    dfs2(0, 0);
    cout << endl;
}
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0;i < n - 2;i++){
            for(int j = 0;j < 3;j++){
                scanf("%d", &a[i][j]);
            }
        }
        solve();
    }
    return 0;
}