#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

const int maxn = 1e6 + 5;

int pre[maxn];

int l[maxn], r[maxn];
int n;
vector<int> G[maxn];
int id[maxn];
bool vis[maxn];
set<int> s;

void dfs(int u, int fa){
    vis[u] = true;
    for(auto v : G[u]){
        if(vis[v])
            continue;
        dfs(v, u);
    }
}

bool judge(){
    memset(vis, 0, sizeof(vis));
    dfs(1, 1);
    for(int i = 1;i <= n;i++){
        if(!vis[i])
            return false;
    }
    return true;
}
int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d%d", &l[i], &r[i]);
        id[l[i]] = -i;
        id[r[i]] = i;
    }
    int E = 0;
    s.clear();
    for(int i = 1;i <= 2 * n;i++){
        if(id[i] < 0){
            s.insert(i);
        }else{
            if(E >= n){
                s.clear();
                continue;
            }
            int now = id[i];
            for(auto it = s.rbegin(); it != s.rend() and *it > l[now];it++){
                int v = -id[*it];
                G[now].push_back(v);
                G[v].push_back(now);
                E++;
//                cout << now << " " << v << endl;
            }
            s.erase(l[now]);
        }
    }
    if(E == n - 1 and judge()){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}