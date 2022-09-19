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
void err() {
	printf("NO\n");
	exit(0);
}
map <int, int> c;
int read(int x) {
	if (c.count(x))
		return c[x];
	else
		return 0;
}
int main() {
	int n;
	scanf("%d", &n);
	int m = 1e9 + 44, M = 0;
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		mini(m, x);
		maxi(M, x);
		c[x]++;
	}
	for (auto & x : c) {
		debug("in %d\n", x);
		int i = x.first;
		if (read(i) > read(i + 1))
			err();
		if (c[i]) {
			n -= 2 * c[i];
			c[i + 1] -= c[i];
		}
		else {
			if (n)
				err();
		}
	}
	printf("YES\n");
}