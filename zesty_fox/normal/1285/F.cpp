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

const int N=1e5+10;

vi fac[N];
int v[N],mu[N],p[N],pc;
void init(int n){
    mu[1]=1;
    for(int i=2;i<=n;i++){
        if(!v[i])
            v[i]=i,p[++pc]=i,mu[i]=-1;
        for(int j=1;j<=pc;j++){
            if(p[j]>v[i]||p[j]>n/i)
                break;
            v[p[j]*i]=p[j];
            mu[p[j]*i]=(i%p[j]?-mu[i]:0);
        }
    }

    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j+=i)
            fac[j].pb(i);
}

int n,a[N],b[N];
vi val[N];

i64 calc(int a[],int n){
    sort(a,a+n);
    static int st[N],cnt[N];
    int tp=0;

    auto modify = [&](int x,int v){
        for(auto d:fac[x])
            cnt[d]+=v;
    };
    auto count = [&](int x){
        int ret=0;
        for(auto d:fac[x])
            ret+=cnt[d]*mu[d];
        return ret;
    };

    i64 ret=0;
    for(int i=n-1;i>=0;i--){
        int c=count(a[i]);
        if(c){
            int v=0;
            while(tp){
                c-=(__gcd(a[i],st[tp])==1);
                if(!c) {v=st[tp];break;}
                modify(st[tp--],-1);
            }
            modify(st[tp--],-1);
            ret=max(ret,(i64)a[i]*v);
        }
        modify(a[i],1),st[++tp]=a[i];
    }
    while(tp)
        modify(st[tp],-1),--tp;
    return ret;
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    init(N-10);
    n=rdi();
    for(int i=1;i<=n;i++){
        a[i]=rdi();
        for(int d:fac[a[i]])
            val[d].pb(a[i]/d);
    }

    i64 ans=0;
    for(int d=1;d<N;d++)
        if(val[d].size()>1)
            ans=max(ans,calc(val[d].data(),val[d].size())*d);
    cout<<ans<<endl;
    return 0;
}