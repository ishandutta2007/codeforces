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

const int MOD=998244353,N=5010;
int n,m,k;
ll ans,str[N][N],inv;
ll qpow(ll x,ll y){
    ll res=1;
    while(y){
        if(y&1) (res*=x)%=MOD;
        (x*=x)%=MOD;y>>=1;
    }
    return res;
}

int main(){
    n=rdi(),m=rdi(),k=rdi();
    str[0][0]=1;inv=qpow(m,MOD-2);
    for(int i=1;i<=k;i++){
        for(int j=1;j<=i;j++) str[i][j]=(j*str[i-1][j]+str[i-1][j-1])%MOD;
    }
    ll mul=1,p=1;
    for(int i=0;i<=k;i++){
        (ans+=str[k][i]*mul%MOD*p%MOD)%=MOD;
        (mul*=(n-i))%=MOD,(p*=inv)%=MOD;
    }
    cout<<ans<<endl;
    return 0;
}