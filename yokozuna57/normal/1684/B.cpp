#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

template<class T> T T_INF(){ return 1000000000000000000; }
template<> int T_INF<int>(){ return 1000000000; }

int main(){
	int T;
	scanf("%d",&T);
	for(;T>0;T--){
		ll a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		printf("%lld %lld %lld\n",1000000000*b+a,b,c);
	}
}