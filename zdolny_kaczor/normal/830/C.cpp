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
struct fun {
	int l, a, b;
	fun (int l_, int a_, int b_) : l(l_), a(a_), b(b_) {}
	void show() {
		debug("%lld x + %lld on range(%lld, inf]\n", a, b, l);
	}
};//f(x) = {0 if x <= l else a * x + b
bool operator< (fun a, fun b) {
	return a.l < b.l;
}
void parse(int a, vector <fun> & ans) {
	vector <int> A;
	int root = 0;
	while (root * root <= a)
		root++;
	for (int i = 1; i <= a; ++i) {
		A.PB(a / i);
		if (a / i == a / (i + 1)) {
			for (int k = a / i - 1; k > 0; --k)
				A.PB(k);
			break;
		}
	}
	for (auto x : A) {
		ans.emplace_back(a / x, x, -a);
		ans.emplace_back(a / (x + 1), -x, a);
	}
	ans.emplace_back(a, 0, a);
}
const LL llinf = 1e18;
int main() {
	int n;
	long long k;
	scanf("%d%lld", &n, &k);
	vector <fun> F;
	for (int i = 0; i < n; ++i) {
		int ai;
		scanf("%d", &ai);
		ai--;
		parse(ai, F);
// 		for (auto f : F)
// 			f.show();
// 		for (int m = 1; m <= 2 * a[i]; ++m) {
// 			long long c = 0;
// 			for (auto f : F)
// 				if (f.l < m)
// 					c += m * f.a + f.b;
// 			assert(c == a[i] % m);
// 		}
	}
	sort(F.begin(), F.end());
	long long a = 0, b = 0;
	long long ans = 0;
	for (size_t i = 0; i < F.size(); ++i) {
		auto f = F[i];
		long long curr = f.l;
		long long next = (i == F.size() - 1 ? llinf : F[i + 1].l);
		a += f.a;
		b += f.b;
		if (curr == next)
			continue;
		LL rhs = b + n + k;
		LL lhs = n - a;
		if (lhs > 0) {
			LL bound = rhs / lhs;
			if (bound > curr)
				ans = max(ans, bound);
		}
		else if (lhs == 0) {
			if (rhs >= 0)
				ans = max(ans, next);
		}
		else {
			if (lhs * next <= rhs)
				ans = max(ans, next);
		}
	}
	printf("%lld\n", ans);
}