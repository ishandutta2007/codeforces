#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int n, m;
const int maxn = 1e5 + 5;
vector<int> G[maxn];
bool vis[maxn];
int seq[maxn];
int tot;
int main(){
    while(cin >> n >> m){
        for(int i = 1;i <= n;i++){
            G[i].clear();
        }
        memset(vis, false,sizeof(vis));
        tot = 0;
        for(int i = 1;i <= m;i++){
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        set<int> reached;
        reached.insert(1);
        while(reached.size() > 0){
            int now = *reached.begin();
            vis[now] = 1;
            seq[++tot] = now;
            for(auto v:G[now]){
                if(vis[v]) continue;
                reached.insert(v);
            }
            reached.erase(now);
        }
        for(int i = 1;i <= n;i++){
            cout << seq[i] << " ";
        }
        cout << endl;
    }
    return 0;
}