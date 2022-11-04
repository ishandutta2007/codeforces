#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=200005;
ll a[N],fac[1000];
ll all[N],cnt[N];
int n;
ll mul(ll x,ll y,ll mo){
	ll s=0;
	for (;y;y/=2,x=(x+x)%mo)
		if (y&1) s=(s+x)%mo;
	return s;
}
ll power(ll x,ll y,ll mo){
	ll s=1;
	for (;y;y/=2,x=mul(x,x,mo))
		if (y&1) s=mul(s,x,mo);
	return s;
}
ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
bool isprime(ll x){
	if (x==2) return 1;
	for (int T=10;T;T--){
		ll a=rand()%(x-2)+2;
		if (power(a,x-1,x)!=1) return 0;
		int p=x-1;
		for (;p%2==0;){
			p/=2;
			ll v=power(a,p,x);
			if (mul(v,v,x)==1&&v!=1&&v!=x-1) return 0;
		}
	}
	return 1;
}
ll pollard(ll n,int c){
	ll i=0,k=2,x=rand()%(n-1)+1,y=x;
	for (;;){
		x=(mul(x,x,n)+c)%n;
		ll g=gcd((y-x+n)%n,n);
		if (g!=1&&g!=n) return g;
		if (x==y) return n;
		if ((++i)==k) y=x,k<<=1;
	}
}
void getfact(ll n,int cnt){
	if (n==1) return;
	if (isprime(n)){
		fac[++*fac]=n;
		return;
	}
	ll p=n;
	for (;p>=n;p=pollard(n,cnt--));
	getfact(p,cnt);
	getfact(n/p,cnt);
}
int get(ll x){
	int S=0;
	for (int i=1;i<=*fac;i++)
		if (x%fac[i]==0) S|=1<<(i-1);
	return S;
}
ll x,y;
int main(){
	scanf("%d%lld%lld",&n,&x,&y);
	if (y%x) return puts("0"),0;
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	getfact(y,123);
	sort(fac+1,fac+*fac+1);
	*fac=unique(fac+1,fac+*fac+1)-fac-1;
	int wzp=(1<<*fac)-1;
	for (int i=1;i<=n;i++)
		if (a[i]%x==0) ++cnt[wzp^get(a[i]/x)];
	for (int i=0;i<=wzp;i++){
		for (int j=i;j;j=(j-1)&i) all[j]+=cnt[i];
		all[0]+=cnt[i];
	}
	ll ans=0;
	for (int i=1;i<=n;i++){
		if (y%a[i]) continue;
		ll cur=x;
		for (;;){
			ll lcm=(a[i]/gcd(a[i],cur))*cur;
			if (lcm==y) break;
			cur*=y/lcm;
		}
		cur/=x;
		ans+=all[get(cur)];
	}
	printf("%lld",ans);
}