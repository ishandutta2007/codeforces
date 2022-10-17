#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define fr first
#define sc second
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)

int main(){
	int T;
	scanf("%d",&T);
	for(;T>0;T--){
		ll d,m;
		scanf("%lld%lld",&d,&m);
		ll ret=1;
		ll t=1;
		while(t<=d){
			ret*=min(2*t-1,d)-t+2;
			ret%=m;
			t*=2;
		}
		ret+=m-1;
		ret%=m;
		printf("%lld\n",ret);
	}
}