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
ll a[N];
vector< pair<pii, ll> > ans;
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++){
		int v, u, d;
		scanf("%d%d%d", &v, &u, &d);
		a[v] += d;
		a[u] -= d;
	}
	for(int i = 0, j = 0; i <= n; i++){
		while(a[i] > 0){
			while(a[j] >= 0)
				j++;			
			ll x = min(a[i], -a[j]);
			a[i] -= x;
			a[j] += x;
			ans.pb({{i, j}, x});
		}
	}
	printf("%d\n", ans.size());
	for(auto it : ans)
		printf("%d %d %lld\n", it.f.f, it.f.s, it.s);	
	return 0;
}