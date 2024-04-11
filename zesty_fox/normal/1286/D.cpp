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

const int N=100010,MOD=998244353,INV100=828542813;

ll qpow(ll x,ll y=MOD-2){
    ll res=1;
    while(y){
        if(y&1) (res*=x)%=MOD;
        (x*=x)%=MOD;y>>=1;
    }
    return res;
}

int n;
ll ans;
struct Proton{int x,v,p[2];}p[N];

struct Hit{
    int x,fx,y,fy;
    int dis() const{return p[y].x-p[x].x;}
    int relV() const{return fx^fy?p[x].v+p[y].v:abs(p[x].v-p[y].v);}
};
vector<Hit> v;

struct Matrix{
    array<array<int,3>,3> a;
    int n,m;
    Matrix(int _n=0,int _m=0){
        n=_n,m=_m;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++) a[i][j]=0;
    }
    array<int,3>& operator [](int idx) {return a[idx];}
    friend Matrix operator * (Matrix a,Matrix b){
        Matrix res(a.n,b.m);
        for(int i=0;i<res.n;i++)
            for(int j=0;j<res.m;j++)
                for(int k=0;k<a.m;k++)
                    (res[i][j]+=(ll)a[i][k]*b[k][j]%MOD)%=MOD;
        return res;
    }
};

struct SGT{
#define lson (now<<1)
#define rson (now<<1|1)
#define mid ((l+r)>>1)
    Matrix t[N*4];
    void pushup(int now) {t[now]=t[lson]*t[rson];}
    void init(int now,int l,int r,Matrix *m){
        if(l==r){
            t[now]=m[l];
            
            return;
        }
        init(lson,l,mid,m);init(rson,mid+1,r,m);
        pushup(now);
    }
    void modify(int now,int l,int r,int x,const Matrix &v){
        if(l==r) {t[now]=v;return;}
        x<=mid?modify(lson,l,mid,x,v):modify(rson,mid+1,r,x,v);
        pushup(now);
    }
    Matrix query() {return t[1];}
#undef lson
#undef rson
#undef mid
}t;

Matrix m[N];
void init(){
    for(int i=1;i<=n;i++){
        int p0=p[i].p[0],p1=p[i].p[1];
        m[i]=Matrix(2,2);
        m[i][0]={p0,p1};
        m[i][1]={p0,p1};
    }
    t.init(1,1,n,m);
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi();
    for(int i=1;i<=n;i++){
        p[i].x=rdi(),p[i].v=rdi();
        p[i].p[1]=(ll)rdi()*INV100%MOD;
        p[i].p[0]=(MOD+1-p[i].p[1])%MOD;
    }
    
    for(int i=1;i<n;i++){
        v.pb({i,1,i+1,0});
        if(p[i].v>p[i+1].v) v.pb({i,1,i+1,1});
        if(p[i].v<p[i+1].v) v.pb({i,0,i+1,0});
    }
    sort(v.begin(),v.end(),[&](Hit a,Hit b){
        return (ll)a.dis()*b.relV()<(ll)b.dis()*a.relV();
    });
    init();
    for(auto now:v){
        int x=now.x,y=now.y;
        Matrix tmp(2,2);
        tmp[now.fx][now.fy]=p[y].p[now.fy];
        t.modify(1,1,n,y,tmp);
        
        int ti=(ll)now.dis()*qpow(now.relV())%MOD;
        auto res=t.query();ll sum=0;
        for(int i:{0,1}) sum+=res[0][i];
        ans+=sum%MOD*ti%MOD;

        m[y][now.fx][now.fy]=0;
        t.modify(1,1,n,y,m[y]);
    }
    ans%=MOD;
    cout<<ans<<endl;
    return 0;
}