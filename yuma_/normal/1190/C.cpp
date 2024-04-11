#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;

struct Value{
	int z_l;
	int z_r;
	int o_l;
	int o_r;
};
Value operator +(const Value&l,const Value&r){
	return Value{
		min(l.z_l,r.z_l),
		max(l.z_r,r.z_r),
		min(l.o_l,r.o_l),
		max(l.o_r,r.o_r)
	};
}
const Value ini =Value{int(1e9),-1,int(1e9),-1};
// Value operator +(const Value&al,const Value&ar){
// 	return al+ar;
// }
#define WHATS(var) //cout<<#var<<"="<<var<<endl;

struct segtree {
	int N;
	vector<Value>dat;

	segtree() {}
	segtree(int n)  {
		N = 1;
		while (N < n) N *= 2;
		dat.resize(2*N-1);
		for (int i = 0; i < 2 * N - 1; i++) {
			dat[i] = ini;
		}
	}
	// update k th element
	void update(int k, Value a) {
		 k += N - 1;
		dat[k] = a;
		
		while (k > 0) {
			k = (k - 1) / 2;
			const Value al(dat[k * 2 + 1]);
			const Value ar(dat[k * 2 + 2]);
			dat[k] =al+ar;
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
		return al+ar;
	}
};
int main() {
	ios::sync_with_stdio(false);
	ll N;cin>>N;
	int K;cin>>K;
	string st;cin>>st;
	segtree seg(N);
	for(int i=0;i<N;++i){
		if(st[i]=='1'){
			seg.update(i,Value{int(1e9),-1,i,i+1});
		}else{
			seg.update(i,Value{i,i+1,int(1e9),-1});
		}
	}
	int win=-1;
	for(int l=0;l<=N-K;++l){
		auto l_seg=seg.query(0,l);
		auto r_seg=seg.query(l+K,N);

		auto sum=l_seg+r_seg;

		if(sum.o_r==-1||sum.z_r==-1){
			//cout<<l<<endl;
			//WHATS(sum.o_r);
			//WHATS(sum.z_r);
			win=max(win,1);
		}else{
			auto asum=sum;
			for(int now=0;now<2;++now){
				if(now==1){
					sum.o_l=min(sum.o_l,l);
					sum.o_r=max(sum.o_r,l+K);
				}else{
					sum.z_l=min(sum.z_l,l);
					sum.z_r=max(sum.z_r,l+K);
				}
				int o_dis=sum.o_r-sum.o_l;
				int z_dis=sum.z_r-sum.z_l;

				if(o_dis<=K||z_dis<=K){

				}else{
					//cout<<o_dis<<endl;
					//cout<<z_dis<<endl;
					win=max(win,0);
				}
				sum=asum;
			}
			
		}
	}
	if(win==1){
		cout<<"tokitsukaze";
	}else if(win==0){
		cout<<"once again";
	}else{
		cout<<"quailty";
	}
	cout<<endl;
	return 0;
}