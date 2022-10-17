#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

template<class T> T T_INF(){ return 1000000000000000000; }
template<> int T_INF<int>(){ return 1000000000; }

ll n,k;
ll a[200010];
void solve(){
	ll ret=n*k-n*(n+1)/2-k*(k-1)/2;
	vector<ll> v;
	for(int i=0;i<n;i++)v.push_back(a[i]+i+1);
	sort(v.begin(),v.end());
	for(int i=0;i<n-k;i++)ret+=v[i];
	printf("%lld\n",ret);
}

int main(){
	int T;
	scanf("%d",&T);
	for(;T>0;T--){
		scanf("%lld%lld",&n,&k);
		for(int i=0;i<n;i++)scanf("%lld",&a[i]);
		solve();
	}
}