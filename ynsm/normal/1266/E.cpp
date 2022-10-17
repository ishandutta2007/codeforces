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

int n, m, a[N], b[N];
ll ans;
map<int, int> mt[N];
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		ans += a[i];
	}
	int q;
	scanf("%d", &q);
	while(q--){
		int v, u, d;
		scanf("%d%d%d", &v, &u, &d);
		if(mt[v][u] != 0){
			ans -= max(0, a[mt[v][u]] - b[mt[v][u]]);
			b[mt[v][u]]--;
			ans += max(0, a[mt[v][u]] - b[mt[v][u]]);
		}
		mt[v][u] = d;
		if(mt[v][u] != 0){
			ans -= max(0, a[mt[v][u]] - b[mt[v][u]]);
			b[mt[v][u]]++;
			ans += max(0, a[mt[v][u]] - b[mt[v][u]]);
		}
		printf("%lld\n", max(1ll, ans));
	}
	return 0;
}