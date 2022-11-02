#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int maxn=1e6+34;
bool v1[maxn],v2[maxn];
int a[maxn],n,m,d[maxn],ans[maxn];
vector <int> f[maxn],g[maxn];
void dfs1(int u){
    v1[u]=1;
    for (auto v:f[u]){
        if (!v1[v]) dfs1(v);
    }
}
void dfs2(int u){
    v2[u]=1;
    for (auto v:g[u]){
        if (!v2[v]) dfs2(v);
    }
}
int main(){
    cin >> n >> m;
    while (m--){
        int u,v; cin >> u >> v;
        f[u].pb(v); g[v].pb(u);
        d[v]++;
    }
    queue <int> q; int tot=0;
    for (int i=1;i<=n;i++) if (!d[i]) q.push(i);
    while (!q.empty()){
        int u=q.front(); q.pop(); ++tot;
        for (auto v:f[u]){
            d[v]--;
            if (!d[v]) q.push(v);
        }
    }
    if (tot!=n){puts("-1");return 0;}
    for (int i=1;i<=n;i++){
        ans[i]=!v1[i]&!v2[i];
        if (!v1[i]) dfs1(i);
        if (!v2[i]) dfs2(i);
    }
    int cnt=0;
    for (int i=1;i<=n;i++) cnt+=ans[i];
    cout << cnt << endl;
    for (int i=1;i<=n;i++) if (ans[i]) printf("A"); else printf("E");
    return 0;
}