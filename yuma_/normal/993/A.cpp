#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld =long double;
const ld eps = 1e-9;

template<typename T> struct Compress {
	map<T, int>mp;
	map<int, T>revmp;

	Compress(vector<T>vs) {
		setmp(vs);
	}

	Compress() :mp(), revmp() {

	}
	void setmp(vector<T>vs) {
		sort(vs.begin(), vs.end());
		vs.erase(unique(vs.begin(), vs.end()), vs.end());
		for (int i = 0; i < static_cast<int>(vs.size()); ++i) {
			mp[vs[i]] = i;
			revmp[i] = vs[i];
		}
	}

};

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
		return r;
	}

	void lazy_func(const int k, const int a, const int b) {
		if (dat[k].lazy == -1) {

		}
		else {
			dat[k].sum=dat[k].lazy;
		}
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


int main()
{
	vector<vector<int>>v(300,vector<int>(300));
	for (int i = 0; i < 2; ++i) {
		vector<pair<int,int>>ps;
		int minx = 1e8, maxx = -10000, miny = 1e8, maxy = -1e8;
		for (int j = 0; j < 4; ++j) {
			int a,b;cin>>a>>b;
			ps.push_back(make_pair(a,b));
			minx=min(a,minx);
			maxx=max(a,maxx);
			miny=min(b,miny);
			maxy=max(b,maxy);
		}
		int cx = (minx + maxx) / 2;
		int cy = (miny + maxy) / 2;
		for (int y = miny; y <= maxy; ++y) {
			int k=abs(maxy-cy)-(abs(y-cy));

			int l= find(ps.begin(), ps.end(), make_pair(minx, miny)) == ps.end()?cx-k:minx;
			int r= find(ps.begin(), ps.end(), make_pair(minx, miny)) == ps.end()?cx+k:maxx;
			for (int x =l; x <= r; ++x) {
				v[y+150][x+150]++;
			}
		}
		

	}
	bool ok=false;
	for (int i = 0; i < 300; ++i) {
		for (int j = 0; j < 300; ++j) {
			if(v[i][j]>=2)ok=true;
		}
	}
	if(ok)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	

	return 0;

}