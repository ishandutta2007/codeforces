#include <bits/stdc++.h>

using namespace std;

using i64=long long;
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

const int N=2e5+10,MOD=998244353;

i64 qpow(i64 x,i64 y=MOD-2){
    i64 res=1;
    while(y){
        if(y&1) (res*=x)%=MOD;
        (x*=x)%=MOD;y>>=1;
    }
    return res;
}

i64 pw2[N],fac[N],faci[N];
void init(int n){
    pw2[0]=1;
    for(int i=1;i<=n;i++) pw2[i]=pw2[i-1]*2%MOD;
    fac[0]=1;
    for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%MOD;
    faci[n]=qpow(fac[n]);
    for(int i=n-1;i>=0;i--) faci[i]=faci[i+1]*(i+1)%MOD;
}
inline i64 C(int n,int m){
    return fac[n]*faci[m]%MOD*faci[n-m]%MOD;
}

int n;
i64 a[N];

i64 calc(int l,int r){
    if(l>=r) return 1;
    if(a[l]||a[r]){
        i64 sum1=0,sum2=a[r],p1,p2;
        for(p1=l,p2=r;p1<=r;p1++){
            sum1+=a[p1];
            while(p2>l&&sum2<sum1) --p2,sum2+=a[p2];
            if(sum1==sum2){
                if(p1==r) return 1;
                else {a[p1]=a[p2]=0;return calc(p1,p2);}
            }
        }
        assert(0);
    }
    else{
        int cl=0,cr=0;
        for(int i=l;i<=r&&!a[i];i++,cl++);
        for(int i=r;i>=l&&!a[i];i--,cr++);
        if(cl==r-l+1) return pw2[r-l];
        else{
            i64 ret=0;
            for(int i=0;i<=min(cl,cr);i++) ret+=C(cl,i)*C(cr,i)%MOD;
            return ret%MOD*calc(l+cl,r-cr)%MOD;
        }
    }
}

void solve(){
    n=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi();
    cout<<calc(1,n)<<'\n';
    for(int i=1;i<=n;i++) a[i]=0;
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    init(N-10);
    int T=rdi();
    while(T--) solve();
    return 0;
}