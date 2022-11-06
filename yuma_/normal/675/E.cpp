#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt"

#define Seg_Max_N (1<<18) 
using Value = pair<long long int,long long int>;
Value dat[2 * Seg_Max_N];
struct segtree {
	int N;
	const Value ini = (make_pair(-1,-1));
	segtree() {}
	segtree(int n) {
		N = 1;
		while (N < n) N *= 2;
		for (int i = 0; i < 2 * N - 1; i++) {
			dat[i] = ini;
		}
	}
	// update k th element
	void update(int k, Value a) {
		k += N - 1; // leaf
		dat[k] = a;
		while (k > 0) {
			k = (k - 1) / 2;
			const Value al(dat[k * 2 + 1]);
			const Value ar(dat[k * 2 + 2]);
			dat[k] = max(al,ar);
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
		return max(al,ar);
	}
};

int main() {
	int N; cin >> N;
	vector<long long int>tics(N);
	for (int i = 0; i < N - 1; ++i) {
		int a; cin >> a; a--;
		tics[i] = a;
	}
	vector<long long int>diss(N);
	diss[N - 1] = 0;
	segtree seg(N);
	seg.update(N - 1, make_pair(0,N-1));
	for (int i = N - 2; i >= 0;--i) {
		long long int num = 0;
		num += tics[i] - i;

		auto p(seg.query(i, tics[i] + 1));
		const int keiyu = p.second;
		const int withkeiyu = N - tics[i] - 1;
		num += diss[p.second] +withkeiyu-(tics[i]-p.second);
		diss[i] = num;
		seg.update(i, make_pair(tics[i], i));
	}
	long long int ans = accumulate(diss.begin(), diss.end(), 0ll);
	cout << ans << endl;
	return 0;
}