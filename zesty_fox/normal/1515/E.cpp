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

const int N=410;

int n,MOD;
ll f[N][N];

ll fac[N],faci[N];
inline ll qpow(ll x,ll y=MOD-2){
    if(y<0) return 1;
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

inline ll C(int x,int y){
    if(x<0||y<0||x<y) return 0;
    return fac[x]*faci[y]%MOD*faci[x-y]%MOD;
}

ll ans;
int main(){
    n=rdi(),MOD=rdi();init(n);
    f[0][0]=1;
    for(int i=1;i<=n;i++){
        f[i][0]=qpow(2,i-1);
        for(int j=1;j<=i;j++){
            ll pw=1;
            for(int k=i-1;k>1;k--,pw=pw*2%MOD){
                f[i][j]=(f[i][j]+f[k-1][j-1]*pw%MOD*C(i-j,i-k))%MOD;
            }
        }
    }
    for(int i=0;i<=n;i++) (ans+=f[n][i])%=MOD;
    cout<<ans<<endl;
    return 0;
}