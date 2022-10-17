#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, m;
vector< int > g[N];
int main()
{                         
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int v, u;
		cin >> v >> u;
		v--, u--;
		if(v < u)      
			g[v].pb(u - v);
		else
			g[v].pb(u - v + n);
	}
	for(int i = 0; i < n; i++)
		sort(g[i].begin(), g[i].end());
	

	for(int i = 0; i < n; i++){
		ll ans = 0;

		for(int j = 0; j < n; j++)
			if(!g[(j + i) % n].empty())
				ans = max(ans, j + 1ll * n * ((ll)g[(j + i) % n].size() - 1) + g[(j + i) % n][0]); 
			
		cout << ans << " ";
	}
	return 0;
}