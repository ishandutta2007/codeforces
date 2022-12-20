#include <bits/stdc++.h>
#include <random>

using namespace std;

using i64=long long;
using u64=unsigned long long;
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

const int N=6e5+10;

int n,q,a[N],res[N];

struct BIT{
    int mx;
    i64 sum[N];
    void init(int n){
        mx=n,fill(sum,sum+mx+1,0);
    }
    void add(int x,i64 v){
        for(;x<=mx;x+=(x&(-x)))
            sum[x]+=v;
    }
    i64 query(int x){
        i64 ret=0;
        for(;x;x-=(x&(-x)))
            ret+=sum[x];
        return ret;
    }
}t;

mt19937 rng(random_device {}());

int v[N],tot,ha[N],pos[N];
struct Op{int op,x,y,k;}p[N];
void discrete(){
    for(int i=1;i<=n;i++) v[++tot]=a[i];
    for(int i=1;i<=q;i++)
        if(p[i].op==1) v[++tot]=p[i].k;
    sort(v+1,v+tot+1);
    tot=unique(v+1,v+tot+1)-v-1;
    auto getrk = [&](int x){
        return lower_bound(v+1,v+tot+1,x)-v;
    };
    for(int i=1;i<=n;i++) a[i]=getrk(a[i]);
    for(int i=1;i<=q;i++)
        if(p[i].op==1) p[i].k=getrk(p[i].k);
}

void doit(){
    for(int i=1;i<=tot;i++) ha[i]=rng()/2;
    static int a1[N];
    t.init(n);
    for(int i=1;i<=n;i++) t.add(i,ha[a1[i]=a[i]]);
    for(int i=1;i<=q;i++){
        if(p[i].op==1){
            t.add(p[i].x,ha[p[i].k]-ha[a1[p[i].x]]);
            a1[p[i].x]=p[i].k;
        }
        else{
            i64 sum=t.query(p[i].y)-t.query(p[i].x-1);
            if(sum%p[i].k) res[i]=0;
        }
    }
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi(),q=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi();
    for(int i=1;i<=q;i++){
        p[i].op=rdi();
        if(p[i].op==1)
            p[i].x=rdi(),p[i].k=rdi();
        else{
            p[i].x=rdi(),p[i].y=rdi(),p[i].k=rdi();
            res[i]=1;
        }
    }
    discrete();
    for(int i=1;i<=60;i++) doit();
    for(int i=1;i<=q;i++)
        if(p[i].op==2) puts(res[i]?"YES":"NO");
    return 0;
}