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

const int MOD=1e9+7,N=1e5+10;

inline i64 qpow(i64 x,i64 y=MOD-2){
    i64 res=1;
    while(y){
        if(y&1) (res*=x)%=MOD;
        (x*=x)%=MOD;y>>=1;
    }
    return res;
}

int n,k;
i64 fac[N],faci[N];

void init(){
    fac[0]=1;
    for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%MOD;
    faci[n]=qpow(fac[n]);
    for(int i=n-1;i>=0;i--) faci[i]=faci[i+1]*(i+1)%MOD;
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi(),k=min(rdi(),n);init();
    i64 ans=0;
    for(int i=0;i<=k;i++) ans+=fac[n]*faci[i]%MOD*faci[n-i]%MOD;
    ans%=MOD;cout<<ans<<endl;
    return 0;
}