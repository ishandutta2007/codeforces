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
const int MN = 1e6 + 44;
int l[MN], r[MN];
void reset(int n) {
	for (int i = 0; i <= n + 1; ++i)
		l[i] = r[i] = i;
}
void rem(int x) {
	l[x] = x - 1;
	r[x] = x + 1;
}
int L(int x) {
	if (l[x] == x)
		return x;
	else
		return l[x] = L(l[x]);
}
int R(int x) {
	if (r[x] == x)
		return x;
	else
		return r[x] = R(r[x]);
}
LL cou(VPII & x) {
	int n = x.size();
	reset(n);
	LL ans = 0;
	for (auto c : x) {
		rem(c.s);
		debug("rem %d in %d\n", c.f, c.s);
		int ldist = c.s - L(c.s), rdist = R(c.s) - c.s;
		debug("ldist = %d, rdist = %d\n", ldist, rdist);
		ans += c.f * (LL)ldist * rdist;
	}
	return ans;
}
int main() {
	int n;
	scanf("%d", &n);
	VPII order;
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		order.emplace_back(x, i);
	}
	sort(order.begin(), order.end());
	LL ans = cou(order);
	reverse(order.begin(), order.end());
	ans -= cou(order);
	printf("%lld\n", ans);
}