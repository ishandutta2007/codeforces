#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)3e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
 
int n, m, a[N], b[N], p[N];
vector< pair<int, pii > > v;
ll ans;
int pp(int v){
	return (p[v] == v ? v : p[v] = pp(p[v]));
}
bool unite(int v, int u){
	v = pp(v);
	u = pp(u);
	if(v == u)
		return 0;
	p[v] = u;
	return 1;
}
int main()
{
	for(int i = 0; i < N; i++)
		p[i] = i;
	scanf("%d%d", &m, &n); 
	for(int i = 0; i < m; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	for(int i = 0; i < m; i++){
		int k;
		scanf("%d", &k);
		while(k--){
			int x;
			scanf("%d", &x);
			x--;
			v.pb({a[i] + b[x], {x, n + i}});
			ans += a[i] + b[x];
		}
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for(auto it : v)
		if(unite(it.s.f, it.s.s))
			ans -= it.f;
	printf("%lld", ans);
}