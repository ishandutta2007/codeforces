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

const int N=100010,M=80,MOD=1e9+7;

ll s[M];
int v[M],p[M],pcnt,id[M];
void init(int lim){
    for(int i=2;i<=lim;i++){
        if(!v[i]) {v[i]=i,p[++pcnt]=i,id[i]=pcnt,s[i]=(1ll<<id[i]);}
        for(int j=1;j<=pcnt;j++){
            if(p[j]>v[i]||p[j]>lim/i) break;
            v[i*p[j]]=p[j],s[i*p[j]]=s[i]^(1ll<<j);
        }
    }
}

inline ll qpow(ll x,ll y){
    ll res=1;
    while(y){
        if(y&1) (res*=x)%=MOD;
        (x*=x)%=MOD;y>>=1;
    }
    return res;
}

ll a[M];
int n,sum;
bool insert(ll x){
    for(int i=pcnt;i>=1;i--){
        if(x>>i&1){
            if(a[i]) x^=a[i];
            else {a[i]=x;return true;}
        }
    }
    return false;
}

int main(){
    init(M-10);n=rdi();
    for(int i=1;i<=n;i++) sum+=insert(s[rdi()]);
    printf("%lld\n",qpow(2,n-sum)-1);
    return 0;
}