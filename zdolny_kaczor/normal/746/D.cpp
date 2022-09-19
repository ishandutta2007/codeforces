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
int n, k, a, b;
void err() {
	printf("NO\n");
	exit(0);
}
const int MN = 1e5 + 44;
char ans[MN];
int main() {
	scanf("%d%d%d%d", &n, &k, &a, &b);
	int last = 0;
	int type = 0;
	ans[n] = 0;
	for (int i = 0; i < n; ++i) {
		int drink;
		if (last < k) {
			drink = (a > b) ? 0 : 1;
		}
		else {
			drink = 1 - type;
		}
		ans[i] = drink ? 'B' : 'G';
		if (drink == type) {
			last++;
		}
		else {
			last = 1;
			type = drink;
		}
		if (type) b--;
		else a--;
		if (a < 0 || b < 0) {
			err();
		}
	}
	printf("%s\n", ans);
}