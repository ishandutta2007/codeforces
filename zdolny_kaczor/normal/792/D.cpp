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
LL root;
LL left(LL x) {
	if (x & 1)
		return x;
	return x - (x & -x) / 2;
}
LL right(LL x) {
	if (x & 1)
		return x;
	return x + (x & -x) / 2;
}
LL up(LL x) {
	if (x == root)
		return x;
	LL step = x & -x;
	if (left(x + step) == x || right(x + step) == x)
		return x + step;
	else
		return x - step;
}
const int MN = 1e5 + 44;
char in[MN];
int main() {
	LL n;
	int q;
	scanf("%lld%d", &n, &q);
	root = (n + 1) / 2;
	while (q--) {
		LL start;
		scanf("%lld%s", &start, in);
		for (int i = 0; in[i]; ++i)
			if (in[i] == 'U')
				start = up(start);
			else if (in[i] == 'L')
				start = left(start);
			else
				start = right(start);
		printf("%lld\n", start);
	}
}