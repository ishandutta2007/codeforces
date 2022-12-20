#include <bits/stdc++.h>

using namespace std;

using i64=long long;
using db=double;
using vi=vector<int>;
using pii=pair<int,int>;

template <typename T>
T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define mp make_pair
#define pb push_back
#define fi first
#define se second

const int N=2e4+10,MOD=998244353;

i64 qpow(i64 x,i64 y=MOD-2){
    i64 res=1;
    while(y){
        if(y&1) (res*=x)%=MOD;
        (x*=x)%=MOD;y>>=1;
    }
    return res;
}

int n,m,k;

i64 fac[N],faci[N],invn;

void init(int n){
    fac[0]=1;
    for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%MOD;
    faci[n]=qpow(fac[n]);
    for(int i=n-1;i>=0;i--) faci[i]=faci[i+1]*(i+1)%MOD;
} 

inline i64 C(int x,int y){
    if(x==y) return 1;
    else if(x<0||y<0) return 0;
    return fac[x]*faci[y]%MOD*faci[x-y]%MOD;
}

int main(){
    n=rdi(),m=rdi(),k=rdi();
    init(n+m);
    i64 ans=0;
    for(int c=0;c*k<=m&&c<=n;c++) ans+=(c&1?-1:1)*C(n,c)*C(m-c*k+n-1,n-1)%MOD;
    ans=(qpow(n)*C(m+n-1,n-1)-ans%MOD*qpow(n))%MOD*qpow(C(m-k+n-1,n-1))%MOD;
    ans=(ans%MOD+MOD)%MOD;
    cout<<ans<<endl;
    return 0;
}