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
#define M 19
#else
#define debug(...)
#define M 19
#define cerr if(0) cerr
#endif
#define cc(x) x.f, x.s
#define r(a,x) for (int a = 0; x < M; ++a)
#define ex(v, c) for (int x = 0; x < v; ++x) can2 = can2 * 10 + c
int low[19], high[19];
const int L = 19;
bool check(int can[10]) {
	for (int i = 0; i < L; ++i) {
		if (low[i] == high[i]) {
			debug("equal %d on %d\n", low[i], i);
			if (can[low[i]] == 0) {
				debug("ran out\n");
				return false;
			}
			can[low[i]]--;
		}
		else {
			debug("differs %d %d\n", low[i], high[i]);
			for (int x = low[i] + 1; x < high[i]; ++x) {
				
				if (can[x])
					return true;
			}
			int can2[10];
			for (int j = 0; j < 10; ++j)
				can2[j] = can[j];
			if (can[low[i]]) {
				can[low[i]]--;
				for (int j = i + 1; j <= L; ++j) {
					if (j == L) {
						debug("over\n", j);
						return true;
					}
					for (int x = 9; x > low[j]; --x)
						if (can[x])
							return true;
					if (can[low[j]])
						can[low[j]]--;
					else
						break;
				}
			}
			if (can2[high[i]]) {
				debug("high can work\n");
				can2[high[i]]--;
				for (int j = i + 1; j <= L; ++j) {
					if (j == L)
						return true;
					for (int x = 0; x < high[j]; ++x)
						if (can2[x])
							return true;
					if (can2[high[j]])
						can2[high[j]]--;
					else
						break;
				}
			}
			return false;
		}
	}
	return true;
}
int main() {
	LL l, r;
	scanf("%lld%lld", &l, &r);
	if (l == r && false) {
		printf("1\n");
		return 0;
	}
	for (int i = L - 1; i >= 0; --i) {
		low[i] = l % 10;
		l /= 10;
	}
	for (int i = 18; i >= 0; --i) {
		high[i] = r % 10;
		r /= 10;
	}
	int ans = 0;
	r(a, a)
	r(b, a + b)
	r(c, a + b + c)
	r(d, a + b + c + d)
	r(e, a + b + c + d + e)
	r(f, a + b + c + d + e + f)
	r(g, a + b + c + d + e + f + g)
	r(h, a + b + c + d + e + f + g + h)
	r(i, a + b + c + d + e + f + g + h + i) {
		if (a + b + c + d + e + f + g + h + i == 0)
			continue;
		int can[] = {L - (a + b + c + d + e + f + g + h + i), a, b, c, d, e, f, g, h, i};
#ifdef DEB
		LL can2 = 0;
		ex(a, 1);
		ex(b, 2);
		ex(c, 3);
		ex(d, 4);
		ex(e, 5);
		ex(f, 6);
		ex(g, 7);
		ex(h, 8);
		ex(i, 9);
#endif
			debug("try %lld\n", can2);
		if (check(can)) {
			debug("%lld is goood!!!!!!!!!!!!!!!\n", can2);
			ans++;
		}
	}
	printf("%d\n", ans);
}