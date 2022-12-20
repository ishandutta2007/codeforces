#include <bits/stdc++.h>
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

const int N=500010,CHR=23,RINF=0xcfcfcfcf;
struct Edge{int to,nxt,w;}e[N<<1];
int n,head[N],tot;
void addedge(int x,int y,char ch){
    e[++tot]=(Edge){y,head[x],ch-'a'};
    head[x]=tot;
}

int stat[N],siz[N],son[N],dep[N],dfn[N],ti,id[N];
void dfs1(int x){
    siz[x]=1;dfn[x]=++ti;id[ti]=x;
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        stat[y]=stat[x]^(1<<e[i].w);
        dep[y]=dep[x]+1;
        dfs1(y);
        siz[x]+=siz[y];
        if(siz[son[x]]<siz[y]) son[x]=y;
    }
}

int f[1<<CHR],ans[N];
void dfs2(int x,int typ){
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(y==son[x]) continue;
        dfs2(y,0);
    }
    if(son[x]) dfs2(son[x],1);
    f[stat[x]]=max(f[stat[x]],dep[x]);
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(y==son[x]) continue;
        for(int j=dfn[y];j<=dfn[y]+siz[y]-1;j++){
            for(int k=-1;k<=22;k++){
                ans[x]=max(ans[x],f[((1<<(k+1)>>1))^stat[id[j]]]+dep[id[j]]-2*dep[x]);
            }
        }
        for(int j=dfn[y];j<=dfn[y]+siz[y]-1;j++){
            f[stat[id[j]]]=max(f[stat[id[j]]],dep[id[j]]);
        }
    }
    for(int i=-1;i<=22;i++){
        ans[x]=max(ans[x],f[(1<<(i+1)>>1)^stat[x]]-dep[x]);
    }
    if(!typ){
        for(int i=dfn[x];i<=dfn[x]+siz[x]-1;i++){
            f[stat[id[i]]]=RINF;
        }
    }
}

void dfs3(int x){
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        dfs3(y);
        ans[x]=max(ans[x],ans[y]);
    }
}

int main(){
    n=rdi();
    for(int i=2;i<=n;i++){
        int fa=rdi();char ch[2];
        scanf("%s",ch);
        addedge(fa,i,ch[0]);
    }
    memset(f,0xcf,sizeof(f));
    dfs1(1);dfs2(1,0);dfs3(1);
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
    puts("");
    return 0;
}