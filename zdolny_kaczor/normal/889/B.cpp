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
#define NONE (-1)
#define next sntahe
const int A = 26, a = 'a';
char next[A];
int cou[A];
bool acc[A];
bool is[A];
const int MN = 1e5 + 44;
char x[MN];
void err() {
	printf("NO\n");
	exit(0);
}
int main() {
	REP(i, A)
		next[i] = NONE;
	int n;
	scanf("%d", &n);
	REP(i, n) {
		scanf("%s", x);
		REP(i, A)
			cou[i] = 0;
		for (int i = 0; x[i]; ++i) {
			is[x[i] - 'a'] = true;
			if (cou[x[i] - 'a']) {
				debug("more than one\n");
				err();
			}
			cou[x[i] - 'a']++;
		}
		for (int i = 0; x[i + 1]; ++i) {
			char f = x[i] - 'a', s = x[i + 1] - 'a';
			if (next[f] != NONE && next[f] != s) {
				debug("many after\n");
				err();
			}
			next[f] = s;
		}
	}
	REP(i, A)
		FOR(j, i + 1, A - 1)
			if (next[i] == next[j] && next[i] != NONE) {
				debug("many before %d %d\n", i, j);
				err();
			}
	REP(i, A) {
		if (next[i] != NONE)
			acc[next[i]] = true;
	}
	vector <int> ans;
	REP(i, A) {
		debug("in %d\n", i);
		if (!acc[i] && is[i]) {
			int wh = i;
			while (wh != NONE) {
				debug("go %d(%c)\n", wh, a + wh);
				ans.PB(wh);
				wh = next[wh];
			}
		}
	}
	int cou = 0;
	REP(i, A)
		if (is[i]) {
			cou++;
		}
	if (siz(ans) != cou) {
		debug("cycle\n");
		err();
	}
	for (int x : ans)
		putchar(a + x);
	printf("\n");
	return 0;
}