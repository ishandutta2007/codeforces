#include "bits/stdc++.h"
using namespace std;
using ld=long double;
#pragma warning(disable:4996)

typedef pair<int,ld> Value1;
typedef pair<ld,ld> Value2;
const Value1 Zero1(make_pair(0,0));
const Value2 Zero2(make_pair(1,0));

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
		return make_pair(l.first*r.first,l.second*r.first+r.second);
	}

	void lazy_func(const int k, const int a, const int b) {
		{
			dat[k].sum.second =dat[k].sum.second*dat[k].lazy.first+dat[k].lazy.second;
		}
	}

	Value1 connect(const Value1 l, const Value1 r) {
		if (l.first == 0 && r.first == 0) {
			return make_pair(0,0);
		}
		return make_pair(l.first+r.first,((l.first*l.second)+(r.first*r.second))/(r.first+l.first));

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

int main() { 
	int N,Q;cin>>N>>Q;
	lazy_segtree seg(N);
	vector<int>as;
	for (int i = 0; i < N; ++i) {
		seg.dat[seg.N+i].sum=make_pair(1,0);
	}
	for (int i = 0; i < N; ++i) {
		int a; cin >> a;
		seg.update(i, i + 1,make_pair(1,a));
	}
	cout<<setprecision(10)<<fixed;
	while (Q--) {
		int a;cin>>a;
		if (a == 1) {
			int l1,r1,l2,r2;cin>>l1>>r1>>l2>>r2;
			l1--;l2--;
			auto lp=seg.get(l1,r1);
			auto rp=seg.get(l2,r2);
			auto lsum=lp.first*lp.second;
			auto rsum=rp.first*rp.second;
			seg.update(l1,r1,make_pair((r1-l1-1)/ld(r1-l1),rp.second/ld(r1-l1)));
			seg.update(l2,r2, make_pair((r2-l2-1)/ld(r2-l2),lp.second/ld(r2-l2)));
		}
		else {
			int l,r;cin>>l>>r;l--;
			auto p=seg.get(l,r);
			cout<<p.first*p.second<<endl;
		}
	}
	return 0;
}