#include "bits/stdc++.h"
#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<iomanip>
#include<assert.h>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<stack>
#include<complex>
#include<memory>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse2")

#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;
using Graph=vector<vector<int>>;
using ll=long long;
	
#define WHATS(var)//cout<<__LINE__<<' '<<#var<<"="<<var<<endl;
	
template<class S, class T> ostream& operator <<(ostream &os, const pair<S, T> v){
	os << "( " << v.first << ", " << v.second << ")"; return os;
}
template<class T> ostream& operator <<(ostream &os, const vector<T> &v){
	for(int i = 0; i < v.size(); i++){if(i > 0){os << " ";} os << v[i];} return os;
}
template<class T> ostream& operator <<(ostream &os, const vector<vector<T>> &v){
	for(int i = 0; i < v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}
template<class T> ostream& operator <<(ostream &os, const vector<set<T>> &v){
	for(int i = 0; i < v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}
template<class T> ostream& operator <<(ostream &os, const set<T> &v){
	int i=0;
	for(auto it:v){
		if(i > 0){os << ' ';}
		os << it;
		i++;
	} 
	return os;
}
//1. mask
	// 	a. i==0
	// 	for(int i=mask; i>0; i=(i-1)&mask) {
	// 	}

	// b. i==0
	// 	for(int i=mask; i>=0; i--) {
	// 		i&=mask;
	// 	}
// 2. mask

// mask

// 	for(int i=mask; i<(1<<n); i=(i+1)|mask) {
// 	}


using Value=ll;
const Value ini =0;
// Value operator +(const Value&al,const Value&ar){
// 	return al+ar;
// }
Value connect(Value al,const Value ar){
	return al+ar;
}
Value dat[800001];
struct segtree {
	int N;

	segtree() {}
	
	segtree(int n)  {
		N = 1;
		while (N < n) N *= 2;
		
		for(int x=0;x<N;++x){
			{
				dat[x+N-1] = ini;
			}
		}
		for(int x=N-2;x>=0;--x){
			dat[x]=connect(dat[x*2+1],dat[x*2+2]);
		}
	}
	// update k th element
	void update(int k,const Value& a) {
		 k += N - 1;
		dat[k] = a;
		
		while (k > 0) {
			k = (k - 1) >>1;
			dat[k]=connect(dat[k * 2 + 1],dat[k * 2 + 2]);
		}
	}
	// min [a, b)
	Value  query(int a, int b) { return query(a, b, 0, 0, N); }
	Value  query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l) return ini;
		if (a <= l && r <= b) return dat[k];
		const int m = (l + r) / 2;
		return connect(query(a, b, k * 2 + 1, l, m),query(a, b, k * 2 + 2, m, r));
	}
};

struct query{
	ll x;
	int id;
	int type;
};
ll solve(vector<pair<int,int>>ps){
	sort(ps.begin(),ps.end(),[](const pair<int,int>&l,const pair<int,int>&r){
		return (l.first==r.first)?l.second>r.second:l.first<r.first;
		});
	vector<query>qs;
	for(int i=0;i<ps.size();++i){
		qs.push_back(query{ps[i].first,i,0});
		qs.push_back(query{ps[i].second,-i,1});
	}
	sort(qs.begin(),qs.end(),[](const query&l,const query&r){
		return l.x==r.x?l.id<r.id:l.x<r.x;
	});
	segtree seg(240000);
	ll answer=0;
	for(auto q:qs){
		if(q.type==0){
			seg.update(q.x,seg.query(q.x,q.x+1)+1);
		}else{
			int al=ps[-q.id].first;;
			ll tt=seg.query(al,al+1);
			WHATS(tt)
			seg.update(al,seg.query(al,al+1)-1);

			answer+=seg.query(0,al+1);
			WHATS(al)
			WHATS(answer)
		}
	}
	return answer;
}
ll solve2(vector<pair<int,int>>ls,const vector<pair<int,int>>rs){
	vector<int>mins,maxs;
	for(auto tt:rs){
		mins.push_back(tt.first);
		maxs.push_back(tt.second);
	}
	sort(mins.begin(),mins.end());
	sort(maxs.begin(),maxs.end());
	ll answer=0;
	for(auto p:ls){
		auto mit=upper_bound(mins.begin(),mins.end(),p.second);
		auto mat=lower_bound(maxs.begin(),maxs.end(),p.first);

		answer+=(int(rs.size())-(mins.end()-mit)-(mat-maxs.begin()));
	}
	return answer;
}
struct bu{
	ll si;
	ll bo;
};
bool operator<(const bu&l,const bu&r){return l.si*r.bo<l.bo*r.si;};
bool operator==(const bu&l,const bu&r){return l.si*r.bo==l.bo*r.si;};


int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int N,V;cin>>N>>V;
	vector<pair<int,int>>ls,rs;
	for(int i=0;i<N;++i){
		int x,v;cin>>x>>v;
		if(x<0)ls.emplace_back(v,-x);
		else rs.emplace_back(-v,x);
	}
	ll ans_sum=0;
	{
		vector<pair<bu,bu>>l_bus,r_bus;
		vector<bu>all_bus;
		for(auto aa:ls){
			bu amin=bu{aa.second,aa.first+V};
			bu amax=bu{aa.second,aa.first-V};
			l_bus.push_back(make_pair(amin,amax));
			all_bus.push_back(amin);
			all_bus.push_back(amax);
		}
		for(auto aa:rs){
			bu amin=bu{aa.second,aa.first+V};
			bu amax=bu{aa.second,aa.first-V};
			r_bus.push_back(make_pair(amin,amax));
			
			all_bus.push_back(amin);
			all_bus.push_back(amax);
		}
		sort(all_bus.begin(),all_bus.end());
		all_bus.erase(unique(all_bus.begin(),all_bus.end()),all_bus.end());
		map<bu,int>mp;
		for(int i=0;i<all_bus.size();++i){
			mp[all_bus[i]]=i;
		}
		for(int i=0;i<ls.size();++i){
			ls[i]=make_pair(mp[l_bus[i].first],mp[l_bus[i].second]);

		}
		for(int i=0;i<rs.size();++i){
			rs[i]=make_pair(mp[r_bus[i].first],mp[r_bus[i].second]);
			
		}
		
	}
	// WHATS(ls)
	// WHATS(rs)
	if(V){
		
		ll ans1=solve(ls);
		ll ans2=solve(rs);
		ll ans3=solve2(ls,rs);
		WHATS(ans1)
		WHATS(ans2)
		WHATS(ans3)
		ans_sum=ans1+ans2+ans3;
	}else{
		map<int,ll>mp;
		for(auto kk:ls){
			mp[kk.first]++;
		}
		for(auto kk:rs){
			mp[kk.first]++;
		}
		for(auto m:mp){
			ans_sum+=m.second*(m.second-1)/2;
		}
	}
	cout<<ans_sum<<endl;
	// int H,W;cin>>H>>W;
	// vector<string>field(H);
	// for(int y=0;y<H;++y){
	// 	cin>>field[y];

	// }
	// UnionFind uf(H+W);
	// for(int y=0;y<H;++y){
	// 	for(int x=0;x<W;++x){
	// 		if(field[y][x]=='#')uf.unionSet(y,x+H);
	// 	}
	// }
	// bool ok=true;
	// for(int y=0;y<H;++y){
	// 	for(int x=0;x<W;++x){
	// 		if(field[y][x]=='.'){
	// 			if(uf.root(y)==uf.root(x+H))ok=false;
	// 		}
	// 	}
	// }
	// if(ok)cout<<"Yes"<<endl;
	// else cout<<"No"<<endl;


	return 0;
}