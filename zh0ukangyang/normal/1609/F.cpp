#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
#define uint unsigned int 
using namespace std;
const int N = 1 << 20;
int n, stka[N], tpa, stkb[N], tpb, bt[N];
ll f[N], ns;
struct segt { 
	int a[N], b[N];
	inline void ad (int p, int w) {
		int cw = w * p;
		for (int x = p; x <= n; x += x & -x) a[x] += w, b[x] += cw;
	}
	void add (int l, int r, int w) {
		ad (r + 1, -w), ad (l, w);
	}
	inline int Pre (int p) {
		int ret = 0;
		for (int x = p; x; x -= x & -x) ret += (p + 1) * a[x] - b[x];
		return ret;
	}
	int query (int l, int r) {
		return Pre (r) - Pre (l - 1);
	}
	void clear () {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
	}
} a, b;
int ret;
int main() { 
	ios :: sync_with_stdio (false);
	cin.tie (0); cout.tie (0);
	cin >> n ;
	L(i, 1, n) cin >> f[i], bt[i] = __builtin_popcountll(f[i]);
	L(o, 0, 60) {
		tpa = tpb = 0, ret = 0;
		a.clear ();
		b.clear ();
		L(i, 1, n) {
			while (tpa > 0 && f[stka[tpa]] <= f[i]) {
				if(bt[stka[tpa]] == o) {
					ret -= b.query (stka[tpa - 1] + 1, stka[tpa]);
					a.add (stka[tpa - 1] + 1, stka[tpa], -1); 
				}
				-- tpa;
			}
			while (tpb > 0 && f[stkb[tpb]] >= f[i]) {
				if(bt[stkb[tpb]] == o) {
					ret -= a.query (stkb[tpb - 1] + 1, stkb[tpb]);
					b.add (stkb[tpb - 1] + 1, stkb[tpb], -1); 
				}
				-- tpb;
			}
			stka[++tpa] = i;
			stkb[++tpb] = i;
			if(bt[i] == o) {
				a.add (stka[tpa - 1] + 1, stka[tpa], 1);
				ret += b.query (stka[tpa - 1] + 1, stka[tpa]);
				b.add (stkb[tpb - 1] + 1, stkb[tpb], 1);
				ret += a.query (stkb[tpb - 1] + 1, stkb[tpb]);
			}
			ns += ret;
		}
	}
	cout << ns << '\n';
	return 0;
}