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

const int INF=0x3f3f3f3f;
#define rdi read<int>
#define rdl read<ll>
#define mp make_pair
#define pb push_back
#define fi first
#define sec second

const int N=500010;
int n,m,tot,head[N];
struct Edge{int to,nxt;}e[N<<1];
void addedge(int x,int y){
    e[++tot]=(Edge){y,head[x]};
    head[x]=tot;
}

int vis[N],seq[N],pos,a[N],rt;
void dfs(int x,int fa){
    seq[++pos]=x,a[x]^=1,vis[x]=1;
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(vis[y]) continue;
        dfs(y,x),seq[++pos]=x,a[x]^=1;
    }
    if(a[x]){
        seq[++pos]=fa,a[fa]^=1;
        seq[++pos]=x,a[x]^=1;
    }
}

int main(){
    n=rdi(),m=rdi();
    for(int i=1;i<=m;i++){
        int x=rdi(),y=rdi();
        addedge(x,y);addedge(y,x);
    }
    for(int i=1;i<=n;i++){
        a[i]=rdi();
        if(a[i]) rt=i;
    }
    dfs(rt,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]&&a[i]){
            puts("-1");
            return 0;
        }
    }
    if(a[0]) pos-=3;
    printf("%d\n",pos);
    for(int i=1;i<=pos;i++) printf("%d ",seq[i]);
    puts("");
    return 0;
}