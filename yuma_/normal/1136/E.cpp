#include "bits/stdc++.h"

using namespace std;
#pragma warning(disable:4996)

struct Value1 {
	long long int max_num;
	long long int sum;
};
typedef pair<bool,long long  int>Value2;
const Value1 Zero1{ 0,0 };
const Value2 Zero2(make_pair(false, 0));

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
	lazy_segtree(int n,vector<long long int>v) :N(1) {
		while (N < n) N *= 2;
		dat.resize(2 * N);
		for (int i = N; i < N + v.size(); ++i) {
			dat[i].sum = Value1{ v[i - N],v[i - N] };
		}
		for (int i = N - 1; i >= 1; --i) {
			update_node(i);
		}
	}

	Value2 lazy_connect(const Value2 l, const Value2 r) {
		if(r.first)return r;
		else if(l.first)return l;
		else {
			return Zero2;
		}
	}

	void lazy_func(const int k, const int a, const int b) {
		if (dat[k].lazy.first)dat[k].sum = Value1{ dat[k].lazy.second, dat[k].lazy.second*(b - a) };
		else {
		}
	}

	Value1 connect(const Value1 l, const Value1 r) {
		return Value1{ max(l.max_num,r.max_num),l.sum + r.sum };

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
	int dfs(long long int ax, int k = 1, int a = 0, int b = -1) {
		if (b == -1)b = N;
		lazy_evaluate_node(k, a, b); // .

		if (a + 1 == b) {
			if(dat[k].sum.max_num>=ax)return a;
			else return N;
		}
		if (dat[k].sum.max_num >= ax) {

			int m = (a + b) / 2;
			
			int vl=dfs(ax,2 * k, a, m);
			int vr=N;
			if (vl == N) {
				 vr = dfs(ax, 2 * k + 1, m, b);

			}
			else {
				lazy_evaluate_node(2*k+1,m,b);
			}
			update_node(k);
			return min(vl,vr);
		}
		else {
			return N;
		}

	}
};


int main() {
	int N;cin>>N;
	vector<long long int>as(N);
	for(int i=0;i<N;++i)scanf("%lld",&as[i]);
	vector<long long int>sas(N-1);
	for(int i=0;i<N-1;++i)scanf("%lld",&sas[i]);

	vector<long long int>pluss(N);
	vector<long long int>offsets(N+1);
	offsets[0]=0;
	pluss[0]=as[0];
	offsets[1]=0;
	long long int sum=0;
	for (int i = 1; i < N; ++i) {
		sum+=sas[i-1];
		pluss[i]=pluss[i-1]+as[i]-as[i-1]-sas[i-1];
		offsets[i+1]=offsets[i]+sum;
	}
	lazy_segtree seg(N,pluss);
	int Q;scanf("%d",&Q);
	while (Q--) {
		char ch;
		scanf("%c",&ch);
		scanf("%c",&ch);
		int a,b;
		scanf("%d %d",&a,&b);
		if (ch == 's') {
			a--;
			long long int answer=offsets[b]-offsets[a];
			answer+=seg.get(a,b).sum;
			printf("%lld\n",answer);
		}
		else {
			a--;
			int l=a;
			long long int l_num=seg.get(l,l+1).sum;
			int r=seg.dfs(l_num+b);
			r=min(r,N);
			seg.update(l,r,make_pair(true,l_num+b));
		}
	}
	return 0;
	
}