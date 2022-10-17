#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll a[100010];

void solve(){
	ll sum=0;
	for(int i=0;i<n;i++)sum+=a[i];
	
	ll x=(sum+n-2)/(n-1);
	for(int i=0;i<n;i++)x=max(x,a[i]);
	
	printf("%lld\n",x*(n-1)-sum);
}

int main(){
	int t;
	scanf("%d",&t);
	for(;t>0;t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%lld",&a[i]);
		solve();
	}
}