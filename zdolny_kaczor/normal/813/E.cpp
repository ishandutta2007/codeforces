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
const int ROOT = 100;
const int MN = 1e5 + 44;
VI occ[MN];
int a[MN];
int pre[MN / ROOT + 1][MN / ROOT + 1];
int lower(const VI & in, int b) {
	int ans = 0;
	int l = 0, h = in.size() - 1;
	while (l <= h) {
		int m = (l + h) / 2;
		if (in[m] < b) {
			ans = m + 1;
			l = m + 1;
		}
		else
			h = m - 1;
	}
	return ans;
}
int in_range(int val, int l, int r) {
	return lower(occ[val], r + 1) - lower(occ[val], l);
}
int cou[MN];
int main() {
	int n, b;
	scanf("%d%d", &n, &b);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		occ[a[i]].PB(i);
	}
	for (int i = 0; i * ROOT < n; ++i) {
		debug("iter from %d\n", i);
		if (i)
			for (int k = 0; k < MN; ++k)
				cou[k] = 0;
		int ans = 0;
		for (int k = i * ROOT; k < n; ++k) {
			debug("add %d\n", a[k]);
			if (cou[a[k]] != b) {
				debug("really add\n");
				cou[a[k]]++;
				ans++;
			}
			if ((k + 1) % ROOT == 0) {
				debug("store ans in %d %d\n", i, k / ROOT);
				pre[i][k / ROOT] = ans;
			}
		}
	}
	int q;
	scanf("%d", &q);
	int last = 0;
	while (q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		l += last;
		r += last;
		l %= n;
		r %= n;
		if (l > r)
			swap(l, r);
		int ans = 0;
		debug("decrypt %d %d\n", l, r);
		if (r - l > 2 * ROOT) {
			int ll = (l + ROOT - 1) / ROOT * ROOT;
			int rr = (r + 1) / ROOT * ROOT - 1;
			debug("goto [%d, %d]\n", ll, rr);
			ans = ll < rr ? pre[ll / ROOT][rr / ROOT] : 0;
			while (l < ll) {
				if (in_range(a[ll - 1], ll, rr) < b)
					ans++;
				ll--;
			}
			while (r > rr) {
				if (in_range(a[rr + 1], ll, rr) < b)
					ans++;
				rr++;
			}
		}
		else {
			map <int, int> cou;
			for (int i = l; i <= r; ++i) {
				if (cou[a[i]] < b)
					ans++;
				cou[a[i]]++;
			}
		}
		debug("return:");
		printf("%d\n", ans);
		last = ans;
	}
}