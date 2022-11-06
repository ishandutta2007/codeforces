#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;

long long int A,B;
#define Seg_Max_N (1<<20) 
struct Value {
	long long int hero_cnt;
	long long int len;
	long long int answer;
};
Value ini = Value{
	0,1,0
};
//struct segtree {
//	int N;
//	vector<Value>dat;
//
//	segtree() {}
//	segtree(int n) :dat(2 * Seg_Max_N) {
//		N = 1;
//		while (N < n) N *= 2;
//		for (int i = 0; i < 2 * N - 1; i++) {
//			dat[i] = ini;
//		}
//	}
//	Value connect(const Value&l, const Value&r) {
//		long long int nanswer=0;
//		long long int hero_sum=l.hero_cnt+r.hero_cnt;
//		if (hero_sum==0) {
//			nanswer=A;
//		}
//		else {
//			(l.len+r.len)*B*hero_sum;
//		}
//		nanswer=min(nanswer,l.answer+r.answer);
//
//		return Value{ hero_sum,l.len + r.len,nanswer };
//	}
//	// update k th element
//	void update(int k, Value a) {
//		k += N - 1;
//		dat[k] = a;
//
//		while (k > 0) {
//			k = (k - 1) / 2;
//			const Value al(dat[k * 2 + 1]);
//			const Value ar(dat[k * 2 + 2]);
//			dat[k] = connect(al, ar);
//		}
//	}
//	// min [a, b)
//	Value  query(int a, int b) { return query(a, b, 0, 0, N); }
//	Value  query(int a, int b, int k, int l, int r) {
//		if (r <= a or b <= l) return ini;
//		if (a <= l and r <= b) return dat[k];
//		const int m = (l + r) / 2;
//		const Value al(query(a, b, k * 2 + 1, l, m));
//		const Value ar(query(a, b, k * 2 + 2, m, r));
//		return connect(al, ar);
//	}
//};
Value connect(const Value&l, const Value&r) {
	long long int nanswer = 0;
	long long int hero_sum = l.hero_cnt + r.hero_cnt;
	if (hero_sum == 0) {
		nanswer = A;
	}
	else {
		nanswer=(l.len + r.len)*B*hero_sum;
	}
	nanswer = min(nanswer, l.answer + r.answer);

	return Value{ hero_sum,l.len + r.len,nanswer };
}
Value solve(int l, int r, const vector<int>&vs) {
	auto lt=lower_bound(vs.begin(),vs.end(),l);
	auto rt=lower_bound(vs.begin(),vs.end(),r);
	if (lt == rt) {
		return Value{ 0,r - l,A };
	}
	else {

		if (l+1==r) {
			return Value{ (rt-lt),1,B*1*(rt-lt) };
		}
		Value lv=solve(l,(l+r)/2,vs);
		Value rv=solve((l+r)/2,r,vs);

		Value my_v=connect(lv,rv);
		return my_v;
	}
}
int main() {
	int N,K;
	cin>>N>>K>>A>>B;
	vector<int>v(K);
	for(int i=0;i<K;++i)scanf("%d",&v[i]),v[i]--;
	sort(v.begin(),v.end());
	Value answer=solve(0,(1<<N),v);
	cout<<answer.answer<<endl;
	return 0;
}