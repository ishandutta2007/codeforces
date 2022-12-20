#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T>
inline T read(){
    T x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

#define rdi read<int>
#define rdl read<ll>

const int MOD=1e9+7,N=5010;
int n,k,a[N];
inline ll qpow(ll x,ll y){
    ll res=1;
    while(y){
        if(y&1) (res*=x)%=MOD;
        (x*=x)%=MOD;y>>=1;
    }
    return res;
}

inline ll inv(ll x){return qpow(x,MOD-2);}
ll c[N],e;

int main(){
    n=rdi(),k=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi();
    c[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=i;j>=1;j--) c[j]=(c[j]*a[i]-c[j-1]+MOD)%MOD;
        c[0]=c[0]*a[i]%MOD;
    }
    ll frac=1,invn=inv(n),p=1;
    for(int i=0;i<=n;i++){
        (e+=c[i]*frac%MOD*p%MOD)%=MOD;
        frac=frac*(k-i)%MOD,p=p*invn%MOD;
    }
    printf("%lld\n",(c[0]+MOD-e)%MOD);
    return 0;
}