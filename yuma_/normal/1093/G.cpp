#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;


#define Seg_Max_N (1<<18) 

using Value = vector<int>;
const Value ini = vector<int>(32,-1e9);
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
		Value v(32);
		for(int i=0;i<32;++i)v[i]=max(l[i],r[i]);
		return v;
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
int N, Dim;
vector<int>ge() {
	vector<int>coor(5);
	for (int j = 0; j < Dim; ++j) {
		int a;
		scanf("%d", &a);
		coor[j] = (a);
	}
	vector<int>v(1 << 5);
	for (int j = 0; j < (1 << 5); ++j) {
		int sum = 0;
		for (int k = 0; k < 5; ++k) {
			int plus;
			if (j&(1 << k)) {
				plus = 1;
			}
			else {
				plus = -1;
			}
			sum += plus*coor[k];
		}
		v[j] = sum;
	}
	return v;
}
int main()
{
	cin>>N>>Dim;
	segtree seg(N);
	for (int i = 0; i < N; ++i) {
		vector<int>v=ge();
		seg.update(i,v);
	}
	int Q;cin>>Q;
	while (Q--) {
		int type;
		scanf("%d",&type);
		if (type == 1) {
			int x;scanf("%d",&x);
			vector<int>v=ge();x--;
			seg.update(x,v);
		}
		else {
			int l,r;scanf("%d %d",&l,&r);
			l--;
			auto vs=seg.query(l,r);
			int ans=0;
			for (int i = 0; i < 32; ++i) {
				int rev_i=i^31;
				int nans=abs(vs[i]+vs[rev_i]);
				ans=max(ans,nans);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}