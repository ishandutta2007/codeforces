// LUOGU_RID: 97280490
#include <bits/stdc++.h>

using namespace std;

using i64=long long;
using u64=unsigned long long;
using db=double;
using pii=pair<int,int>;
using vi=vector<int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch-'0'),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back

const int N=510,M=N*4,INF=0x3f3f3f3f,INF1=INF/2;

struct Edge{int to,nxt,f,w;}e[M];
int head[N],tot=1;

void add_e(int x,int y,int f,int w){
    e[++tot]={y,head[x],f,w},head[x]=tot;
    e[++tot]={x,head[y],0,-w},head[y]=tot;
}

int n,m,S,T,cap[N*4];

void init(){
    n=rdi(),m=rdi();
    static int sum[N];
    for(int i=1;i<=m;i++){
        int x=rdi(),y=rdi(),f=rdi(),w=rdi();
        cap[i]=f;
        if(f&1) sum[x]--,sum[y]++,f--;
        add_e(x,y,f,w);
    }
    S=n+1,T=n+2;
    for(int i=1;i<=n;i++){
        if(sum[i]<0) add_e(i,T,-sum[i],0);
        else add_e(S,i,sum[i],0);
    }
    add_e(n,1,INF,INF1);
}

int fl[N],pre[N],dis[N];
bool bfs(int n,int S,int T,int k){
    fill(dis,dis+n+1,INF);
    static int inq[N];
    inq[S]=1,dis[S]=0,fl[S]=INF;
    queue<int> q({S});
    while(!q.empty()){
        int x=q.front();q.pop();inq[x]=0;
        for(int i=head[x];i;i=e[i].nxt){
            int y=e[i].to;
            if(e[i].f>=k&&dis[y]>dis[x]+e[i].w){
                dis[y]=dis[x]+e[i].w;
                pre[y]=i,fl[y]=min(fl[x],e[i].f);
                if(!inq[y]) inq[y]=1,q.push(y);
            }
        }
    }
    return dis[T]<INF;
}

void upd(int S,int T,int k){
    int f=fl[T]/k*k;
    while(T!=S){
        int pr=pre[T];
        e[pr].f-=f,e[pr^1].f+=f;
        T=e[pr^1].to;
    }
}

bool flow(){
    while(bfs(n+2,S,T,1)) upd(S,T,1);
    head[1]=e[head[1]].nxt,head[n]=e[head[n]].nxt;
    for(int x=1;x<=n+2;x++)
        for(int i=head[x];i;i=e[i].nxt){
            if(i&1) continue;
            if(e[i].f&1||(x==S&&e[i].f)) return false;
        }
    while(bfs(n+2,1,n,2)){
        if(dis[n]>=0) break;
        upd(1,n,2);
    }
    return true;
}

void solve(){
    init();
    if(!flow()) puts("Impossible");
    else{
        puts("Possible");
        for(int i=1;i<=m;i++)
            cout<<cap[i]-e[i*2].f<<' ';
        cout<<'\n';
    }
}

int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
#endif
    solve();
    return 0;
}