#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int maxn = 2e5 + 5;

int n,m;

vector<int> G[maxn];
vector<int> ans[maxn];
int f[maxn];
bool vis[maxn];
int odd[maxn];
bool used[maxn];

void dfs(int u,int fa){
    vis[u] = true;

    for(auto i : G[u]){
        int v = f[i] ^ u;
        if(v == fa) continue;
        if(used[i]) continue;
        if(vis[v]){
            odd[v] ^= 1;
            ans[v].push_back(i);
            used[i] = 1;
        }else{
            dfs(v,u);
            if(odd[v]){
                odd[v] ^= 1;
                ans[v].push_back(i);
                used[i] = 1;
            }else odd[u] ^= 1,ans[u].push_back(i),used[i] = 1;
        }
    }
}


int main(){
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        f[i] = u ^ v;
        G[u].push_back(i);
        G[v].push_back(i);
    }
    for(int i = 1;i <= n;i++){
        if(!vis[i]) dfs(i,i);
    }

    int res = 0;
    for(int i = 1;i <= n;i++){
        res += ans[i].size() / 2;
    }
    cout << res << endl;
    for(int i = 1;i <= n;i++){
        for(int j = 0;j  + 1< ans[i].size();j += 2){
            int xx = ans[i][j];
            int yy = ans[i][j + 1];
            int u = f[xx] ^ i;
            int v = f[yy] ^ i;
            printf("%d %d %d\n",u,i,v);
        }
    }
    return 0;
}