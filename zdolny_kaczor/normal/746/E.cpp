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
#define debug2(...) cerr << __VA_ARGS__
#else
#define debug(...)
#define debug2(...)
#endif
const int MN = 2e5 + 44;
int a[MN];
map <int, vector <int> > ecount;
set <int> used;
vector <int> toadd;
int ans[MN];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		ecount[x].push_back(i);
	}
	for (auto &x : ecount) {
		debug("clear %d\n", x.first);
		while (x.second.size() > 1) {
			debug("remove %d\n", x.second.back());
			x.second.pop_back();
		}
	}
	int odd = 0, even = 0;
	for (auto &x : ecount) {
		if (x.first % 2) odd++;
		else even++;
	}
	for (auto &x : ecount) {
		if (even > n / 2 && x.first % 2 == 0) {
			x.second.clear();
			even--;
		}
		if (odd > n / 2 && x.first % 2 == 1) {
			x.second.clear();
			odd--;
		}
	}
	for (auto x : ecount)
		if (x.second.size() > 0)
			used.insert(x.first);
	for (int i = 2; i <= m && even < n / 2; i += 2)
		if (used.count(i) == 0) {
			toadd.push_back(i);
			debug("add %d as even\n", i);
			even++;
		}
	for (int i = 1; i <= m && odd < n / 2; i += 2)
		if (used.count(i) == 0) {
			toadd.push_back(i);
			debug("add %d as odd\n", i);
			odd++;
		}
	if (odd < n / 2 || even < n / 2) {
		printf("-1\n");
		return 0;
	}
	int ch = toadd.size();
	for (auto & x : ecount)
		for (auto k : x.second)
			ans[k] = x.first;
	for (int i = 0; i < n; ++i)
		if (ans[i] == 0) {
			ans[i] = toadd.back();
			toadd.pop_back();
		}
	printf("%d\n", ch);
	for (int i = 0; i < n; ++i)
		printf("%d ", ans[i]);
	printf("\n");
}