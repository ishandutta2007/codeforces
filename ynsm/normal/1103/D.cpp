#include <bits/stdc++.h>                                                                                                                                                                                      //YaLoh

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e6 + 123, M = 12, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, m, pp[N], cnt[1 << M], gg[1 << M];
ll ans, k, g, a[N], b[N], c[M], val[1 << M], dp[M][1 << M], tmp[M][1 << M];
vector< ll > p, v[N]; 
map<int, int> mt;

bool cmp(int i, int j){
	return b[i] < b[j];
}
int main()
{            

	scanf("%d%lld", &n, &k);
	for(int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	for(int i = 0; i < n; i++)
		scanf("%lld", &b[i]);
	for(int i = 0; i < n; i++)
		pp[i] = i;
	sort(pp, pp + n, cmp);
	
	for(int i = 0; i < n; i++)
		g = __gcd(g, a[i]);
	for(int i = 2; 1ll * i * i <= g; i++)
		if(g % i == 0){
			while(g % i == 0)
				g /= i;
			p.pb(i);                      	
		}
	if(1 < g)
		p.pb(g);
	m = p.size();
	if(m == 0){
		printf("0");
		return 0;
	}	
	
	for(int i = 0; i <= m; i++)
		for(int j = 0; j < (1 << m); j++)
			tmp[i][j] = dp[i][j] = INF;
	tmp[0][0] = dp[0][0] = 0;                    
	ans = INF;
	for(int i = 1; i < (1 << m); i++)
		for(int j = 0; j < m; j++)
			if((i >> j) & 1)
				gg[i] = j;
	
	for(int q = 0; q < n; q++){
		int i = pp[q];
		ll cur = 1;
		for(int j = 0; j < m; j++){
			c[j] = 1;
			while(a[i] % p[j] == 0)
				a[i] /= p[j], c[j] *= p[j];
			cur *= c[j];
		}	
		if(mt[cur] > m)
			continue;
		mt[cur]++;
		val[0] = 1;
		for(int msk = 1; msk < (1 << m); msk++){
			val[msk] = val[msk ^ (1 << gg[msk])] * c[gg[msk]];
			if(val[msk] <= k && cnt[msk] <= m){
				v[i].pb(msk);
	            cnt[msk]++;
			}
		}                    
		
		for(int x = m - 1; x >= 0; x--)
			for(auto msk : v[i])
				for(int it = ((1 << m) - 1) ^ msk; it > 0; it = (it - 1) & (((1 << m) - 1) ^ msk))
					dp[x + 1][msk | it] = min(dp[x + 1][msk | it], dp[x][it] + b[i]);
		for(auto msk : v[i])
			dp[1][msk] = min(dp[1][msk], b[i]);
	}
	for(int x = 1; x <= m; x++)
		if(dp[x][(1 << m) - 1] != INF)
        	ans = min(ans, x * dp[x][(1 << m) - 1]);
	
	if(ans == INF)
		ans = -1;
	
	printf("%lld", ans);
	return 0;
}