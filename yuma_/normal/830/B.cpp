#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;


#define Seg_Max_N (1<<18) 

using Value = long long int;
const Value ZERO = 0;
struct segtree {
	int N;
	vector<Value>dat;

	segtree() {}
	segtree(int n) :dat(2 * Seg_Max_N) {
		N = 1;
		while (N < n) N *= 2;
		for (int i = 0; i < 2 * N - 1; i++) {
			dat[i] = ZERO;
		}
		query(0, N);
	}
	Value connect(const Value&l, const Value&r) {
		return l + r;
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
		if (r <= a or b <= l) return ZERO;
		if (a <= l and r <= b) return dat[k];
		const int m = (l + r) / 2;
		const Value al(query(a, b, k * 2 + 1, l, m));
		const Value ar(query(a, b, k * 2 + 2, m, r));
		return connect(al, ar);
	}
};

int main() {
	long long int ans = 0;
	map<int, vector<int>>mp;
	int N; cin >> N;
	segtree seg(N);
	for (int i = 0; i < N; ++i) {
		int a; cin >> a;
		mp[a].push_back(i);
		seg.update(i, 1);
	}
	int now = 0;
	for (auto&& m : mp) {
		auto it = lower_bound(m.second.begin(), m.second.end(), now);
		int r;
		if (it == m.second.begin()) {
			r = *prev(m.second.end());
		}
		else if (it == m.second.end()) {
			r = *prev(it);
		}
		else {
			r = *prev(it);
		}
		if(r<now)ans += seg.query(now, N) + seg.query(0, r + 1);
		else ans += seg.query(now, r + 1);
		now = r + 1;
		for (auto a : m.second) {
			seg.update(a, 0);
		}

	}
	cout << ans << endl;
	return 0;
}