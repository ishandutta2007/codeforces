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
#define cc(x) x.f, x.s
const int MN = 2e5 + 44;
char a[MN], b[MN];
int per[MN];
int n;
bool good(int sta) {
	debug("try %d\n", sta);
	int pos = 0;
	REP(i, n) {
		if (per[i] >= sta) {
			debug("try %c with pos = %d\n", a[i], pos);
			if (a[i] == b[pos]) {
				debug("good\n");
				pos++;
			}
		}
	}
	debug("reached %d (%d)\n", pos, (int)b[pos]);
	return b[pos] == 0;
}
int main() {
	scanf("%s%s", a, b);
	n = strlen(a);
	REP(i, n) {
		int x;
		scanf("%d", &x);
		per[x - 1] = i;
	}
	debug("done\n");
	int low = 0, high = n, ans = 0;
	while (low <= high) {
		debug("%d - %d\n", low, high);
		int med = (low + high) / 2;
		if (good(med)) {
			ans = med;
			low = med + 1;
		}
		else
			high = med - 1;
	}
	printf("%d\n", ans);
}