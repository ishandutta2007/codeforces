#include<bits/stdc++.h>
#define maxn 300005
using namespace std;
typedef long long ll;
const ll M=1020304067;
ll mu[maxn],l,r,mid,n,a[maxn],cnt[maxn],f[maxn],nf[maxn],inv[maxn],x,w;
ll C(ll x,ll y){
    if (y>x) return 0;
    return f[x]*nf[y]%M*nf[x-y]%M;
}
bool check(ll x){
    ll res=0;
    for (int i=1;i<maxn;i++) if (mu[i]) (res+=mu[i]*C(cnt[i],x))%=M;
    res=(res+M)%M;
    return (bool)res;
}

int main(){
    inv[1]=1; for (int i=2;i<maxn;i++) inv[i]=M-(M/i)*inv[M%i]%M;
    f[0]=nf[0]=1; for (int i=1;i<maxn;i++) f[i]=f[i-1]*i%M,nf[i]=nf[i-1]*inv[i]%M;
    x=0; cin >> n; mu[1]=1;
    for (int i=1;i<=n;i++){
        scanf("%I64d",&w); a[w]++; x=__gcd(x,w);
    }
    if (x>1) {puts("-1");return 0;}
    for (int i=1;i<maxn;i++) for (int j=2;j*i<maxn;j++) mu[i*j]-=mu[i];
    for (int i=1;i<maxn;i++) for (int j=1;j*i<maxn;j++) cnt[i]+=a[i*j];
    l=0; r=n;
    while (r-l>1){
        mid=(l+r)>>1;
        if (check(mid)) r=mid; else l=mid;
    }
    cout << r << endl;
}