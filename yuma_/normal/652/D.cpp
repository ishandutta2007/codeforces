#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps = 1e-9;

//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt" > "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\b.txt"

struct Compress {
	map<int, int>mp;
	map<int, int>revmp;

	Compress(vector<int>vs) {
		setmp(vs);
	}
	Compress(const set<int>&vs) {
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
	void setmp(const set<int>&vs) {
		int num = 0;
		for (auto v : vs) {
			mp[v] = num;
			revmp[num] = v;
			num++;
		}
	}
};


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

struct aa {
	int num;
	int place;
	bool activate;
};

struct seg {
	int id;
	int first;
	int second;
};

int main() {
	int N; cin >> N;
	vector<seg>ps;
	set<int>aset;
	for (int i = 0; i < N; ++i) {
		int l, r; scanf("%d %d", &l, &r);
		aset.emplace(l);
		aset.emplace(r);
		ps.push_back(seg{ i,l,r });
	}
	Compress comp(aset);
	for (auto& p : ps) {
		p.first = comp.mp[p.first];
		p.second = comp.mp[p.second];
	}
	sort(ps.begin(), ps.end(), [](const seg&l, const seg&r) {return l.first < r.first; });
	vector<aa>orders;
	for (int i = 0; i < ps.size();++i){
		auto p = ps[i];
		orders.push_back(aa{ i,p.first,true });
		orders.push_back(aa{ i,p.second,false });
	}
	sort(orders.begin(), orders.end(), [](const aa&l, const aa&r) {
		return l.place < r.place;
	});
	lazy_segtree l_seg(ps.size());
	vector<int>anss(ps.size());
	for (auto o : orders) {
		if (o.activate) {
			anss[o.num] -= l_seg.get(o.num + 1, o.num + 1);
		}
		else {
			anss[o.num] += l_seg.get(o.num + 1, o.num + 1);
			l_seg.update(1, o.num, 1);
		}
	}
	vector<int>realanss(ps.size());

	for (int i = 0; i < ps.size(); ++i) {
		realanss[ps[i].id] = anss[i];
	}
	for (int i = 0; i < ps.size(); ++i) {
		printf("%d\n", realanss[i]);
	}
	return 0;
}