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

const int MOD=1e9+7,N=2e6+10;

i64 pw2[N],fac[N];
void init(int n){
    pw2[0]=1;
    for(int i=1;i<=n;i++)
        pw2[i]=pw2[i-1]*2%MOD;
    fac[0]=1;
    for(int i=1;i<=n;i++)
        fac[i]=fac[i-1]*i%MOD;
}

i64 qpow(i64 x,i64 y=MOD-2){
    i64 res=1;
    while(y){
        if(y&1) (res*=x)%=MOD;
        (x*=x)%=MOD;y>>=1;
    }
    return res;
}

int n,c[N];
i64 res[N],f[N];

void solve(){
    n=rdi();
    if(n==1){
        cout<<1<<'\n';
        return;
    }
    for(int i=1;i<=n;i++)
        c[i]=(i+1)/2;
    f[n]=2;
    i64 sum=0;
    for(int i=n,j=n;i>=2;i--){
        sum=sum*2%MOD;
        while(j-c[j]+1>i)
            sum+=f[j]*pw2[j-c[j]-i]%MOD,--j;
        if(i!=n)
            f[i]=(pw2[n-i]-sum)%MOD;
        res[i]=pw2[i-c[i]]*f[i]%MOD;
    }
    i64 inv=qpow(pw2[n]);
    for(int i=1;i<=n;i++){
        res[i]=(res[i]%MOD+MOD)%MOD*inv%MOD;
        cout<<res[i]<<'\n';
    }
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    init(1000000);
    int T=rdi();
    while(T--) solve();
    return 0;
}