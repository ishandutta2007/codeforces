#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;

#define Seg_Max_N (1<<18) 

using Value = pair<long long int, long long int>;
const Value ini = (make_pair(1e18, 0));
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
		return make_pair(min(l.first, r.first), max(l.second, r.second));
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
	vector<long long int>sasum(N);
	{
		vector<long long int>as(N);
		vector<long long int>sas(N - 1);
		vector<long long int>sums(N + 1);
		for (int i = 0; i < N; ++i) {
			cin >> as[i];
			sums[i + 1] = sums[i] + as[i];
		}
		for (int i = 0; i < N - 1; ++i) {
			sas[i] = abs(as[i + 1] - as[i]);
		}
		for (int i = 0; i < N - 1; ++i) {
			sasum[i + 1] = sasum[i] + (i % 2 ? sas[i] : -sas[i]);
		}
	}
	segtree tree(N);
	for (int i = 0; i < N; ++i) {
		tree.update(i, make_pair(sasum[i], sasum[i]));
	}
	long long int ans = 0;
	for (int i = 0; i < N; ++i) {
		auto p(tree.query(i + 1, N));
		long long int aans = 0;
		if (i % 2) {
			aans = p.second - sasum[i];
		}
		else {
			aans = (sasum[i] - p.first);
		}
		ans = max(ans, aans);
	}
	cout << ans << endl;

	return 0;
}