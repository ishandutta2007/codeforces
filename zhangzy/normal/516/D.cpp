#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

int n, T;
vector<pii>G[101000];
ll d[101000]; int id[101000];

int mx=1; ll mxd;
void dfs(int x,int fff,ll dis){
    d[x]=max(d[x],dis);
    if (dis>mxd) mxd=dis, mx=x;
    for (auto y:G[x])
        if (y.fi!=fff)
            dfs(y.fi,x,y.se+dis);
}
void gaod(){
    mxd=-1; dfs(mx,0,0);
    mxd=-1; dfs(mx,0,0);
    mxd=-1; dfs(mx,0,0);
}

int fa[101000], sz[101000], fl[101000];
int GF(int x){
    return fa[x]==x? x: fa[x]=GF(fa[x]);
}

int main(){
    cin>>n;

    for (int i=1;i<n;++i){
        int u, v, w; scanf("%d%d%d",&u,&v,&w);
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    gaod();

    for (int i=1;i<=n;++i) id[i]=i;
    sort(id+1,id+n+1,([](int a, int b){return d[a]>d[b];}));
    
    cin>>T;
    while (T--){
        ll lim; cin>>lim;
        int ans=1;
        memset(fl,0,sizeof fl);
        for (int i=1;i<=n;++i) fa[i]=i;
        for (int i=1,j=1;i<=n;++i){
            if (i>1) --sz[GF(id[i-1])];
            while (j<=n&&d[id[i]]-d[id[j]]<=lim){
                int x=id[j];
                fl[x]=sz[x]=1;
                for (auto o:G[x]){
                    int y=o.fi; if (!fl[y]) continue;
                    ans=max(ans,(sz[GF(x)]+=sz[GF(y)]));
                    fa[GF(y)]=GF(x);
                }
                ++j;
            }
        }
        cout<<ans<<endl;
    }
}