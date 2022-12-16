#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

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
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=2000010,MOD=998244353;
ll fac[N],faci[N];
inline ll qpow(ll x,ll y=MOD-2){
    if(y<0) x=qpow(x),y=-y;
    ll res=1;
    while(y){
        if(y&1) (res*=x)%=MOD;
        (x*=x)%=MOD;y>>=1;
    }
    return res;
}

void init(int lim){
    fac[0]=1;
    for(int i=1;i<=lim;i++) fac[i]=fac[i-1]*i%MOD;
    faci[lim]=qpow(fac[lim]);
    for(int i=lim-1;i>=0;i--) faci[i]=faci[i+1]*(i+1)%MOD;
}

inline ll C(int x,int y){return fac[x]*faci[y]%MOD*faci[x-y]%MOD;}

int n;
ll ans;

int main(){
    init(N-10);
    n=rdi();
    ll sum1=0;
    for(int i=1,c=1;i<=n;i++,c=-c){
        sum1+=c*C(n,i)*qpow(3,(ll)-n*i)%MOD*(qpow(1-qpow(3,i-n)+MOD,n)-1)%MOD;
        sum1%=MOD;
    }
    sum1=sum1*qpow(3,(ll)n*n+1)%MOD;
    ll sum2=0;
    for(int i=1,c=1;i<=n;i++,c=-c){
        sum2+=c*C(n,i)*qpow(3,(ll)n*(n-i)+i)%MOD;
        sum2%=MOD;
    }
    sum2=sum2*2%MOD;
    ans=(sum1+sum2)%MOD;
    ans=(ans%MOD+MOD)%MOD;
    cout<<ans<<endl;
    return 0;
}