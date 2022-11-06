#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;

typedef int Value1;
typedef int Value2;
const Value1 Zero1(0);
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
	}

	Value2 lazy_connect(const Value2 l, const Value2 r) {
		return l+r;
	}

	void lazy_func(const int k, const int a, const int b) {
		dat[k].sum+=dat[k].lazy;
	}

	Value1 connect(const Value1 l, const Value1 r) {
		return max(l,r);

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
	int N,K;cin>>N>>K;
	vector<int>as(N);
	vector<int>nexts(N);
	vector<int>prevs(N);
	{
		for (int i = 0; i < N; ++i) {
			scanf("%d",&as[i]); as[i]--;
		}
		{
			vector<int>uses(N, N);
			for (int i = N - 1; i >= 0; --i) {
				nexts[i] = uses[as[i]];
				uses[as[i]] = i;
			}
		}
		{
			vector<int>uses(N, -1);
			for (int i = 0; i <N; ++i) {
				prevs[i] = uses[as[i]];
				uses[as[i]] = i;
			}
		}
	}
	//vector<lazy_segtree>segs(K+1,lazy_segtree(N+1));

	vector<vector<int>>dp(K + 1, vector<int>(N + 1));
	{
		vector<int>pluss(N+1,1);
		int num=0;
		for (int i = 1; i <= N; ++i) {
			num+=pluss[i-1];
			pluss[nexts[i-1]]--;
			//segs[0].update(i,i+1,num);
			dp[0][i]=num;
		}
	}

	for (int k = 0; k < K; ++k) {
		lazy_segtree seg(N+1);
		for (int i = 0; i <= N; ++i) {
			seg.update(i,i+1,dp[k][i]);
		}


		for (int x = 0; x < N; ++x) {
			int pre=prevs[x];
			seg.update(pre+1,x+1,1);
			dp[k+1][x+1]=seg.get(0,x+1);
		}


	}
	/*
	 1 3 3 1 4 4 4 
	0 1 2 2 2 3 3 3
	1 / / / / / / /    1
	2 2 / / / / / /    2
	2 2 3 / / / / /    3
	2 3 4 3 / / / /    4
	3 4 5 4 3 / / /    5
	3 4 5 4 3 4 / /    5*/

	int ans=dp[K-1][N];
	cout<<ans<<endl;
	return 0;
}