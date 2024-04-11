#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> P1;
#define mp1(a,b,c) P1(a,P(b,c))
#define fr first
#define sc second

int main(){
	static ll n;
	static ll a[200010];
	scanf("%lld",&n);
	for(int i = 1 ; i <= n ; i ++){
		scanf("%lld",&a[i]);
	}
	
	static ll cnt[200010] = {};
	static ll ret = 0;
	for(int i = 1 ; i <= n ; i ++){
		ret += a[i];
	}
	
	map<P,ll> M;
	ll q;
	scanf("%lld",&q);
	for(;q>0;q--){
		ll s,t,u;
		scanf("%lld%lld%lld",&s,&t,&u);
		map<P,ll>::iterator itr = M.find(P(s,t));
		if(itr != M.end()){
			cnt[itr->sc] --;
			if(cnt[itr->sc] < a[itr->sc])ret ++;
			M.erase(itr);
		}
		if(u != 0){
			M[P(s,t)] = u;
			cnt[u] ++;
			if(cnt[u] <= a[u])ret --;
		}
		printf("%lld\n",ret);
	}
}