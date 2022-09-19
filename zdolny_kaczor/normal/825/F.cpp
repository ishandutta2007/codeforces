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
const int MN = 8e3 + 44;
const int LOG = 13;
map <pair <int, int>, int> B;
int bind(int a, int b) {
	static int c = 144;
	auto it = B.find(make_pair(a, b));
	if (it == B.end()) {
		c++;
		B[make_pair(a, b)] = c;
		return c;
	}
	else
		return it -> second;
}
int mlog[MN];
int dict[MN][LOG];
bool same(int p1, int p2, int len) {
	int r = mlog[len];
	return dict[p1][r] == dict[p2][r] && dict[p1 + len - (1 << r)][r] == dict[p2 + len - (1 << r)][r];
}
char in[MN];
int diglen[MN];
int minsize[MN][MN];
int ans[MN];
int main() {
	for (int i = 0; i < MN; ++i) {
		for (int k = 0; k < LOG; ++k)
			if ((1 << k) <= i)
				mlog[i] = k;
	}
	for (int i = 1; i < MN; ++i) {
		int p = 1;
		while (p <= i)
			diglen[i]++, p *= 10;
	}
	scanf("%s", in);
	int n = strlen(in);
	for (int i = 0; i < n; ++i)
		dict[i][0] = in[i];
	for (int l = 1; l < LOG; ++l) {
		for (int i = 0; i + (1 << l) < MN; ++i)
			dict[i][l] = bind(dict[i][l - 1], dict[i + (1 << (l - 1))][l - 1]);
	}
	for (int i = 0; i < MN; ++i)
		for (int k = i + 1; k < MN; ++k)
			minsize[i][k] = 1e7 + 77;
	for (int i = 0; i < n; ++i)
		for (int l = 1; l <= n; ++l) {
			for (int k = 0; i + (k + 1) * l <= n; ++k) {
				debug("iterate i = %d l = %d k = %d\n", i, l, k);
				if (!same(i, i + k * l, l))
					break;
				debug("survived\n");
				mini(minsize[i][i + l * (k + 1)], diglen[k + 1] + l);
			}
		}
	ans[n] = 0;
	for (int i = n - 1; i >= 0; --i) {
		ans[i] = 1e7 + 44;
		for (int k = i + 1; k <= n; ++k)
			ans[i] = min(ans[i], minsize[i][k] + ans[k]);
	}
	printf("%d\n", ans[0]);
}