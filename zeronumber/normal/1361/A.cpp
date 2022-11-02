#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int maxn=6e5+10;
vector <int> h[maxn],g[maxn];
int n,m,f[maxn],p,id[maxn];

int main(){
    cin >> n >> m;
    for (int i=1;i<=m;i++){
        int u,v; scanf("%d%d",&u,&v);
        h[u].pb(v); h[v].pb(u);
    }
    for (int i=1;i<=n;i++){
        int x; scanf("%d",&x);
        g[x].pb(i); id[i]=x;
    }
    for (int i=1;i<=n;i++){
        for (auto j:h[i]) f[id[j]]=1;
        p=1; while (f[p]) ++p;
        if (p!=id[i]){
            puts("-1");
            return 0;
        }
        for (auto j:h[i]) f[id[j]]=0;
    }
    for (int i=1;i<=n;i++) for (auto x:g[i]) printf("%d ",x);
    puts("");
    return 0;
}