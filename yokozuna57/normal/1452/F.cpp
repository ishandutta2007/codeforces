#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ll n,q;
	ll a[32];
	scanf("%lld%lld",&n,&q);
	for(int i=0;i<n;i++)scanf("%lld",&a[i]);
	for(;q>0;q--){
		ll t,x,k;
		scanf("%lld%lld%lld",&t,&x,&k);
		if(t==1){
			a[x]=k;
		}
		else {
			ll b[32];
			for(int i=0;i<n;i++)b[i]=a[i];
			ll ret=0;
			ll cnt=0;
			for(int i=0;i<=x;i++)cnt+=b[i];
			while(1){
				if(cnt>=k)break;
				for(int i=x+1;i<n;i++){
					ll s=min(b[i],(k-cnt)/(1LL<<(i-x)));
					ret+=s*((1LL<<(i-x))-1);
					cnt+=s*(1LL<<(i-x));
					b[i]-=s;
					b[x]+=s*(1LL<<(i-x));
				}
				ll sum=0;
				for(int i=0;i<=x;i++){
					sum+=(1LL<<i)*b[i];
				}
				if(sum>=k){
					ret+=k-cnt;
					break;
				}
				int loc=x+1;
				while(loc<n&&b[loc]==0)loc++;
				if(loc==n){
					ret=-1;
					break;
				}
				ret+=loc-x;
				cnt+=2;
				b[x]+=2;
				for(int i=x+1;i<loc;i++)b[i]++;
			}
			printf("%lld\n",ret);
		}
	}
}