#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
    ll f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=10007;
ll exgcd(ll a,ll b,ll &x,ll &y){
    if(!b){x=1,y=0;return a;}
    ll d=exgcd(b,a%b,x,y),z=x;
    return x=y,y=z-a/b*y,d;
}
ll mul(ll a,ll b,ll mod){
    if(b<0)a=-a,b=-b;ll res=0;
    for(;b;b>>=1,a=(a+a)%mod)
	if(b&1)res=(res+a)%mod;
    return res;
}
inline ll lcm(ll x,ll y){
    __int128 res=(__int128)x/__gcd(x,y)*y;
    if(res>1e12)return 1e13;return res;
}
ll n,m,K;
inline ll excrt(int n,ll *a,ll *b){
    ll X=b[1],M=a[1];
    for(int i=2;i<=n;i++){
	ll x,y,d=exgcd(M,a[i],x,y);
	if((b[i]-X)%d!=0)return -1;
	y=M,M=lcm(M,a[i]);
	x=mul(x,(b[i]-X)/d,M);
	X=(((mul(y,x,M)+X)%M)+M)%M;
    }
    X=(X+M-1)%M+1;
    if(X<1 || X+K-1>m)return -1;
    return X;
}
ll x,a[N],b[N];
int main(){
    n=read(),m=read(),K=read(),x=1;
    for(int i=1;i<=K;i++){
	a[i]=read(),x=lcm(x,a[i]);
	b[i]=((a[i]-i+1)%a[i]+a[i])%a[i];
    }
    if(x>n)puts("NO"),exit(0);
    ll ans=excrt(K,a,b);
    if(ans==-1)puts("NO"),exit(0);
    for(int i=1;i<=K;i++)if(__gcd(x,ans+i-1)!=a[i])puts("NO"),exit(0);
    return puts("YES"),0;
}