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

const int N=200010,MOD=1e9;

int n,m;

//f[0]=0,f[1]=1,f[i]=f[i-1]+f[i-2]
ll fib[N],sumf[N];

struct SGT{
#define lson (now<<1)
#define rson (now<<1|1)
#define mid ((l+r)>>1)
    struct Data{
        int len;
        ll sum1,sum2;
        //[l,r]
        //sum1=\sum{a_i*fib_{i-l+1}}
        //sum2=\sum{a_i*fib_{i-l+2}};
        friend Data operator + (const Data &a,const Data &b){
            return {a.len+b.len,
                    (a.sum1+b.sum1*fib[a.len-1]+b.sum2*fib[a.len])%MOD,
                    (a.sum2+b.sum1*fib[a.len]+b.sum2*fib[a.len+1])%MOD};
        }
    }t[N*4];
    ll tag[N*4];
    
    void upd(int now,ll val){
        (tag[now]+=val)%=MOD;
        (t[now].sum1+=(sumf[t[now].len])*val)%=MOD;
        (t[now].sum2+=(sumf[t[now].len+1]-1)*val)%=MOD;
    }
    void pushdown(int now) {if(tag[now]) upd(lson,tag[now]),upd(rson,tag[now]),tag[now]=0;}
    void pushup(int now) {t[now]=t[lson]+t[rson];}

    void build(int now,int l,int r,int *a){
        if(l==r){
            t[now]={1,a[l]*fib[1],a[l]*fib[2]};
            return;
        }
        build(lson,l,mid,a),build(rson,mid+1,r,a);
        pushup(now);
    }
    void modify(int now,int l,int r,int x,ll val){
        if(l==r){
            t[now]={1,val*fib[1],val*fib[2]};
            return;
        }
        pushdown(now);
        x<=mid?modify(lson,l,mid,x,val):modify(rson,mid+1,r,x,val);
        pushup(now);
    }
    void add(int now,int l,int r,int x,int y,ll val){
        if(x<=l&&r<=y) {upd(now,val);return;}
        pushdown(now);
        if(x<=mid) add(lson,l,mid,x,y,val);
        if(y>mid) add(rson,mid+1,r,x,y,val);
        pushup(now);
    }
    Data query(int now,int l,int r,int x,int y){
        if(x<=l&&r<=y) return t[now];
        pushdown(now);
        if(y<=mid) return query(lson,l,mid,x,y);
        if(x>mid) return query(rson,mid+1,r,x,y);
        return query(lson,l,mid,x,y)+query(rson,mid+1,r,x,y);
    }
#undef lson
#undef rson
#undef mid
}t;

int a[N];
void init(){
    fib[0]=0,fib[1]=1;
    for(int i=2;i<=n+1;i++) fib[i]=(fib[i-1]+fib[i-2])%MOD;
    for(int i=1;i<=n+1;i++) sumf[i]=(sumf[i-1]+fib[i])%MOD;
    t.build(1,1,n,a);
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi(),m=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi();
    init();
    while(m--){
        int op=rdi(),x,y,v;
        if(op==1) x=rdi(),v=rdi(),t.modify(1,1,n,x,v);
        if(op==2) x=rdi(),y=rdi(),cout<<t.query(1,1,n,x,y).sum1<<'\n';
        if(op==3) x=rdi(),y=rdi(),v=rdi(),t.add(1,1,n,x,y,v);
    }
    return 0;
}