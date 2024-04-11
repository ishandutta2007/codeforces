#include <bits/stdc++.h>

using namespace std;

using ll=long long;
using vi=vector<int>;
using pii=pair<int,int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=(x*10)+(ch^48),ch=getchar();
    return !f?x:-x;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=500010;
const ll INF=0x3f3f3f3f3f3f3f3f;

struct Edge{int to,nxt;}e[N<<1];
int head[N],tot;

void addedge(int x,int y){
    e[++tot]={y,head[x]};
    head[x]=tot;
}

int n;

int siz[N];
void dfs(int x,int fa){
    siz[x]=1;
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(y==fa) continue;
        dfs(y,x);
        siz[x]+=siz[y];
    }
}

ll f[N];
int p[N];
void dfs1(int x,int fa){
    bool isleaf=1;
    f[x]=INF,p[x]=0;
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(y==fa) continue;
        dfs1(y,x);
        isleaf=0;
        ll tmp=f[y]+(ll)(siz[x]-siz[y])*(siz[x]-siz[y]);
        if(tmp<f[x]) f[x]=tmp,p[x]=p[y];
    }
    if(isleaf) f[x]=1,p[x]=x;
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi();
    for(int i=1;i<n;i++){
        int x=rdi(),y=rdi();
        addedge(x,y),addedge(y,x);
    }
    dfs(1,0);dfs1(1,0);
    int x=p[1];dfs(x,0);dfs1(x,0);
    printf("%lld\n",(ll)n*(n-1)/2+((ll)n*n-f[x])/2);
    return 0;
}