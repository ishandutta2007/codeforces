#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

template<class T> T T_INF(){ return 1000000000000000000; }
template<> int T_INF<int>(){ return 1000000000; }

int n;
ll a[400010];

void solve(){
	ll ret=0;
	for(int i=1;i<=n;i++){
		ret+=max(a[i]-max(a[i-1],a[i+1]),(ll)0);
		a[i]=min(a[i],max(a[i-1],a[i+1]));
	}
	for(int i=0;i<=n;i++){
		ret+=abs(a[i+1]-a[i]);
	}
	printf("%lld\n",ret);
}

int main(){
	int T;
	scanf("%d",&T);
	for(;T>0;T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		a[0]=a[n+1]=0;
		solve();
	}
}