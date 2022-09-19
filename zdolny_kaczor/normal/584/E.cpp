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
int n;
const int MN = 2e3 + 44;
int a[MN], bin[MN];
int p[MN];
int l[MN];
int r[MN];
void init(int n) {
	REP(i, n + 2)
		l[i] = r[i] = i;
}
void rem(int x) {
	l[x] = x - 1;
	r[x] = x + 1;
}
int left(int x) {
	if (l[x] == x)
		return x;
	else
		return l[x] = left(l[x]);
}
int right(int x) {
	if (r[x] == x)
		return x;
	else
		return r[x] = right(r[x]);
}
VPII ans;
void ch(int a, int b) {
	if (a > b)
		swap(a, b);
	debug("ch %d %d\n", a, b);
	getwait();
	ans.PB(MP(a, b));
	swap(p[a], p[b]);
	if (p[a] == a)
		rem(a);
	if (p[b] == b)
		rem(b);
}
void push(int x) {
	debug("push %d\n", x);
	FOR(i, 1, n)
		debug("%d ", p[i]);
	debug("\n");
	getwait();
	while (p[x] > x) {
		debug("p[%d] = %d\n", x, p[x]);
		int next;
		while (true) {
			next = right(x + 1);
			debug("next = %d\n", next);
			if (p[next] < next)
				break;
			push(next);
		}
		assert(next != x);
		ch(x, next);
	}
}
int main() {
	scanf("%d", &n);
	init(n);
	FOR(i, 1, n)
		scanf("%d", a + i);
	FOR(i, 1, n) {
		int x;
		scanf("%d", &x);
		bin[x] = i;
	}
	FOR(i, 1, n) {
		p[i] = i[a][bin];
		if (p[i] == i)
			rem(i);
	}
	FOR(i, 1, n)
		debug("%d ", p[i]);
	debug("\n");
	int cost = 0;
	FOR(i, 1, n)
		cost += abs(i - p[i]);
	printf("%d\n", cost / 2);
	for (int i = 1; i <= n; ++i)
		push(i);
	printf("%d\n", siz(ans));
	for (auto x : ans) {
		printf("%d %d\n", x.f, x.s);
	}
}