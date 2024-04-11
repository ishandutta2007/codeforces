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
#define EB emplace_back
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
const bool debug = 
#ifdef DEB
true;
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
false;
#define debug(...)
#define cerr if(0) cout
#endif
#define cc(x) x.f, x.s
#define here() debug("LINE: %d\n", __LINE__)
const int MN = 1e5 + 44;
void err() {
	printf("No\n");
	exit(0);
}
bool is[MN];
bool isnot[MN];
VI words[MN];
VI go[MN];
void dfs(int x, bool start = true) {
	if (is[x] && !start)
		return;
	is[x] = true;
	for (auto c : go[x])
		dfs(c, false);
}
int main() {
	int n, A;
	scanf("%d%d", &n, &A);
	REP(i, n) {
		int len;
		scanf("%d", &len);
		REP(k, len) {
			int x;
			scanf("%d", &x);
			words[i].PB(x);
		}
		words[i].PB(-1);
	}
	REP(i, n - 1) {
		REP(k, min(siz(words[i]), siz(words[i + 1]))) {
			if (words[i][k] != words[i + 1][k]) {
				if (words[i][k] < words[i + 1][k]) {
					if (words[i][k] != -1) {
						debug("%d -> %d\n", words[i + 1][k], words[i][k]);
						go[words[i + 1][k]].PB(words[i][k]);
					}
				}
				else {
					if (words[i + 1][k] == -1)
						err();
					debug("is %d, is not %d\n", words[i][k], words[i + 1][k]);
					is[words[i][k]] = true;
					isnot[words[i + 1][k]] = true;
				}
				break;
			}
		}
	}
	FOR(i, 1, A) {
		if (is[i])
			dfs(i);
	}
	FOR(i, 1, A)
		if (is[i] && isnot[i])
			err();
	VI ans;
	FOR(i, 1, A)
		if (is[i])
			ans.PB(i);
	printf("Yes\n%d\n", siz(ans));
	for (auto c : ans)
		printf("%d ", c);
	printf("\n");
}