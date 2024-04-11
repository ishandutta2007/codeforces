#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define f first
#define s second
#define VI vector<int>
#define LL long long
#define MP make_pair
#define LD long double
#define PB push_back
#define PLL pair <LL, LL>
#define ALL(V) V.begin(),V.end()
#define abs(x) max((x),-(x))
#define PDD pair<LD,LD> 
#define VPII vector< PII > 
#define siz(V) ((int)V.size())
#define FOR(x, b, e)  for(int x=b;x<=(e);x++)
#define FORD(x, b, e) for(int x=b;x>=(e);x--)
#define REP(x, n)     for(int x=0;x<(n);x++)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#ifdef DEB
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#define cerr if(0) cerr
#endif
#define set unordered_set
const int inf = 1e9 + 44;
vector <int> parse(int x) {
	int last = x + 1;
	vector <int> ans;
	for (int i = 1; i <= x; ++i) {
		int c = x / i;
		if (c == last) {
			for (int k = c - 1; k >= 1; --k) {
				ans.push_back(k);
			}
			break;
		}
		ans.push_back(c);
		last = c;
		if (x % i == 0)
			ans.PB(--last);
	}
	reverse(ALL(ans));
	ans.PB(inf);
	return ans;
}
const int MN = 507;
int a[MN];
vector <int> p[MN];
int wh[MN];
int needed(int all, int lower) {
	return (all + lower) / (lower + 1);
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		p[i] = parse(a[i]);
		debug("p[%d] = ", a[i]);
		for (auto c : p[i])
			debug("%d ", c);
		debug("\n");
	}
	LL ans = 1e18 + 44;
	for (auto c : p[0]) {
		if (c == 0 || c == inf)
			continue;
		bool good = true;
		for (int i = 1; i < n; ++i) {
			while (p[i][wh[i]] < c)
				wh[i]++;
			if (p[i][wh[i]] != c) {
				good = false;
				break;
			}
		}
		if (good) {
			debug("%d is good\n", c);
			LL C = 0;
			for (int i = 0; i < n; ++i)
				C += needed(a[i], c);
			mini(ans, C);
		}
	}
	printf("%lld\n", ans);
}