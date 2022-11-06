#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
struct query {
	int id;
	int l;
	int r;

};

#define Seg_Max_N (1<<19) 

using Value = pair<int, int>;
const Value ini = make_pair(1e9,-1);
struct segtree {
	int N;
	vector<Value>dat;

	segtree() {}
	segtree(int n) :dat(2 * Seg_Max_N) {
		N = 1;
		while (N < n) N *= 2;
		for (int i = 0; i < 2 * N - 1; i++) {
			dat[i] = ini;
		}
	}
	Value connect(const Value&l, const Value&r) {
		return min(l,r);
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

int main() {
	int N;cin>>N;
	vector<int>v(N);
	for(int i=0;i<N;++i)scanf("%d",&v[i]);
	int Q;cin>>Q;
	map<int,vector<query>>q_mp;
	for (int i = 0; i < Q; ++i) {
		int l,r;scanf("%d %d",&l,&r);
		l--;
		q_mp[r].push_back(query{ i,l,r });
	}
	vector<int>anss(Q,-1);
	segtree seg(N);

	map<int,int>prev_mp;
	for (int r = 0; r <= N; ++r) {
		for (auto q : q_mp[r]) {
			auto p=seg.query(q.l,q.r);
			if(p.first>=q.l)anss[q.id]=0;
			else anss[q.id]=p.second;
		}

		if (r != N) {
			int num=v[r];
			if (prev_mp.find(num) == prev_mp.end()) {
				seg.update(r, make_pair(-1, num));

			}
			else {
				seg.update(r,make_pair(prev_mp[num],num));
				seg.update(prev_mp[num],ini);

			}
			prev_mp[num] = r;

		}
	}
	
	for (auto an : anss) {
		printf("%d\n",an);
	}

	return 0;
}