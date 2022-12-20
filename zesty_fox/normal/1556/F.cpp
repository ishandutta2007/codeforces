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
#define mp make_pair
#define pb push_back

const int N=15,MOD=1e9+7;
inline ll qpow(ll x,ll y=MOD-2){
    ll res=1;
    while(y){
        if(y&1) (res*=x)%=MOD;
        (x*=x)%=MOD;y>>=1;
    }
    return res;
}

int n;
ll win[N][1<<N],a[N];
void init(){
    for(int i=1;i<=n;i++){
        for(int j=0;j<(1<<n);j++){
            win[i][j]=1;
            for(int k=1;k<=n;k++){
                if(j>>(k-1)&1) win[i][j]=win[i][j]*a[i]%MOD*qpow(a[i]+a[k])%MOD;
            }
        }
    }
}

inline ll G(int x,int y){
    ll res=1;
    for(int i=1;i<=n;i++){
        if(x>>(i-1)&1) res=res*win[i][y]%MOD;
    }
    return res;
}

ll p[1<<N],ans;
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
#endif
    n=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi();
    init();
    for(int i=0;i<(1<<n);i++){
        p[i]=1;
        for(int s=i;s;s=(s-1)&i){
            if(s==i) continue;
            p[i]=(p[i]+MOD-p[i^s]*G(i^s,s)%MOD)%MOD;
        }
        ans=(ans+p[i]*G(i,((1<<n)-1)^i)%MOD*__builtin_popcount(i))%MOD;
    }
    cout<<ans<<endl;
    return 0;
}