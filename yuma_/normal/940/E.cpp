#include "bits/stdc++.h"
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
		return make_pair(min(l.first, r.first), (l.second + r.second));
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
	int N,C;cin>>N>>C;
	vector<long long int>v;
	segtree seg(N);
	for (int i = 0; i < N; ++i) {
		int a;cin>>a;
		v.push_back(a);
		seg.update(i,make_pair(a,a));
	}
	vector<long long int>dp(N+1);
	dp[0]=0;
	for (int i = 0; i < N; ++i) {
		if (i < C-1) {
			dp[i+1]=dp[i]+v[i];
		}
		else {
			auto p(seg.query(i-C+1,i+1));
			dp[i+1]=min(dp[i]+v[i],dp[i-C+1]+p.second-p.first);
		}
	}
	cout<<dp[N]<<endl;
	return 0;
}