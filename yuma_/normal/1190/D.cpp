#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;

struct Compress {
	map<int, int>mp;
	map<int, int>revmp;

	Compress(vector<int>vs) {
		sort(vs.begin(), vs.end());
		for (int i = 0; i < vs.size(); ++i) {
			mp[vs[i]] = i;
			revmp[i] = vs[i];
		}
	}
	Compress(const set<int>&vs) {
		int num = 0;
		for (auto v : vs) {
			mp[v] = num;
			revmp[num] = v;
			num++;
		}
	}
};
using Value=long long ;
const Value ini =0;
// Value operator +(const Value&al,const Value&ar){
// 	return al+ar;
// }
#define WHATS(var) cout<<#var<<"="<<var<<endl;

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

	int dfs(int k,int l,int r,Value v){
		if(l+1==r){
			WHATS(r)
			return r;
		}else{
			const int m=(l+r)/2;
			const Value al=dat[2*k+1];
			
			if(al>=v){
				return dfs(2*k+1,l,m,v);
			}else{
				return dfs(2*k+2,m,r,v-al);
			}
		}
	}
};
int main() {
	ios::sync_with_stdio(false);
	int N;cin>>N;
	vector<pair<int,int>>ps(N);
	vector<int>xs,ys;
	for(int i=0;i<N;++i){
		int x,y;cin>>x>>y;
		xs.push_back(x);
		ys.push_back(y);
		ps[i]=make_pair(x,y);
	}
	Compress x_comp(xs);
	Compress y_comp(ys);
	for(int i=0;i<N;++i){
		ps[i].first=x_comp.mp[ps[i].first];
		ps[i].second=y_comp.mp[ps[i].second];
	}
	map<int,vector<int>>mp;
	for(auto p:ps){
		mp[-p.second].push_back(p.first);
	}
	
	ll answer=0;
	segtree seg(N);
	ll sum=0;
	for(auto m:mp){
		vector<int>v(m.second);
		sort(v.begin(),v.end());
		for(int i=0;i<v.size();++i){
			seg.update(v[i],1);
		}
		sum=seg.query(0,N);
		//cout<<sum<<endl;
		answer+=sum*(sum+1)/2;
		for(int i=0;i<=v.size();++i){
			ll asum=-1;
			if(i==0){
				asum=seg.query(0,v[i]);
			}else if(i==v.size()){
				asum=seg.query(v[i-1]+1,N);
			}else{
				asum=seg.query(v[i-1]+1,v[i]);
			}
			//cout<<asum<<endl;
			//WHATS(asum);
			answer-=asum*(asum+1)/2;
		}
	}
	cout<<answer<<endl;
	return 0;
}