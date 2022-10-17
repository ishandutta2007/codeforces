#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
const ll MOD = 1000000007;

#define fr first
#define sc second

ll n,m;
vector<int> G[3002];
ll b[3002],w[3002];

ll siz[3002];
P dp[3002][3002];
ll dfs(ll v,ll p){
	siz[v] = 1;
	dp[v][0] = P(0,w[v]-b[v]);
	for(int i = 0 ; i < G[v].size() ; i ++){
		if(G[v][i] == p)continue;
		int ch = dfs(G[v][i],v);
		for(int j = siz[v] ; j < siz[v]+ch ; j ++){
			dp[v][j] = P(0,0);
		}
		siz[v] += ch;
		for(int t = min( siz[v]-1 , m-1 ) ; t >= max((ll)0,m+siz[v]-n-1) ; t --){
			dp[v][t].sc += dp[G[v][i]][0].sc;
			for(int j = max((ll)1,t+ch-siz[v]+1) ; j < min(t+1,ch) ; j ++){
				P q = dp[v][t-j];
				q.fr += dp[G[v][i]][j].fr;
				q.sc += dp[G[v][i]][j].sc;
				dp[v][t] = max( dp[v][t] , q );
			}
			for(int j = max((ll)0,t+ch-siz[v]) ; j < min(t,ch) ; j ++){
				P q = dp[v][t-j-1];
				q.fr += dp[G[v][i]][j].fr;
				if(dp[G[v][i]][j].sc > 0)q.fr ++;
				dp[v][t] = max( dp[v][t] , q );
			}
		}
		/*for(int j = 0 ; j < ch ; j ++){
			dp[v][siz[v]] = P(0,0);
			for(int k = min(siz[v]-1,siz[v]-j) ; k >= 0 ; k --){
				if(k+j <= siz[v]){
					P q = dp[v][k];
					q.fr += dp[G[v][i]][j].fr;
					q.sc += dp[G[v][i]][j].sc;
					dp[v][k+j] = max( dp[v][k+j] , q );
				}
				if(k+j+1 <= siz[v]){
					P q = dp[v][k];
					q.fr += dp[G[v][i]][j].fr;
					if(dp[G[v][i]][j].sc > 0)q.fr ++;
					dp[v][k+j+1] = max ( dp[v][k+j+1] , q );
				}
			}
			siz[v] ++;
		}*/
	}
	/*puts("===================");
	cout << v << endl;
	for(int i = 0 ; i < siz[v] ; i ++){
		cout << dp[v][i].fr << " " << dp[v][i].sc << endl;
	}*/
	return siz[v];
}

int main(){
	int t;
	scanf("%d",&t);
	for(;t>0;t--){
		scanf("%lld%lld",&n,&m);
		for(int i = 1 ; i <= n ; i ++){
			scanf("%lld",&b[i]);
		}
		for(int i = 1 ; i <= n ; i ++){
			scanf("%lld",&w[i]);
		}
		for(int i = 0 ; i < n-1 ; i ++){
			ll x,y;
			scanf("%lld%lld",&x,&y);
			G[x].push_back(y);
			G[y].push_back(x);
		}
		dfs(1,0);
		
		ll ret = dp[1][m-1].fr;
		if(dp[1][m-1].sc > 0)ret ++;
		printf("%lld\n",ret);
		
		for(int i = 1 ; i <= n ; i ++){
			G[i].clear();
		}
	}
}