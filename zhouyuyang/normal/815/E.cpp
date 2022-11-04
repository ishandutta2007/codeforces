#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll get(ll x,ll v){
	if (x<=v*2) return 0;
	ll s1=1,s2=0,p1=x,p2=x-1,ans=0;
	for (;p2>=v*2;p1/=2,p2=p1-1){
		if (p2==v*2) return s1+ans;
		ans+=s1+s2;
		if (p1&1) s1=s1*2+s2;
		else s2=s2*2+s1;
	}
	return ans;
}
ll solve(ll l,ll r,ll p,ll k){
	ll mid=(l+r)/2;
	if (k==1) return mid;
	ll tmp=get(mid-l,p),Tmp=get(r-mid,p+1);
	if (k>tmp+Tmp+1) return solve(mid+1,r,p,k-tmp-1);
	return solve(l,mid-1,p,k-Tmp-1);
}
int main(){
	ll n,k;
	scanf("%lld%lld",&n,&k);
	if (k==1) return puts("1"),0;
	if (k==2) return printf("%lld",n),0;
	n-=2; k-=2;
	ll l=0,r=n/2+1,mid;
	while (r-l>1){
		mid=(l+r)/2;
		if (get(n,mid)<k) r=mid;
		else l=mid;
	}
	printf("%lld\n",solve(1,n,l,k)+1);
}