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
const int MN = 3e5 + 44;
VI graf[MN];
#define hash h45h
LL val[MN];
LL hash[MN];
unordered_map <LL, set<LL> > graf2;
unordered_set <LL> seen;
void err() {
	printf("NO\n");
	exit(0);
}
map <LL, int> nr;
int cou = 1;
void dfs(LL x) {
	if (seen.count(x))
		return;
	seen.insert(x);
	nr[x] = cou;
	cou++;
	for (auto z : graf2[x])
		dfs(z);
}
int main() {
	val[0] = 13243;
	for (int i = 1; i < MN; ++i)
		if (i % 7 < 3)
			val[i] = (val[i - 1] * 7 + 3441343) % 1000000000000000007LL;
		else
			val[i] = (val[i - 1] * 13 + 14233024) % 1000000000000000009LL;
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].PB(b);
		graf[b].PB(a);
	}
	for (int i = 1; i <= n; ++i) {
		hash[i] = val[i];
		for (auto x : graf[i])
			hash[i] ^= val[x];
	}
	for (int i = 1; i <= n; ++i)
		debug("%d. %18lld\n", i, hash[i]);
	for (int i = 1; i <= n; ++i) {
		graf2[hash[i]];
		for (auto x : graf[i])
			if (hash[i] != hash[x])
				graf2[hash[i]].insert(hash[x]);
	}
	for (auto x : graf2) {
		debug("%18lld:", x.first);
		for (auto y : x.second)
			debug("%18lld ", y);
		debug("\n");
	}
	for (auto x : graf2) {
		if (x.second.size() > 2u)
			err();
		else if (x.second.size() <= 1u && !seen.count(x.first)) {
			dfs(x.first);
			cou++;
		}
	}
	if (seen.size() < graf2.size())
		err();
	printf("YES\n");
	for (int i = 1; i <= n; ++i) {
		printf("%d ", nr[hash[i]]);
	}
	printf("\n");
}