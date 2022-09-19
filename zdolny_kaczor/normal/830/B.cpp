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
const int MN = 1 << 17;
int tree[MN * 2];
void edit(int pos, int val) {
	tree[pos + MN] = val;
	pos += MN;
	pos /= 2;
	while (pos > 0) {
		tree[pos] = tree[pos * 2 + 1] + tree[pos * 2];
		pos /= 2;
	}
}
int read(int l, int r, int wh = 1, int lb = 0, int rb = MN) {
	if (l > rb || r < lb)
		return 0;
	if (l <= lb && r >= rb)
		return tree[wh];
	return read(l, r, wh * 2, lb, (lb + rb) / 2) + read(l, r, wh * 2 + 1, (lb + rb) / 2 + 1, rb);
}
//[a, b)
int readc(int a, int b) {
	if (a == b)
		return 0;
	if (a < b)
		return read(a, b - 1);
	return read(a, MN - 1) + (b == 0 ? 0 : read(0, b - 1));
}
VI a[MN];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		edit(i, 1);
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		a[x].PB(i);
	}
	long long ans = 0;
	int pos = 0;
	for (int i = 0; i < MN; ++i) {
		vector <int> aft, bef;
		for (auto x : a[i])
			if (x >= pos)
				aft.PB(x);
			else
				bef.PB(x);
		for (auto x : bef)
			aft.push_back(x);
		for (auto x : aft) {
			ans += readc(pos, x) + 1;
			debug("goto %d reaching ans = %lld\n", x, ans);
			edit(x, 0);
			pos = x;
		}
	}
	printf("%lld\n", ans);
}