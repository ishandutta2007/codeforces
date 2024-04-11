#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
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

const int N=400010,MOD=1e9+7;

i64 qpow(i64 x,i64 y=MOD-2){
    i64 res=1;
    while(y){
        if(y&1) (res*=x)%=MOD;
        (x*=x)%=MOD;y>>=1;
    }
    return res;
}

i64 fac[N],faci[N];

void init(int lim){
    fac[0]=1;
    for(int i=1;i<=lim;i++) fac[i]=fac[i-1]*i%MOD;
    faci[lim]=qpow(fac[lim]);
    for(int i=lim-1;i>=0;i--) faci[i]=faci[i+1]*(i+1)%MOD;
}

i64 C(int x,int y) {return x<y?0:fac[x]*faci[y]%MOD*faci[x-y]%MOD;}

int n,a[N];
i64 ans;

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi();
    for(int i=0;i<=n;i++) a[i]=rdi();
    init(n+a[0]);
    for(int i=0;i<=n;i++) ans+=C(a[i]+i,i+1);
    ans%=MOD;cout<<ans<<endl;
    return 0;
}