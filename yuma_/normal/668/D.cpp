#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

struct Node {
	int sum;//. .
	int lazy;	//
	Node() {
		sum = lazy = 0;
	}
};


struct lazy_segtree {
	int N;
	vector<Node>dat;
	lazy_segtree(int n) :N(1) {
		while (N < n) N *= 2;
		dat.resize(2 * N);
	}

	// inline!()
	inline void lazy_evaluate_node(int k, int a, int b) {
		dat[k].sum += dat[k].lazy * (b - a + 1);
		if (k < N) { // 2*k() < 2*N () . .
			dat[2 * k].lazy += dat[k].lazy;	//.
			dat[2 * k + 1].lazy += dat[k].lazy;
		}
		dat[k].lazy = 0;
	}

	inline void update_node(int k) { // k. if.
		dat[k].sum = dat[2 * k].sum + dat[2 * k + 1].sum;
	}

	// update(l,r,v) := [l,r]. 1-indexed.
	void update(int l, int r, int v, int k = 1, int a = 1, int b = -1) {
		if (b == -1)b = N;
		if (l < 0 || r<0)assert(false);
		lazy_evaluate_node(k, a, b); 	// .

		if (b < l || r < a) //[a,b][l,r]
			return;
		if (l <= a && b <= r) { // [l,r][a,b]
			dat[k].lazy += v;
			lazy_evaluate_node(k, a, b); //.
			return;
		}

		int m = (a + b) / 2;
		update(l, r, v, 2 * k, a, m);
		update(l, r, v, 2 * k + 1, m + 1, b);
		update_node(k);
	}

	// get(l,r) := [l,r]. 1-indexed.
	int get(int l, int r, int k = 1, int a = 1, int b = -1) {
		if (b == -1)b = N;

		if (l < 0 || r<0)assert(false);
		lazy_evaluate_node(k, a, b); // .

		if (b < l || r < a) //[a,b][l,r]
			return 0;

		if (l <= a && b <= r) { // [l,r][a,b]
			return dat[k].sum;
		}

		int m = (a + b) / 2;
		int vl = get(l, r, 2 * k, a, m);
		int vr = get(l, r, 2 * k + 1, m + 1, b);
		update_node(k);
		return vl + vr;
	}
};

//#define Seg_Max_N (1<<18) 
//
//using Value = pair<long long int, long long int>;
//const Value ini = (make_pair(1e18, 0));
//struct segtree {
//	int N;
//	vector<Value>dat;
//
//	segtree() {}
//	segtree(int n) :dat(2 * Seg_Max_N) {
//		N = 1;
//		while (N < n) N *= 2;
//		for (int i = 0; i < 2 * N - 1; i++) {
//			dat[i] = ini;
//		}
//	}
//	Value connect(const Value&l, const Value&r) {
//		return make_pair(min(l.first, r.first), min(l.second, r.second));
//	}
//	// update k th element
//	void update(int k, Value a) {
//		k += N - 1;
//		dat[k] = a;
//
//		while (k > 0) {
//			k = (k - 1) / 2;
//			const Value al(dat[k * 2 + 1]);
//			const Value ar(dat[k * 2 + 2]);
//			dat[k] = connect(al, ar);
//		}
//	}
//	// min [a, b)
//	Value  query(int a, int b) { return query(a, b, 0, 0, N); }
//	Value  query(int a, int b, int k, int l, int r) {
//		if (r <= a or b <= l) return ini;
//		if (a <= l and r <= b) return dat[k];
//		const int m = (l + r) / 2;
//		const Value al(query(a, b, k * 2 + 1, l, m));
//		const Value ar(query(a, b, k * 2 + 2, m, r));
//		return connect(al, ar);
//	}
//};


struct Compress {
	map<int, int>mp;
	map<int, int>revmp;

	Compress(vector<int>vs) {
		setmp(vs);
	}
	Compress(const set<int>&vs) {
		setmp(vs);
	}
	Compress():mp(),revmp() {

	}
	void setmp(vector<int>vs) {
		sort(vs.begin(), vs.end());
		vs.erase(unique(vs.begin(), vs.end()), vs.end());
		for (int i = 0; i < vs.size(); ++i) {
			mp[vs[i]] = i;
			revmp[i] = vs[i];
		}
	}
	void setmp(const set<int>&vs) {
		int num = 0;
		for (auto v : vs) {
			mp[v] = num;
			revmp[num] = v;
			num++;
		}
	}
};
struct query {
	int a;
	int t;
	int x;
};

int main() {
	int N; cin >> N;
	map<int,Compress>comps;
	map<int, vector<int>>mps;
	vector<int>xs;
	vector<query>qs;
	for (int i = 0; i < N; ++i) {
		int a, t, x; cin >> a >> t >> x;
		xs.push_back(x);
		mps[x].push_back(t);
		qs.push_back(query{ a,t,x });
	}
	for (auto mp : mps) {
		comps[mp.first];
		comps[mp.first].setmp(mp.second);
	}
	Compress xcomp(xs);
	for (int i = 0; i < N; ++i) {
		qs[i].t = comps[qs[i].x].mp[qs[i].t];
		qs[i].x = xcomp.mp[qs[i].x];
	}
	vector<lazy_segtree>segs;
	for (auto mp : mps) {
		segs.push_back(lazy_segtree(mp.second.size()));
	}
	for (int i = 0; i < N; ++i) {
		query q(qs[i]);
		const int type = q.a;
		const int time = q.t;
		const int num = q.x;
		if (type==1) {
			segs[num].update(time + 1, segs[num].N, 1);
		}
		else if (type == 2) {

			segs[num].update(time + 1, segs[num].N, -1);
		}
		else {
			int ans = segs[num].get(time + 1, time + 1);
			cout << ans << endl;
		}
	}
	
	return 0;
}