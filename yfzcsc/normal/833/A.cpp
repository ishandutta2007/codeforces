#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll getpw3(ll x){
	ll l=1,r=2000000,ans=-1;
	while(l<=r){
		ll mid=l+r>>1,p=mid*mid*mid;
		if(p<x)l=mid+1;
		else if(x==p)return ans=mid;
		else r=mid-1;
	}
	return ans;
}
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		ll a,b;
		scanf("%lld%lld",&a,&b);
		ll ans=getpw3(a*b);
		if(ans==-1){
			puts("No");
			continue;
		} else {
			if(a%ans||b%ans){
				puts("No");
				continue;
			} else {
				a/=ans,b/=ans;
				if(a*b!=ans)puts("No");
				else puts("Yes");
			}
		}
	}
}