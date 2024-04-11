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
#define getwait getchar
#else
#define debug(...)
#define debug2(...)
#define getwait()
#endif
#define next nexstaoe
const int MN = 2e6 + 44;
int count(int n) {
	return (n * (n - 1)) / 2 + (n % 2 == 0 ? (max(0, n / 2 - 1)) : 0);
}
int opt[MN];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%*d%d", opt + i);
	}
	sort(opt, opt + m);
	int v;
	for (v = 0; count(v + 1) < n; ++v)
		;
	debug("v = %d\n", v);
	long long res = 0;
	for (int i = 0; i < min(v, m); ++i)
		res += opt[m - i - 1];
	printf("%lld\n", res);
}