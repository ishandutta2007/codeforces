#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef double db;
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
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=100010,MOD=1e9+7,INF=0x3f3f3f3f;

int h,w,n;
struct Board{int l,r,u,s;}b[N];

struct SGT{
#define lson (now<<1)
#define rson (now<<1|1)
#define mid ((l+r)>>1)
    using max_heap=priority_queue<pii,vector<pii>,greater<pii>>;
    max_heap q[N];
    int mi[N*4];
    int getmin(const max_heap &a) {return a.empty()?INF:a.top().fi;}
    void pushup(int now) {mi[now]=min(mi[lson],mi[rson]);}

    i64 query(int now,int l,int r,Board b){
        if(mi[now]>min(b.u+b.s,h+1)) return 0;
        if(l==r){
            i64 sum=0;
            while(!q[l].empty()&&q[l].top().fi<=b.u+b.s)
                sum+=q[l].top().se,q[l].pop();
            mi[now]=getmin(q[l]);
            return sum%MOD;
        }
        i64 ret=0;
        if(b.l<=mid) ret+=query(lson,l,mid,b);
        if(b.r>mid) ret+=query(rson,mid+1,r,b);
        pushup(now);return ret%MOD;
    }
    void insert(int now,int l,int r,int x,pii v){
        if(l==r){
            q[l].push(v);
            mi[now]=getmin(q[l]);
            return;
        }
        x<=mid?insert(lson,l,mid,x,v):insert(rson,mid+1,r,x,v);
        pushup(now);
    }
#undef lson
#undef rson
#undef mid
}t;

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    h=rdi(),w=rdi(),n=rdi();
    for(int i=1;i<=n;i++){
        int u=rdi(),l=rdi(),r=rdi(),s=rdi();
        b[i]={l,r,u,s};
    }
    sort(b+1,b+n+1,[&](const Board &a,const Board &b){return a.u<b.u;});
    for(int i=1;i<=w;i++) t.insert(1,1,w,i,{h+1,1});
    for(int i=n;i>=1;i--){
        i64 sum=t.query(1,1,w,b[i]);
        if(b[i].l==1) t.insert(1,1,w,b[i].r+1,{b[i].u,2*sum%MOD});
        else if(b[i].r==w) t.insert(1,1,w,b[i].l-1,{b[i].u,2*sum%MOD});
        else t.insert(1,1,w,b[i].l-1,{b[i].u,sum}),
            t.insert(1,1,w,b[i].r+1,{b[i].u,sum});
    }
    i64 ans=0;
    for(int i=1;i<=w;i++)
        while(!t.q[i].empty()) ans+=t.q[i].top().se,t.q[i].pop();
    cout<<ans%MOD<<'\n';
    return 0;
}