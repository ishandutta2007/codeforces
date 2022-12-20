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

const int N=2000010,MOD=1e9+7;

int pr[N],pcnt,mu[N],sumu[N],v[N];
ll pw[N];
inline ll qpow(ll x,ll y){
    ll res=1;
    while(y){
        if(y&1) (res*=x)%=MOD;
        (x*=x)%=MOD;y>>=1;
    }
    return res;
}

int n,k;

void init(){
    mu[1]=1;
    for(int i=2;i<=k;i++){
        if(!v[i]) {v[i]=i,pr[++pcnt]=i,mu[i]=-1;}
        for(int j=1;j<=pcnt;j++){
            if(pr[j]>v[i]||pr[j]>k/i) break;
            v[pr[j]*i]=pr[j];
            if(i%pr[j]) mu[pr[j]*i]=-mu[i];
            else mu[pr[j]*i]=0;
        }
    }
    for(int i=1;i<=k;i++) sumu[i]=sumu[i-1]+mu[i];
    
    for(int i=1;i<=k;i++) pw[i]=qpow(i,n);
}

ll b[N],ans;
int main(){
    n=rdi(),k=rdi();init();
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k/i;j++){
            (b[i*j]+=mu[i]*(pw[j]-pw[j-1]))%=MOD;
        }
    }
    for(int i=1;i<=k;i++) (b[i]+=b[i-1])%=MOD;
    for(int i=1;i<=k;i++) b[i]=(b[i]+MOD)%MOD,ans+=(b[i]^i);
    ans%=MOD;cout<<ans<<endl;
    return 0;
}