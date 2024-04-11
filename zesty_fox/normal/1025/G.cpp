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

const int MOD=1e9+7,N=510;

ll qpow(ll x,ll y){
    ll res=1;
    while(y){
        if(y&1) (res*=x)%=MOD;
        (x*=x)%=MOD;y>>=1;
    }
    return res;
}

int n,cnt[N];
ll ans;

int main(){
    n=rdi();
    for(int i=1;i<=n;i++){
        int x=rdi();
        if(x>0) cnt[x]++;
    }
    for(int i=1;i<=n;i++)
        if(cnt[i]) ans+=(1-qpow(2,cnt[i]));
    ans-=1-qpow(2,n-1);
    ans=(ans%MOD+MOD)%MOD;
    cout<<ans<<endl;
    return 0;
}