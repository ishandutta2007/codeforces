#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
T read(){
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

#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mp make_pair
#define rdi read<int>
#define rdll read<ll>

const int N = 16010;
int n;
struct Stock{int a,b,id;}s[N];

ll ti;
struct cmp{
    bool operator () (const Stock &a,const Stock &b) const{
        return a.a * ti + a.b < b.a * ti + b.b;
    }
};

const ll INF=0x3f3f3f3f3f3f3f3f;
const int INF1=0x3f3f3f3f;

priority_queue<Stock,vector<Stock>,cmp> q;
vector<Stock> v1,v2;
int id[N];
bool check(ll T){
    ti=T;sort(v2.begin(),v2.end(),[&](const Stock &a,const Stock &b){return a.a * ti + a.b < b.a * ti + b.b;});
    while(!q.empty()) q.pop();
    for(int l = 0,r = 0;l < 2 * n;l = r){
        r = l;
        while(r < 2 * n && v1[r].b == v1[l].b){
            q.push(v1[r]);
            r++;
        }
        for(int i = l;i < r;i++) id[v1[i].id] = q.top().id;   
    }
    vi tmp;
    for(int i = 1;i <= n;i++){
        tmp.pb(upper_bound(v2.begin(),v2.end(),s[id[i]],[&](const Stock &a,const Stock &b){return a.a * ti + a.b < b.a * ti + b.b;}) - v2.begin());
    }   
    sort(tmp.begin(),tmp.end());
    for(int i = 1;i <= n;i++){
        if(tmp[i-1]<i) return false;
    }
    return true;
}

ll ans1,ans2;
void solve1(){
    v1=vector<Stock>(s+1,s+2*n+1),v2=vector<Stock>(s+n+1,s+2*n+1);
    sort(v1.begin(),v1.end(),[&](const Stock &a,const Stock &b){return a.b < b.b;});
    ll l=0,r=1000000000;
    while(l<r){
        ll mid=(l+r)>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    if(!check(l)){
        puts("-1");
        exit(0);
    }
    cout<<(ans1=l)<<' ';
}

namespace Dinic{
int head[N],cur[N],tot=1;
struct Edge{int to,nxt,w,f;}e[N<<5];
void addedge(int x,int y,int f,int w){
    e[++tot]=(Edge){y,head[x],w,f};head[x]=tot;
    e[++tot]=(Edge){x,head[y],-w,0};head[y]=tot;
}

ll dis[N],inq[N];
int S,T;
bool bfs(){
    queue<int> q;
    for(int i=1;i<=T;i++) dis[i]=INF,inq[i]=0;
    q.push(S);inq[S]=1;dis[S]=0;
    while(!q.empty()){
        int x=q.front();q.pop();inq[x]=0;
        for(int i=head[x];i;i=e[i].nxt){
            int y=e[i].to;
            if(e[i].f&&dis[y]>dis[x]+e[i].w){
                dis[y]=dis[x]+e[i].w;
                if(!inq[y]) inq[y]=1,q.push(y);
            }
        }
    }
    memcpy(cur,head,(T+1)*sizeof(int));
    return dis[T]!=INF;
}

int dfs(int x,ll fl){
    if(x==T) return fl;
    int rest=fl;inq[x]=1;
    for(int &i=cur[x];i&&rest;i=e[i].nxt){
        int y=e[i].to;
        if(e[i].f&&dis[y]==dis[x]+e[i].w&&!inq[y]){
            int tmp=dfs(y,min(rest,e[i].f));
            e[i].f-=tmp;e[i^1].f+=tmp;rest-=tmp;
        }
    }
    return fl-rest;
}

void MCMF(){
    while(bfs()) ans2+=dis[T]*dfs(S,INF);
}
}
using namespace Dinic;

void solve2(){
    S=4*n+1,T=4*n+2;
    for(int i=1;i<=2*n;i++){
        int x=v1[i-1].id,y;
        if(x<=n) addedge(S,x,1,0);
        if(i>1){
            y=v1[i-2].id;
            addedge(x,y,INF1,0);
            if(s[x].b==s[y].b) addedge(y,x,INF1,0);
        }
        addedge(x,x+2*n,1,0);addedge(x,x+2*n,INF1,1);
    }
    v2=vector<Stock>(s+1,s+2*n+1);
    sort(v2.begin(),v2.end(),[&](const Stock &a,const Stock &b){return a.a * ans1 + a.b < b.a * ans1 + b.b;});
    for(int i=1;i<=2*n;i++){
        int x=v2[i-1].id,y;
        if(x>n) addedge(x+2*n,T,1,0);
        if(i>1){
            y=v2[i-2].id;
            addedge(x+2*n,y+2*n,INF1,0);
            if(s[x].a*ans1+s[x].b==s[y].a*ans1+s[y].b) 
                addedge(y+2*n,x+2*n,INF1,0);
        }
    }
    MCMF();
    cout<<ans2+n<<endl;
}

int main(){
    n=rdi();
    for(int i = 1;i <= 2 * n;i++) s[i].a = rdi(),s[i].b = rdi(),s[i].id = i;
    solve1();solve2();
    return 0;
}