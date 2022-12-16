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

const int MOD=1e9+7;
int n;
ll delta,ans;

void solve(){
    n=rdi();map<ll,ll> f;
    f[0]=ans=1,delta=0;
    for(int i=1;i<=n;i++){
        int b=rdi();
        ll val=(ans-f[-delta]+MOD)%MOD;
        (ans+=val)%=MOD,(f[-delta]+=val)%=MOD;
        delta+=b;
    }   
    printf("%lld\n",ans);
}

int T;
int main(){
    T=rdi();
    while(T--) solve();
    return 0;
}