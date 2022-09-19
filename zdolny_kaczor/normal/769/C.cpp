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
#define map sanoteh
void err() {
	printf("IMPOSSIBLE\n");
	exit(0);
}
const int MN = 1e3 + 44;
char map[MN][MN];
int dist[MN][MN];
int n, m, k;
bool poss(PII x) {
	return x.f >= 0 && x.f < n && x.s >= 0 && x.s < m && map[x.f][x.s] != '*';
}
int & d(PII x) {
	return dist[x.f][x.s];
}
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
char dirs[] = "DLRU";
PII add(PII a, int d) {
	return MP(a.f + dx[d], a.s + dy[d]);
}
int len = 0;
void run(PII x) {
	if (len == k)
		return;
	debug("run %d %d\n", x.f, x.s);
	for (int i = 0; i < 4; ++i) {
		PII go = add(x, i);
		if (poss(go) && d(go) <= k - len) {
			printf("%c", dirs[i]);
			len++;
			run(go);
			return;
		}
	}
	assert(len == 0);
	err();
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	if (k % 2)
		err();
	for (int i = 0; i < n; ++i)
		scanf("%s", map[i]);
	PII start;
	for (int i = 0; i < n; ++i)
		for (int k = 0; k < m; ++k)
			if (map[i][k] == 'X')
				start = MP(i, k);
	queue <PII> x;
	const int inf = 1e7 + 44;
	for (int i = 0; i < n; ++i)
		for (int k = 0; k < m; ++k)
			dist[i][k] = inf;
	d(start) = 0;
	x.push(start);
	while (!x.empty()) {
		PII curr = x.front();
		x.pop();
		for (int i = 0; i < 4; ++i) {
			PII go = add(curr, i);
			if (poss(go) && d(go) > d(curr) + 1) {
				d(go) = d(curr) + 1;
				x.push(go);
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int k = 0; k < m; ++k)
			debug("%3d ", dist[i][k]);
		debug("\n");
	}
	run(start);
}