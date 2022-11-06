#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;

#define Seg_Max_N (1<<18) 

struct Value{
	int l_id;
	int or_sum;
	int max_num;
};

const Value ini = Value{(1<<31),0,-1 };
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
		pair<int,int>p=make_pair(l.max_num,l.l_id);
		p=max(p,make_pair(r.max_num,r.l_id));
		return Value{ p.second,l.or_sum | r.or_sum,p.first };
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
segtree seg;
long long int solve(int l, int r) {
	if (l + 1 >= r) {
		return 0;
	}
	else {
		auto val=seg.query(l,r);
		val=seg.query(val.l_id,val.l_id+1);
		long long int max_place=val.l_id;
		long long int l_place,r_place;
		{
			int amin=l-1;
			int amax=max_place;
			while (amin + 1 != amax) {
				int amid((amin+amax)/2);
				auto aval=seg.query(amid,max_place);
				if ((aval.or_sum | val.or_sum) != val.or_sum) {
					amin=amid;
				}
				else {
					amax=amid;
				}
			}
			l_place=amin;
		}
		{
			int amin = max_place;
			int amax = r+1;
			while (amin + 1 != amax) {
				int amid((amin + amax) / 2);
				auto aval = seg.query(max_place,amid);
				if ((aval.or_sum | val.or_sum) != val.or_sum) {
					amax = amid;
				}
				else {
					amin = amid;
				}
			}
			r_place = amax;
		}
		long long int answer=(max_place-l+1)*(r-max_place);
		answer-=(max_place-l_place)*(r_place-max_place-1);
		answer+=solve(l,max_place);
		answer+=solve(max_place+1,r);
		return answer;
	}
}

int main() {
	int N;cin>>N;
	vector<int>hs(N);
	for (int i = 0; i < N; ++i) {
		scanf("%d",&hs[i]);
	}
	seg=segtree(N);
	for (int i = 0; i < N; ++i) {
		seg.update(i, Value{ i,hs[i],hs[i] });
	}
	long long int answer=solve(0,N);
	cout<<answer<<endl;
	return 0;
}