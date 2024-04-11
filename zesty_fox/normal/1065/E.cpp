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

const int N=200010,MOD=998244353;
int n,m,A,b[N];
ll qpow(ll x,ll y=MOD-2){
    ll res=1;
    while(y){
        if(y&1) (res*=x)%=MOD;
        (x*=x)%=MOD;y>>=1;
    }
    return res;
}

ll ans=1;
int main(){
    n=rdi(),m=rdi(),A=rdi();
    for(int i=1;i<=m;i++) b[i]=rdi();
    for(int i=m;i>=1;i--) b[i]=b[i]-b[i-1];
    ll invA=qpow(A);
    for(int i=1;i<=m;i++) ans=ans*(qpow(invA,b[i])+1)%MOD;
    ans=ans*qpow(A,n)%MOD*qpow(qpow(2),m)%MOD;
    cout<<ans<<endl;
    return 0;
}