#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)5e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
 
vector< int > g[N];
int n, m, a[N], p[N];
bool was[N], wass[N];
bool cmp(int i, int j){
	return a[i] < a[j];
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++){
		int v, u;
		scanf("%d%d", &v, &u);
		g[v].pb(u);
		g[u].pb(v);
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		p[i] = i;
	}
	sort(p + 1, p + 1 + n, cmp);
	for(int i = 1; i <= n; i++){
		int v = p[i];
		was[v] = 1;
		for(auto to : g[v])
			if(was[to])
				wass[a[to]] = 1;
		bool ok = !wass[a[v]];
		for(int q = 1; q < a[v]; q++)
			ok &= wass[q];
		if(!ok){
			printf("-1");
			return 0;
		}			
		for(auto to : g[v])
			if(was[to])
				wass[a[to]] = 0;
	}
	for(int i = 1; i <= n; i++)
		printf("%d ", p[i]);
	
}