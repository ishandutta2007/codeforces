//duang duang miao miao wu, kai qi!
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
#define rdl read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=100010,MOD=1e9+7;
int n,a[N],maxn;
inline ll qpow(ll x,ll y=MOD-2){
    ll res=1;
    while(y){
        if(y&1) (res*=x)%=MOD;
        (x*=x)%=MOD;y>>=1;
    }
    return res;
}

ll f[N],ans,sum;
int main(){
    n=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi(),sum+=a[i],maxn=max(maxn,a[i]);
    sum%=MOD;
    f[1]=(sum-1)*(sum-1)%MOD*qpow(sum)%MOD;
    f[2]=(2*f[1]-1)%MOD;
    ll cha=f[2]-f[1];
    for(int i=3;i<=maxn;i++){
        cha-=(sum-1)*qpow(sum-i+1)%MOD;cha%=MOD;
        f[i]=((f[i-1]+cha)%MOD+MOD)%MOD;
    }
    for(int i=1;i<=n;i++) (ans+=f[a[i]])%=MOD;
    cout<<ans<<endl;
    return 0;
}