#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
const ll MOD = 1000000007;

#define fr first
#define sc second

ll n;
vector<P> G[600010];

ll siz[600010];
ll ret_A,ret_B;
ll dfs(ll v,ll d,ll p){
	siz[v] = 1;
	for(int i = 0 ; i < G[v].size() ; i ++){
		if(G[v][i].fr == p)continue;
		siz[v] += dfs(G[v][i].fr,G[v][i].sc,v);
	}
	if(siz[v]%2 == 1)ret_A += d;
	ret_B += d*min(siz[v],n-siz[v]);
	return siz[v];
}

int main(){
	int t;
	scanf("%d",&t);
	for(;t>0;t--){
		ll k;
		scanf("%lld",&k);
		n = 2*k;
		for(int i = 0 ; i < 2*k-1 ; i ++){
			ll a,b,c;
			scanf("%lld%lld%lld",&a,&b,&c);
			G[a].push_back(P(b,c));
			G[b].push_back(P(a,c));
		}
		dfs(1,0,0);
		printf("%lld %lld\n",ret_A,ret_B);
		
		for(int i = 1 ; i <= n ; i ++){
			G[i].clear();
		}
		n = 0;
		ret_A = ret_B = 0;
	}
}