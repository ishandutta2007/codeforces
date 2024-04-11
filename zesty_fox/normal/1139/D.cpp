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

const int N=100010,MOD=1e9+7;
int v[N],p[N],pcnt,mu[N];
void init(int lim){
    mu[1]=1;
    for(int i=2;i<=lim;i++){
        if(!v[i]) {v[i]=i,p[++pcnt]=i,mu[i]=-1;}
        for(int j=1;j<=pcnt;j++){
            if(p[j]>v[i]||p[j]>lim/i) break;
            v[p[j]*i]=p[j];
            if(i%p[j]) mu[p[j]*i]=-mu[i];
            else mu[p[j]*i]=0;
        }
    }
}

inline ll qpow(ll x,ll y=MOD-2){
    ll res=1;
    while(y){
        if(y&1) (res*=x)%=MOD;
        (x*=x)%=MOD;y>>=1;
    }
    return res;
}

int m;
ll ans=1;
int main(){
    m=rdi();init(m);
    for(int d=2;d<=m;d++){
        ans=(ans-(ll)mu[d]*(m/d)*qpow(m-m/d)%MOD+MOD)%MOD;
    }
    cout<<ans<<endl;
    return 0;
}