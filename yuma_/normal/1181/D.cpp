#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;

using Value=long long ;
const Value ini =0;
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
	int N,M,Q;cin>>N>>M>>Q;
	vector<int>nums(M);
	for(int i=0;i<N;++i){
		int a;cin>>a;a--;
		nums[a]++;
	}
	map<ll,vector<int>>mp;
	for(int i=0;i<M;++i){
		mp[nums[i]].push_back(i);
	}
	vector<pair<ll,int>>querys;
	for(int i=0;i<Q;++i){
		ll a;cin>>a;a-=N;
		querys.push_back(make_pair(a,i));
		WHATS(a);
	}
	mp[0];
	sort(querys.begin(),querys.end());

	vector<int>anss(Q);
	segtree seg(M);
	ll now=0;
	auto it=mp.begin();
	ll sum=mp[0].size();
	for(auto a:mp[0]){
		seg.update(a,1);
	}
	//cout<<sum<<endl;
	
	for(auto q:querys){
		int id=q.second;
		ll year=q.first;
		int answer=-1;

		while(true){
			if(next(it)==mp.end()){
			
				int place=(year-now)%sum;
				if(place==0)place=sum;
				answer=seg.dfs(0,0,seg.N,place);
				break;
			}else{
				ll dif=next(it)->first-it->first;
				WHATS(dif);
				ll total=dif*sum;
				WHATS(total)
				WHATS(now)
				WHATS(year)
				if(total+now>=year){
					int place=(year-now)%sum;
					if(place==0)place=sum;
					answer=seg.dfs(0,0,seg.N,place);
					break;
				}else{
					now+=total;
					it++;
					for(auto a:it->second){
						seg.update(a,1);
						sum++;
					}
				}
			}
		}
		anss[id]=answer;	
	}
	for(int i=0;i<Q;++i){
		cout<<anss[i]<<endl;
	}
}