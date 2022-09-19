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
#define next ascroesacr
int A[3][3], B[3][3];
PLL operator+ (PLL a, PLL b) {
	return MP(a.f + b.f, a.s + b.s);
}
PII next(PII x) {
	return MP(A[x.f][x.s], B[x.f][x.s]);
}
PLL sc(PII a) {
	debug("sc %d %d\n", cc(a));
	if (a.f == (a.s + 1) % 3)
		return MP(1, 0);
	else if (a.f == a.s)
		return MP(0, 0);
	else
		return MP(0, 1);
}
PLL operator* (PLL a, LL b) {
	return MP(a.f * b, a.s * b);
}
int main() {
	LL k;
	int a, b;
	scanf("%lld%d%d", &k, &a, &b);
	a--; b--;
	REP(i, 3)
		REP(j, 3) {
			scanf("%d", &A[i][j]);
			A[i][j]--;
		}
	REP(i, 3)
		REP(j, 3) {
			scanf("%d", &B[i][j]);
			B[i][j]--;
		}
	int len = 0;
	PII state = MP(a, b);
	map <PII, int> turn;
	PLL score = MP(0, 0);
	while (turn.count(state) == 0 && len < k) {
		debug("%d %d\n", cc(state));
		score = score + sc(state);
		turn[state] = len++;
		state = next(state);
	}
	LL left = k - len;
	int cycle_len = len - turn[state];
	LL rep = left / cycle_len;
	int rem = left % cycle_len;
	debug("cycle_len = %d, rep = %lld rem = %d\n", cycle_len, rep, rem);
	for (int i = 0; i < cycle_len; ++i) {
		score = score + sc(state) * (rep + (i < rem ? 1 : 0));
		state = next(state);
	}
	printf("%lld %lld\n", cc(score));
}