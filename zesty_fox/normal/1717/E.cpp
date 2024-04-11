#include <bits/stdc++.h>

using namespace std;

using i64=long long;
using vi=vector<int>;
using pii=pair<int,int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=(x*10)+(ch^48),ch=getchar();
    return !f?x:-x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=1e5+10,MOD=1e9+7;

int n,phi[N],p[N],pcnt,v[N];
vi fac[N];

void init(){
    phi[1]=1;
    for(int i=2;i<=n;i++){
        if(!v[i]) {v[i]=i,p[++pcnt]=i,phi[i]=i-1;}
        for(int j=1;j<=pcnt;j++){
            if(p[j]>v[i]||p[j]>n/i) break;
            v[p[j]*i]=p[j];
            phi[p[j]*i]=i%p[j]?phi[i]*(p[j]-1):phi[i]*p[j];
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j+=i) fac[j].pb(i);
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi();init();
    i64 ans=0;
    for(int c=1;c<=n-2;c++)
        for(auto d:fac[n-c]){
            if(d==n-c) break;
            ans+=(i64)c/__gcd(d,c)*d%MOD*phi[(n-c)/d];
        }
    ans%=MOD;
    cout<<ans<<endl;
    return 0;
}