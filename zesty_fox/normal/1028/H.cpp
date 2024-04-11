// LUOGU_RID: 94979538
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

const int N=2e5+10,M=1.1e6,MX=5.1e6;
const int INF=0x3f3f3f3f;

int a[N],n,q,res[M];
struct Query{int l,r,id;}b[M];

int p[MX],ptot,v[MX],pc[MX];
void sieve(int mx){
    v[1]=1,pc[1]=0;
    for(int i=2;i<=mx;i++){
        if(!v[i]) v[i]=i,p[++ptot]=i,pc[i]=1;
        for(int j=1;j<=ptot;j++){
            if(p[j]>v[i]||p[j]*i>mx) break;
            v[p[j]*i]=p[j],pc[p[j]*i]=pc[i]+1;
        }
    }
}

int process(int x){
    int ret=1;
    while(x>1){
        if(v[x/v[x]]==v[x]) x/=v[x]*v[x];
        else ret*=v[x],x/=v[x];
    }
    return ret;
}

vi pos[MX];
vector<pii> vec[N];

void init(){
    sieve(MX-1);
    for(int i=1;i<=n;i++){
        a[i]=process(a[i]);
        for(int d=1;d*d<=a[i];d++){
            if(a[i]%d==0){
                pos[d].pb(i);
                if(d*d!=a[i]) pos[a[i]/d].pb(i);
            }
        }
    }
    for(int v=1;v<MX;v++){
        if(pos[v].empty()) continue;
        static pii buf[N];int tot=0;
        for(auto cur:pos[v]) buf[++tot]={pc[a[cur]],cur};
        static pii st[N];int tp=0;
        for(int i=1;i<=tot;i++){
            while(tp&&st[tp].fi>buf[i].fi) --tp;
            if(tp) vec[buf[i].se].pb({st[tp].se,st[tp].fi+buf[i].fi-2*pc[v]});
            st[++tp]=buf[i];
        }
        tp=0;
        for(int i=tot;i>=1;i--){
            while(tp&&st[tp].fi>buf[i].fi) --tp;
            if(tp) vec[st[tp].se].pb({buf[i].se,st[tp].fi+buf[i].fi-2*pc[v]});
            st[++tp]=buf[i];
        }
    }
}

void solve(){
    init();
    sort(b+1,b+q+1,[&](const Query &a,const Query &b) {return a.r<b.r;});
    static int val[N];
    fill(val+1,val+n+1,INF);
    for(int i=1,pos=1;i<=n;i++){
        for(auto cur:vec[i]){
            for(int j=cur.fi;j>=1&&val[j]>cur.se;j--)
                val[j]=cur.se;
        }
        while(pos<=q&&b[pos].r==i)
            res[b[pos].id]=val[b[pos].l],++pos;
    }
    for(int i=1;i<=q;i++)
        cout<<res[i]<<'\n';
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi(),q=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi();
    for(int i=1;i<=q;i++){
        int l=rdi(),r=rdi();
        b[i]={l,r,i};
    }
    solve();
    return 0;
}