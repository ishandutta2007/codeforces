#include <bits/stdc++.h>

using namespace std;

using i64=long long;
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
#define rdi64 read<i64>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=100010,INF=0x3f3f3f3f;

int n,m,s[N],a[N];
pii p[N];

namespace MC{
int head[N],tot=1,S,T;
struct{int to,nxt,f;} e[N<<2];
void clear(){
    memset(head,0,sizeof(int)*(n+5));
    tot=1;
}

void addedge(int x,int y,int f){
    e[++tot]={y,head[x],f};head[x]=tot;
    e[++tot]={x,head[y],0};head[y]=tot;
}

int dep[N];
queue<int> q;
bool bfs(){
    while(!q.empty()) q.pop();
    memset(dep,0,sizeof(int)*(T+3));
    dep[S]=1;q.push(S);
    while(!q.empty()){
        int x=q.front();q.pop();
        if(x==T) return true;
        for(int i=head[x];i;i=e[i].nxt){
            int y=e[i].to;
            if(e[i].f&&!dep[y]){
                dep[y]=dep[x]+1;
                q.push(y);
            }
        }
    }
    return dep[T];
}

int dfs(int x,int flow){
    if(x==T) return flow;
    int rest=flow;
    for(int i=head[x];i&&rest;i=e[i].nxt){
        int y=e[i].to;
        if(e[i].f&&dep[y]==dep[x]+1){
            int tmp=dfs(y,min(rest,e[i].f));
            e[i].f-=tmp,e[i^1].f+=tmp,rest-=tmp;
        }
    }
    return flow-rest;
}

int solve(){
    int sum=0;
    while(bfs()) sum+=dfs(S,INF);
    return sum;
}
}

pii inp[N];
int deg[N],inv[N],id[N];

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi(),m=rdi();
    for(int i=1;i<=n;i++) s[i]=rdi();
    i64 sum=0;
    for(int i=1;i<=n;i++) 
        a[i]=rdi(),sum+=s[i]*a[i];
    int cnt=0,S=n+1,pos=0;
    MC::S=n+2,MC::T=n+3;
    for(int i=1;i<=m;i++){
        int x=rdi(),y=rdi();
        p[i]={y,x};
        if(!s[x]&&!s[y]) continue;
        if(!s[x]){
            deg[S]--,deg[y]++,++cnt;
            MC::addedge(S,y,1),id[i]=MC::tot;
        }
        else if(!s[y]){
            deg[S]--,deg[x]++,++cnt,swap(p[i].fi,p[i].se);
            MC::addedge(S,x,1),id[i]=MC::tot;
        }
        else{
            deg[x]--,deg[y]++;
            MC::addedge(x,y,1),id[i]=MC::tot;
        }
    }
    s[n+1]=1;
    for(int i=1;i<=n;i++)
        if(s[i]) deg[i]+=a[i],deg[S]-=a[i];
    i64 fl=0;
    for(int i=1;i<=n+1;i++){
        if(!s[i]) continue;
        if(deg[i]&1) {puts("NO");return 0;}
        if(deg[i]>0) MC::addedge(i,MC::T,deg[i]/2);
        else if(deg[i]<0) MC::addedge(MC::S,i,-deg[i]/2),fl+=-deg[i]/2;
    }
    fl-=MC::solve();
    if(fl) {puts("NO");return 0;}
    puts("YES");
    for(int i=1;i<=m;i++){
        if(MC::e[id[i]].f) swap(p[i].fi,p[i].se);
        cout<<p[i].fi<<' '<<p[i].se<<'\n';
    }
    return 0;
}