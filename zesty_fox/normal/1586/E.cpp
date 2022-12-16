#include <bits/stdc++.h>
#include <iterator>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
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
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=600010;

int n,m;
vi e[N],t[N];

int vis[N];
void build_tree(int x,int fa){
    vis[x]=1;
    for(auto y:e[x]){
        if(vis[y]) continue;
        t[x].pb(y);
        build_tree(y,x);
    }
}

int f[N][21],dep[N],lg2[N],q;
void init_lg(){for(int i=2;i<=n;i++) lg2[i]=lg2[i>>1]+1;}
void dfs(int x,int fa){
    dep[x]=dep[fa]+1;f[x][0]=fa;
    for(int i=1;i<=lg2[dep[x]];i++) f[x][i]=f[f[x][i-1]][i-1];
    for(auto y:t[x]) dfs(y,x);
}

int LCA(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=lg2[dep[x]-dep[y]];i>=0;i--)
        if(dep[f[x][i]]>=dep[y]) x=f[x][i];
    if(x==y) return y;
    for(int i=lg2[dep[x]];i>=0;i--)
        if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
    return f[y][0];
}

int tag[N];
void dfs1(int x,int fa){
    for(auto y:t[x]) dfs1(y,x),tag[x]^=tag[y];
}

vector<vi> paths;
vi find_pa(int x,int y){
    vi tmp;
    int lc=LCA(x,y);
    while(x!=lc) tmp.pb(x),x=f[x][0];
    tmp.pb(lc);int pos=tmp.size();
    while(y!=lc) tmp.pb(y),y=f[y][0];
    reverse(tmp.begin()+pos,tmp.end());
    return tmp;
}

int g[N],h[N];
void dp(int x){
    int cnt=0;
    for(auto y:t[x]){
        dp(y);g[x]+=g[y];
        if(tag[y]) cnt++,g[x]-=h[y];
    }
    g[x]+=(cnt+1)/2,h[x]=cnt&1;
}

int df[N],deg[N];
int find(int x){return x==df[x]?df[x]:df[x]=find(df[x]);}
void merge(int x,int y){
    x=find(x),y=find(y);
    df[x]=y;
}

int cnt[N];
int main(){
    n=rdi(),m=rdi();
    for(int i=1;i<=m;i++){
        int x=rdi(),y=rdi();
        e[x].pb(y),e[y].pb(x);
    }
    init_lg();build_tree(1,0);dfs(1,0);
    q=rdi();
    while(q--){
        int x=rdi(),y=rdi();
        tag[x]^=1,tag[y]^=1;
        paths.pb(find_pa(x,y));
    }
    dfs1(1,0);bool flg=1;
    for(int i=2;i<=n;i++){
        if(tag[i]) {flg=0;break;}
    }
    if(flg){
        puts("YES");
        for(auto tmp:paths){
            printf("%lu\n",tmp.size());
            for(auto x:tmp) printf("%d ",x);
            puts("");
        }
        return 0;
    }
    puts("NO");
    for(int i=1;i<=n;i++) df[i]=i;
    dp(1);
    printf("%d\n",g[1]);
    return 0;
}