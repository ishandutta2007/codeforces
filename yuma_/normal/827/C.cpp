#include "bits/stdc++.h"
using namespace std;

#define Seg_Max_N (1<<18) 

using Value = int;
const Value ini = 0;
struct segtree {
	int N;
	vector<Value>dat;

	segtree() {}
	segtree(int n) {
		N = 1;
		while (N < n) N *= 2;
		dat.resize(2 * N);
		for (int i = 0; i < 2 * N - 1; i++) {
			dat[i] = ini;
		}
	}
	Value connect(const Value& l, const Value&r) {
		
		return l+r;
	}
	// update k th element
	void update(int k, const Value& a) {
		k += N - 1;
		dat[k] = connect(dat[k], a);

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
	string st; cin >> st;
	vector<vector<vector<segtree>>>segs(10);
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < i + 1; ++j) {
			segs[i].push_back(vector<segtree>(4,segtree(st.size())));
		}
	}
	
	map<char, int>chmp;
	chmp['A'] = 0;
	chmp['T'] = 1;
	chmp['G'] = 2;
	chmp['C'] = 3;
	for (int i = 0; i < st.size(); ++i) {
		int num = chmp[st[i]];
		vector<int>v(4);
		v[num]++;
		for (int j = 0; j < 10; ++j) {
			segs[j][i % (j + 1)][num].update(i, 1);
		}
	}
	int Q; cin >> Q;
	while(Q--){
		int a; cin >> a;
		if (a == 1) {
			int k;
			char ch; cin >> k >> ch;
			k--;
			vector<int>v(4);
			v[chmp[ch]]++;
			v[chmp[st[k]]]--;
			for (int j = 0; j < 10; ++j) {
				segs[j][k % (j + 1)][chmp[ch]].update(k, 1);
				segs[j][k % (j + 1)][chmp[st[k]]].update(k, -1);
			}
			st[k] = ch;
		}
		else {
			int l, r; cin >> l >> r;
			l--;
			string st; cin >> st;
			int ans = 0;
			for (int i = 0; i < st.size(); ++i) {
				int num = chmp[st[i]];
				int t = (l + i) % (st.size());
				ans += segs[st.size() - 1][t][num].query(l, r);
			}
			cout << ans << endl;

		}
	}
	return 0;
}