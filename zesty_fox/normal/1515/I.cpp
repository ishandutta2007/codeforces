#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef double db;
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
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=2e5+10,L=54;
const i64 INFl=0x3f3f3f3f3f3f3f3f;

struct Diamond{i64 c,w,v;int id;}d[N];
int n,q,id[N];

struct SGT{
#define lson (now<<1)
#define rson (now<<1|1)
#define mid ((l+r)>>1)
    // light diamond 
    array<i64,L> sw[N*3],sv[N*3];
    // Heavy diamond
    array<i64,L> mi[N*3];

    inline bool islight(int x,int hi) {return d[x].w<(1ll<<(hi-1));}
    inline bool isheavy(int x,int hi) {return (1ll<<(hi-1))<=d[x].w&&d[x].w<(1ll<<hi);}
    void pushup(int now){
        for(int i=1;i<L;i++){
            sw[now][i]=sw[lson][i]+sw[rson][i],sv[now][i]=sv[lson][i]+sv[rson][i];
            mi[now][i]=min(mi[lson][i],mi[rson][i]+sw[lson][i]);
        }
    }

    // remember to modify d[x].c first
    void upd(int now,int l,int r,int x){
        if(l==r){
            for(int i=1;i<L;i++){
                sw[now][i]=sv[now][i]=0,mi[now][i]=INFl;
                if(islight(x,i)) sw[now][i]=d[x].c*d[x].w,sv[now][i]=d[x].c*d[x].v;
                else if(isheavy(x,i)) mi[now][i]=(d[x].c?d[x].w:INFl);
            }
            return;
        }
        if(x<=mid) upd(lson,l,mid,x);
        else upd(rson,mid+1,r,x);
        pushup(now);
    }
    i64 query(int now,int l,int r,i64 &C){
        if(l==r){
            i64 c=min(d[l].c,C/d[l].w);
            C-=(i64)c*d[l].w;return c*d[l].v;
        }
        if(!C) return 0;
        int hi=__lg(C)+1;
        if(C>=sw[now][hi+1]) {C-=sw[now][hi+1];return sv[now][hi+1];}
        else if(sw[now][hi]<=C&&C<mi[now][hi]) {C-=sw[now][hi];return sv[now][hi];}
        else return query(lson,l,mid,C)+query(rson,mid+1,r,C);
    }
#undef lson
#undef rson
#undef mid
}t;

void init(){
    n=rdi(),q=rdi();
    for(int i=1;i<=n;i++) d[i].c=rdi(),d[i].w=rdi(),d[i].v=rdi(),d[i].id=i;
    sort(d+1,d+n+1,[&](auto a,auto b){return a.v!=b.v?a.v>b.v:a.w<b.w;});
    for(int i=1;i<=n;i++) id[d[i].id]=i,t.upd(1,1,n,i);
}

i64 query(i64 C){
    return t.query(1,1,n,C=min(C,(i64)4e15));
}

void solve(){
    while(q--){
        int op=rdi();
        if(op==1){
            int c=rdi(),typ=rdi();
            d[id[typ]].c+=c,t.upd(1,1,n,id[typ]);
        }
        else if(op==2){
            int c=rdi(),typ=rdi();
            d[id[typ]].c-=c,t.upd(1,1,n,id[typ]);
        }
        else cout<<query(rdi64())<<'\n';
    }
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    init();solve();
    return 0;
}