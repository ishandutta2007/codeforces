#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=100010;
const ll INFl=0x3f3f3f3f3f3f3f3f;

vector<pii> e[N*10];

priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
ll dis[N*10];

void dij(int st){
    memset(dis,0x3f,sizeof(dis));
    q.push({dis[st]=0,st});
    while(!q.empty()){
        auto tmp=q.top();q.pop();
        int x=tmp.se;
        if(dis[x]!=tmp.fi) continue;
        for(auto edge:e[x]){
            int y=edge.fi,w=edge.se;
            if(dis[y]>dis[x]+w){
                dis[y]=dis[x]+w;
                q.push({dis[y],y});
            }
        }
    }
}

struct SGT{
#define lson (now<<1)
#define rson (now<<1|1)
#define mid ((l+r)>>1)
    int ofs,typ;
    void adde(int x,int y,int w){
        !typ?e[x+ofs].pb({y+ofs,w}):e[y+ofs].pb({x+ofs,w});
    }
    void build(int now,int l,int r){
        if(l==r){
            adde(now,l-ofs,0);
            return;
        }
        build(lson,l,mid),build(rson,mid+1,r);
        adde(now,lson,0),adde(now,rson,0);
    }
    void connect(int now,int l,int r,int x,int y,int fr,int w){
        if(x<=l&&r<=y){
            adde(fr-ofs,now,w);
            return;
        }
        if(x<=mid) connect(lson,l,mid,x,y,fr,w);
        if(y>mid) connect(rson,mid+1,r,x,y,fr,w);
    }
#undef lson
#undef rson
#undef mid
}t1,t2;

int n,m,st;

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi(),m=rdi(),st=rdi();
    t1.ofs=n,t1.typ=0,t1.build(1,1,n);
    t2.ofs=5*n,t2.typ=1,t2.build(1,1,n);
    while(m--){
        int typ=rdi(),st,x,y,w;
        if(typ==1) st=rdi(),x=rdi(),w=rdi(),e[st].pb({x,w});
        if(typ==2) st=rdi(),x=rdi(),y=rdi(),w=rdi(),t1.connect(1,1,n,x,y,st,w);
        if(typ==3) st=rdi(),x=rdi(),y=rdi(),w=rdi(),t2.connect(1,1,n,x,y,st,w);
    }
    dij(st);
    for(int i=1;i<=n;i++)
        cout<<(dis[i]>=INFl?-1:dis[i])<<' ';
    cout<<'\n';
    return 0;
}