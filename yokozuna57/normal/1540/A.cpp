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
ll d[100010];

void solve(){
	sort(d,d+n);
	ll ret=0;
	for(int i=0;i<n;i++){
		ret+=(n-1-2*i)*d[i];
	}
	ret+=d[n-1];
	printf("%lld\n",ret);
}

int main(){
	int T;
	scanf("%d",&T);
	for(;T>0;T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%lld",&d[i]);
		solve();
	}
}