#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using vi=vector<int>;
using pii=pair<int,int>;

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
#define mp make_pair
#define pb push_back

const int N=100010,MOD=1e9+7;
int n,a[N];

int p[N],pcnt,v[N],phi[N];
vi fac[N];
void init(int lim){
    v[1]=1,phi[1]=1;
    for(int i=2;i<=lim;i++){
        if(!v[i]) {v[i]=i,p[++pcnt]=i,phi[i]=i-1;}
        for(int j=1;j<=pcnt;j++){
            if(p[j]>v[i]||p[j]>lim/i) break;
            v[p[j]*i]=p[j],phi[p[j]*i]=(i%p[j]?phi[i]*(p[j]-1):phi[i]*p[j]);
        }
    }
    for(int i=1;i<=lim;i++){
        for(int j=i;j<=lim;j+=i) fac[j].pb(i);
    }
}

ll ans;
int cnt[N];
ll solve(const vi &b){
    ll sum=0;
    for(auto x:b){
        for(auto T:fac[x]){
            sum=(sum+(2ll*cnt[T]+1)*phi[T])%MOD;
            cnt[T]++;
        }
    }
    for(auto x:b){
        for(auto T:fac[x]) cnt[T]--;
    }
    return sum;
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi();init(N-10);
    for(int i=1;i<=n;i++) a[i]=rdi();
    for(int T=1;T<=n;T++){
        vi tmp;
        for(int i=T;i<=n;i+=T) tmp.pb(a[i]);
        ans=(ans+phi[T]*solve(tmp))%MOD;
    }
    ans=(ans%MOD+MOD)%MOD;
    cout<<ans<<endl;
    return 0;
}