#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
const int maxn=1e6+12;
const int M=1000000007;
vector <int> h[maxn];
vector <int> ans;
bool vis[maxn];
int n,m,d[maxn],_,c[maxn];
void solve(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) h[i].clear(),c[i]=0;
    ans.clear();
    for (int i=0;i<m;i++){
        int u,v; scanf("%d%d",&u,&v);
        h[u].pb(v);
    }
    for (int i=1;i<=n;i++) if (h[i].size()==2){
        sort(h[i].begin(),h[i].end());
        int u=h[i][0],v=h[i][1];
        if (u==v) h[i].resize(1);
    }
    for (int i=1;i<=n;i++){
        if (c[i]==2) ans.pb(i);
        else for (auto j:h[i]) c[j]=max(c[j],c[i]+1);
    }
    sort(ans.begin(),ans.end());
    printf("%d\n",(int)ans.size());
    for (auto x:ans) printf("%d ",x); puts("");
}
int main(){
    cin >> _;
    while (_--) solve();
    return 0;
}