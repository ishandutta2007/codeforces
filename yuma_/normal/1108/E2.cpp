#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
typedef int Value1;
typedef int Value2;
const Value1 Zero1(1e9);
const Value2 Zero2(0);

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
		for (int i = N - 1; i >= 1; --i) {
			update_node(i);
		}
	}

	Value2 lazy_connect(const Value2 l, const Value2 r) {
		return l+r;
	}

	void lazy_func(const int k, const int a, const int b) {
		dat[k].sum+=dat[k].lazy;
	}

	Value1 connect(const Value1 l, const Value1 r) {
		return min(l,r);

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

struct li {
	int l;
	int r;
	int id;
};
int main()
{
	int N,M;cin>>N>>M;
	lazy_segtree seg(N);
	for (int i = 0; i < N; ++i) {
		int a;scanf("%d",&a);
		seg.update(i,i+1,int(-1e9)+a);
	}

	vector<vector<li>>adds(N+1);
	vector<vector<li>>remos(N+1);

	set<int>usings;
	for (int i = 0; i < M; ++i) {
		int l,r;cin>>l>>r;
		l--;
		seg.update(l,r,-1);
		adds[l].push_back(li{ l,r,i });
		remos[r].push_back(li{ l,r,i });
		usings.emplace(i);
	}
	pair<int,int>answer=make_pair(-1,-1);

	for (int i = 0; i < N; ++i) {
		for (auto li : adds[i]) {
			seg.update(li.l,li.r,1);
		}
		for (auto li : remos[i]) {
			seg.update(li.l, li.r, -1);
		}
		int now_sa=seg.get(i,i+1)-seg.get(0,N);
		answer=max(answer,make_pair(now_sa,i));
	}

	int max_place=answer.second;
	printf("%d",answer.first);
	cout<<endl;
	vector<int>ans_li_ids;
	for (auto add : adds) {
		for (auto ad : add) {
			if (ad.r <= max_place || max_place < ad.l) {
				ans_li_ids.emplace_back(ad.id);
			}
		}
	}
	printf("%zd",ans_li_ids.size());
	cout << endl;

	for (auto li_id : ans_li_ids) {
		printf("%d ",li_id+1);
	}
	cout << endl;

	return 0;
}