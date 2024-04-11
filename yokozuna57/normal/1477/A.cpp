#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

ll gcd(ll x,ll y){
	if(y==0)return x;
	return gcd(y,x%y);
}

ll n,k;
ll a[200010];

void solve(){
	ll g=0;
	for(int i=1;i<n;i++){
		g=gcd(g,abs(a[i]-a[0]));
	}
	bool ok=false;
	for(int i=0;i<n;i++){
		ll x=abs(k-a[i]);
		if(x%(2*g)==0)ok=true;
	}
	if(ok)puts("YES");
	else puts("NO");
}

int main(){
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%lld%lld",&n,&k);
		for(int i=0;i<n;i++)scanf("%lld",&a[i]);
		solve();
	}
}