#include "bits/stdc++.h"
using namespace std;

#define Seg_Max_N (1<<18) 

using Value = long long int;
const Value ini = 0;
struct segtree {
	int N;
	vector<Value>dat;

	segtree() {}
	segtree(int n) {
		N = 1;
		while (N < n) N *= 2;
		dat.resize(2*N);
		for (int i = 0; i < 2 * N - 1; i++) {
			dat[i] = ini;
		}
	}
	Value connect(const Value&l, const Value&r) {
		return max(l, r);
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

struct ring {
	int inr;
	int outr;
	long long int h;
};
struct Compress {
	map<int, int>mp;
	map<int, int>revmp;

	Compress(vector<int>vs) {
		setmp(vs);
	}
	Compress() :mp(), revmp() {

	}
	void setmp(vector<int>vs) {
		sort(vs.begin(), vs.end());
		vs.erase(unique(vs.begin(), vs.end()), vs.end());
		for (int i = 0; i < static_cast<int>(vs.size()); ++i) {
			mp[vs[i]] = i;
			revmp[i] = vs[i];
		}
	}
};



int main() {
	vector<ring>rings;
	{
		int N; cin >> N;
		map<int, vector<pair<int, int>>>mp;
		vector<int>v;
		for (int i = 0; i < N; ++i) {
			int a, b, h; cin >> a >> b >> h;
			mp[b].push_back(make_pair(a, h));
			v.push_back(a);
			v.push_back(b);
		}
		Compress comp(v);
		for (auto&m : mp) {
			sort(m.second.begin(), m.second.end());
			long long int sumh = 0;
			for (auto a : m.second)sumh += a.second;
			rings.push_back(ring{ m.second[0].first,m.first,sumh });
		}
		for (auto& ring : rings) {
			ring.inr = comp.mp[ring.inr];
			ring.outr = comp.mp[ring.outr];
		}
	}
	const int SIZE =3e5;
	segtree seg(SIZE);
	for (auto &&ring : rings) {
		long long int t = seg.query(ring.inr + 1, SIZE);
		seg.update(ring.outr, t + ring.h);
	}
	long long int ans = seg.query(0, SIZE);
	cout << ans << endl;
	
 	return 0;
}