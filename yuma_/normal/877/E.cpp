#include "bits/stdc++.h"
using namespace std;

struct Point{
	int l;
	int r;
	int pa;
	vector<int>chs;
};

typedef int Value1;
typedef bool Value2;
const Value1 Zero1(0);
const Value2 Zero2(false);

struct Node {
	Value1 sum;//. .
	Value2 lazy;	//
	Node() :sum(Zero1) {
		lazy = Zero2;
	}
};
struct lazy_segtree {
	int N;
	vector<Node>dat;
	lazy_segtree(int n) :N(1) {
		while (N < n) N *= 2;
		dat.resize(2 * N);
	}

	Value2 lazy_connect(const Value2 l, const Value2 r) {
		return l^r;
	}

	void lazy_func(const int k, const int a, const int b) {
		if (dat[k].lazy)dat[k].sum =(b-a)-dat[k].sum;
		else {
		}
	}

	Value1 connect(const Value1 l, const Value1 r) {
		return l + r;

	}

	// inline!()
	inline void lazy_evaluate_node(int k, int a, int b) {
		lazy_func(k, a, b);
		if (k < N) { // 2*k() < 2*N () . .
			dat[2 * k].lazy = lazy_connect(dat[2 * k].lazy, dat[k].lazy);	//.
			dat[2 * k + 1].lazy = lazy_connect(dat[2 * k + 1].lazy, dat[k].lazy);
		}
		dat[k].lazy = Zero2;
	}

	inline void update_node(int k) { // k. if.
		dat[k].sum = connect(dat[2 * k].sum, dat[2 * k + 1].sum);

	}

	// update(l,r,v) := [l,r). 0-indexed.
	void update(int l, int r, Value2 v, int k = 1, int a = 0, int b = -1) {
		if (b == -1)b = N;
		if (l < 0 || r < 0)assert(false);
		lazy_evaluate_node(k, a, b); 	// .

		if (b <= l || r <= a) //[a,b)[l,r)
			return;
		if (l <= a && b <= r) { // [l,r)[a,b)
			dat[k].lazy = lazy_connect(dat[k].lazy, v);
			lazy_evaluate_node(k, a, b); //.
			return;
		}

		int m = (a + b) / 2;
		update(l, r, v, 2 * k, a, m);
		update(l, r, v, 2 * k + 1, m, b);
		update_node(k);
	}
	//get(l,r) := [l,r). 0-indexed.
	Value1 get(int l, int r, int k = 1, int a = 0, int b = -1) {
		if (b == -1)b = N;

		if (l < 0 || r<0)assert(false);
		lazy_evaluate_node(k, a, b); // .

		if (b <= l || r <= a) //[a,b)[l,r)
			return Zero1;

		if (l <= a && b <= r) { // [l,r)[a,b)
			return dat[k].sum;
		}

		int m = (a + b) / 2;
		Value1 vl = get(l, r, 2 * k, a, m);
		Value1 vr = get(l, r, 2 * k + 1, m, b);
		update_node(k);
		return connect(vl, vr);
	}
};

void dfs(vector<Point>&ps,int now, int&aa) {
	ps[now].l = aa;
	aa++;
	for (auto ch : ps[now].chs) {
		dfs(ps, ch, aa);
	}
	ps[now].r = aa;

}

int main() {
	int N; cin >> N;
	vector<Point>ps(N);
	for (int i = 0; i < N-1; ++i) {
		int a; cin >> a; a--;
		ps[i + 1].pa = a;
		ps[a].chs.push_back(i + 1);
	}
	int aa = 0;
	dfs(ps, 0, aa);
	lazy_segtree seg(N);
	for (int i = 0; i < N; ++i) {
		int a; cin >> a;
		int l = ps[i].l;
		int r = ps[i].r;
		seg.update(l, l+1, bool(a));
	}
	int Q; cin >> Q;
	while (Q--) {
		string st; cin >> st;
		int n; cin >> n; n--;
		if (st == "get") {
			int ans = seg.get(ps[n].l, ps[n].r);
			cout << ans << endl;
		}
		else {
			seg.update(ps[n].l, ps[n].r, true);
		}
	}
	return 0;
}