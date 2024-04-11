#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;


const int maxn = 3e5 + 5;

vector<pair<int,int> > G[maxn];
vector<int> ans;
int d[maxn];
bool vis[maxn];
int dfs(int u){
    vis[u] = true;
    int s = (d[u] == 1);
    for(int i = 0;i < G[u].size();i++){
        int v = G[u][i].first;
        if(!vis[v]){
            if(dfs(v) == 1){
                s ^= 1;
                ans.push_back(G[u][i].second);
            }
        }
    }
    return s;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    int have = -1,cnt = 0;
    for(int i = 1;i <= n;i++){
        scanf("%d",&d[i]);
        if(d[i] == -1) have = i;
        if(d[i] == 1) cnt++;
    }
    for(int i = 1;i <= m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(make_pair(v,i));
        G[v].push_back(make_pair(u,i));
    }
    if(cnt % 2 && have == -1){
        cout << -1 << endl;
        return 0;
    }
    if(cnt % 2) d[have] = 1;
    dfs(1);
    cout << ans.size() << endl;
    for(int i = 0;i < ans.size();i++){
        printf("%d ",ans[i]);
    }
    return 0;
}