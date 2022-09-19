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
long long a[4];
long long sum = 0;
void add(int x) {
	x &= 3;
	a[x]++;
	a[(x + 1) & 3]++;
	sum += 2;
	printf("+%d\n", x + 1);
}
void div(int x) {
	x &= 3;
	assert(a[x] % 2 == 0 && a[(x + 1) & 3] % 2 == 0);
	sum -= a[x] / 2;
	sum -= a[(x + 1) & 3] / 2;
	a[x] /= 2;
	a[(x + 1) & 3] /= 2;
	printf("/%d\n", x + 1);
}
int main() {
	for (int i = 0; i < 4; ++i) {
		scanf("%lld", a + i);
		sum += a[i];
	}
	while (sum > 4) {
		for (int i = 0; i < 4; ++i)
			debug("%lld ", a[i]);
		debug("\n");
		bool done = false;
		long long M = 0, wh = -1;
		for (int i = 0; !done && i < 4; ++i) {
			if (a[i] % 2 == 0 && a[(i + 1) & 3] % 2 == 0) {
				long long v = a[i] + a[(i + 1) & 3];
				if (v > M) {
					wh = i;
					M = v;
				}
			}
		}
		if (wh != -1) {
			div(wh);
			done = true;
		}
		for (int i = 0; !done && i < 4; ++i) {
			if (a[i] % 2 && a[(i + 1) & 3] % 2 && a[i] > 1 && a[(i + 1) & 3] > 1) {
				add(i);
				done = true;
			}
		}
		for (int i = 0; !done && i < 4; ++i) {
			if (a[i] % 2 == 0 && a[(i + 1) & 3] > 2) {
				add(i - 1);
				add(i);
				done = true;
			}
		}
		for (int i = 0; !done && i < 4; ++i) {
			if (a[i] == 2) {
				add(i - 1);
				add(i);
				done = true;
			}
		}
		for (int i = 0; !done && i < 4; ++i)
			if (a[i] > 1) {
				add(i);
				done = true;
			}
	}
}