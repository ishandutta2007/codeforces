#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
template<typename T>
inline T read(){
    T x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}


#define rdi read<int>
#define rdl read<ll>

const int N=10010;
int n,m,head[N],tot=1;
struct Edge{int to,nxt;}e[N<<2];
void addedge(int x,int y){
    e[++tot]=(Edge){y,head[x]};
    head[x]=tot;
}

int tr[N<<2],vis[N],rt[N],cnt;
void dfs(int x){
    vis[x]=1;
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(vis[y]) continue;
        tr[i]=tr[i^1]=1;
        dfs(y);
    }
}

int dep[N],f[N][16],lg2[N];
void pre_lg(){
    for(int i=2;i<=n;i++) lg2[i]=lg2[i>>1]+1;
}

int tofa[N];
void dfs1(int x,int fa){
    f[x][0]=fa;dep[x]=dep[fa]+1;
    for(int i=1;i<=15;i++) f[x][i]=f[f[x][i-1]][i-1];
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(!tr[i]||y==fa) continue;
        tofa[y]=i;
        dfs1(y,x);
    }
}

int lca(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=lg2[dep[x]-dep[y]];i>=0;i--){
        if(dep[f[x][i]]>=dep[y]) x=f[x][i];
    }
    if(x==y) return y;
    for(int i=lg2[dep[x]];i>=0;i--){
        if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
    }
    return f[x][0];
}

int dist(int x,int y){return dep[x]+dep[y]-2*dep[lca(x,y)];}

int a[N];
void dfs2(int x,int fa){
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(y==fa||!tr[i]) continue;
        dfs2(y,x);a[x]+=a[y];
    }
}

int ans[N],pos;
int main(){
    n=rdi(),m=rdi();pre_lg();
    for(int i=1;i<=m;i++){
        int x=rdi(),y=rdi();
        addedge(x,y);addedge(y,x);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]) {rt[++cnt]=i;dfs(i);dfs1(i,0);}
    }
    int tmp=0,k=0;
    for(int i=2;i<=tot;i+=2){
        if(tr[i]) continue;
        int x=e[i].to,y=e[i^1].to;
        if(!(dist(x,y)&1)) tmp++,a[lca(x,y)]-=2,a[x]++,a[y]++,k=i;
        else a[lca(x,y)]+=2,a[x]--,a[y]--;
    }
    if(!tmp){
        printf("%d\n",m);
        for(int i=1;i<=m;i++) printf("%d ",i);
        puts("");return 0;
    }
    for(int i=1;i<=cnt;i++) dfs2(rt[i],0);
    for(int i=1;i<=n;i++){
        if(a[i]==tmp&&tofa[i]) ans[++pos]=tofa[i]/2;
    }
    if(tmp==1) ans[++pos]=k/2;
    sort(ans+1,ans+pos+1);
    printf("%d\n",pos);
    for(int i=1;i<=pos;i++) printf("%d ",ans[i]);
    puts("");
    return 0;
}