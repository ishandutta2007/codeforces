#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef pair<int,int>pi;
typedef long long ll;
const int M=998244353;
const int maxn=2e6+12;
vector<pi> h[maxn];
int n,r1,r2,dis[maxn],m,U[maxn],V[maxn],f[maxn],l[maxn],r[maxn],tot;
struct seg{
    int L[maxn],R[maxn],dep[maxn],color[maxn],ans[maxn][2],lazy[maxn],inv[maxn];
    void pushup(int x){
        ans[x][0]=max(ans[x*2][0],ans[x*2+1][0]);
        ans[x][1]=max(ans[x*2][1],ans[x*2+1][1]);
    }
    void pushdown(int x){
        if (lazy[x]){
            lazy[x*2]^=1;
            lazy[x*2+1]^=1;
            swap(ans[x*2][0],ans[x*2][1]);
            swap(ans[x*2+1][0],ans[x*2+1][1]);
        }
        lazy[x]=0;
    }
    void build(int x,int l,int r){
        if (l==r) {
            ans[x][color[inv[l]]]=dep[inv[l]];
            return;
        }
        int mid=(l+r)>>1;
        build(x*2,l,mid);
        build(x*2+1,mid+1,r);
        pushup(x);
    }
    void init(){
        for (int i=1;i<=n;i++) L[i]=l[i],R[i]=r[i],dep[i]=dis[i],color[i]=f[i];
        for (int i=1;i<=n;i++) inv[L[i]]=i;
        build(1,1,n);
    }
    void modify(int x,int l,int r,int ll,int rr){
        if (l==ll&&r==rr){
            swap(ans[x][0],ans[x][1]);
            lazy[x]^=1;
            return;
        }
        if (lazy[x]) pushdown(x);
        int mid=(l+r)>>1;
        if (rr<=mid) modify(x*2,l,mid,ll,rr);
        else if (ll>mid) modify(x*2+1,mid+1,r,ll,rr);
        else modify(x*2,l,mid,ll,mid),modify(x*2+1,mid+1,r,mid+1,rr);
        pushup(x);
    }
    void upd(int id){
        modify(1,1,n,L[id],R[id]);
    }
    int qry(){
        return ans[1][0];
    }
}seg1,seg2;
int gid(){
    int ret=1;
    for (int i=2;i<=n;i++) if (dis[i]>dis[ret]) ret=i;
    return ret;
}
void dfs(int u,int fa){
    l[u]=++tot;
    for (auto e:h[u]){
        int v=e.F;
        if (v==fa) continue;
        dis[v]=dis[u]+1;
        f[v]=f[u]^e.S;
        dfs(v,u);
    }
    r[u]=tot;
}
int main(){
    cin >> n;
    for (int i=1;i<n;i++){
        int u,v,w; scanf("%d%d%d",&u,&v,&w);
        h[u].pb((pi){v,w});
        h[v].pb((pi){u,w});
        U[i]=u; V[i]=v;
    }
    dis[1]=0; dfs(1,0);
    r1=gid();
    dis[r1]=0; f[r1]=0; tot=0; dfs(r1,0);
    seg1.init();
    r2=gid();
    dis[r2]=0; f[r2]=0; tot=0; dfs(r2,0);
    seg2.init();
    scanf("%d",&m);
    while (m--){
        int id;scanf("%d",&id);
        int u=U[id],v=V[id];
        if (seg1.dep[u]>seg1.dep[v]) seg1.upd(u); else seg1.upd(v);
        if (seg2.dep[u]>seg2.dep[v]) seg2.upd(u); else seg2.upd(v);
        printf("%d\n",max(seg1.qry(),seg2.qry()));
    }
    return 0;
}