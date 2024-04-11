#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

#define Seg_Max_N (1<<18) 

using Value = pair<long long int, long long int>;
const Value ini = (make_pair(-1e10, 1e10));
struct segtree {
	int N;
	vector<Value>dat;

	segtree() {}
	segtree(int n) :dat(2 * Seg_Max_N) {
		N = 1;
		while (N < n) N *= 2;
		for (int i = 0; i < 2 * N - 1; i++) {
			dat[i] = ini;
		}
	}
	Value connect(const Value&l, const Value&r) {
		return make_pair(max(l.first, r.first), min(l.second, r.second));
	}
	// update k th element
	void update(int k, Value a) {
		k += N - 1;
		dat[k] = a;

		while (k > 0) {
			k = (k - 1) / 2;
			const Value al(dat[k * 2 + 1]);
			const Value ar(dat[k * 2 + 2]);
			dat[k] = connect(al, ar);
		}
	}
	// min [a, b)
	Value  query(int a, int b) { return query(a, b, 0, 0, N); }
	Value  query(int a, int b, int k, int l, int r) {
		if (r <= a or b <= l) return ini;
		if (a <= l and r <= b) return dat[k];
		const int m = (l + r) / 2;
		const Value al(query(a, b, k * 2 + 1, l, m));
		const Value ar(query(a, b, k * 2 + 2, m, r));
		return connect(al, ar);
	}
};

int main() {
	int N; cin >> N;
	vector<int>as(N), bs(N);
	for (int i = 0; i < N; ++i) {
		int a; scanf("%d",&a);
		as[i] = a;
	}
	for (int i = 0; i < N; ++i) {
		int b; scanf("%d", &b);
		bs[i] = b;
	}
	segtree seg(N);
	for (int i = 0; i < N; ++i) {
		seg.update(i, make_pair(as[i], bs[i]));
	}
	long long int ans = 0;
	for (int l = 0; l < N; ++l) {
		int okr, okl;
		{
			int minr = 0;
			int maxr = N+1;
			while (minr + 1 != maxr) {
				int midr = (minr + maxr) / 2;
				auto p = seg.query(l, midr);
				if (p.first < p.second) {
					minr = midr;
				}
				else {
					maxr = midr;
				}
			}
			okl = minr;
		}
		{
			int minr = 0;
			int maxr = N+1;
			while (minr + 1 != maxr) {
				int midr = (minr + maxr) / 2;
				auto p = seg.query(l, midr);
				if (p.first <= p.second) {
					minr = midr;
				}
				else {
					maxr = midr;
				}
			}
			okr = minr;
		}
		ans += okr - okl;
	}
	printf("%lld", ans);
	return 0;
}