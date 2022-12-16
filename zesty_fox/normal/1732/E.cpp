// LUOGU_RID: 91909970
#include <bits/stdc++.h>

using namespace std;

using i64=long long;
using u32=unsigned int;
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

const int N=5e4+10,B=600;

int n,q;
u32 a[N],b[N];

vi d[N];
int bsiz,bcnt,L[B],R[B],bl[N];
u32 val[B][N],mi[B],tg[B];
void build(int id,int l,int r){
    L[id]=l,R[id]=r;
    for(int i=l;i<=r;i++) bl[i]=id;

    for(int i=1;i<N;i++) val[id][i]=0;
    for(int i=l;i<=r;i++)
        for(auto x:d[b[i]])
            if(!val[id][x]||val[id][x]>b[i])
                val[id][x]=b[i];
}

void pushdown(int id){
    if(tg[id]){
        for(int i=L[id];i<=R[id];i++) a[i]=tg[id];
        tg[id]=0;
    }
}

void aply(int id,u32 v){
    tg[id]=v,mi[id]=UINT_MAX;
    for(auto x:d[v])
        if(val[id][x])
            mi[id]=min(mi[id],(v/x)*(val[id][x]/x));
}

void update(int id){
    mi[id]=UINT_MAX;
    for(int i=L[id];i<=R[id];i++){
        u32 g=__gcd(a[i],b[i]);
        mi[id]=min(mi[id],(a[i]/g)*(b[i]/g));
    }
}

void init(){
    for(int i=1;i<N;i++)
        for(int j=i;j<N;j+=i)
            d[j].pb(i);

    bsiz=max(1.,sqrt(n));
    for(int l=1,r;l<=n;l=r+1){
        r=min(l+bsiz-1,n),++bcnt;
        build(bcnt,l,r),update(bcnt);
    }
}

void modify(int l,int r,u32 v){
    auto doit = [&](int l,int r){
        assert(bl[l]==bl[r]);
        pushdown(bl[l]);
        for(int i=l;i<=r;i++) a[i]=v;
        update(bl[l]);
    };
    if(bl[l]==bl[r]) {doit(l,r);return;}
    doit(l,R[bl[l]]),doit(L[bl[r]],r);
    for(int i=bl[l]+1;i<bl[r];i++) aply(i,v);
}

u32 query(int l,int r){
    auto doit = [&](int l,int r){
        assert(bl[l]==bl[r]);
        pushdown(bl[l]);
        u32 ret=UINT_MAX;
        for(int i=l;i<=r;i++){
            u32 g=__gcd(a[i],b[i]);
            ret=min(ret,(a[i]/g)*(b[i]/g));
        }
        return ret;
    };

    if(bl[l]==bl[r]) return doit(l,r);
    u32 ret=min(doit(l,R[bl[l]]),doit(L[bl[r]],r));
    for(int i=bl[l]+1;i<bl[r];i++) ret=min(ret,mi[i]);
    return ret;
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi(),q=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi();
    for(int i=1;i<=n;i++) b[i]=rdi();
    init();
    while(q--){
        int op=rdi();
        if(op==1){
            int l=rdi(),r=rdi(),v=rdi();
            modify(l,r,v);
        }
        else{
            int l=rdi(),r=rdi();
            cout<<query(l,r)<<'\n';
        }
    }
    return 0;
}