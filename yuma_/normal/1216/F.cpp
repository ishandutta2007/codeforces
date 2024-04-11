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
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;
	
#define WHATS(var)cout<<__LINE__<<' '<<#var<<"="<<var<<endl;
	
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
	
	
using ll = long long int;
using Value=ll;
const Value ini =1e18;
Value connect(Value al,const Value ar){
	return min(al,ar);
}
Value dat[800001];
struct segtree {
	int N;

	segtree() {}
	
	segtree(int n)  {
		N = 1;
		while (N < n) N *= 2;
		
		for(int x=0;x<N;++x){
			
			dat[x+N-1] = ini;
			
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
		if (r <= a or b <= l) return ini;
		if (a <= l and r <= b) return dat[k];
		const int m = (l + r) / 2;
		return connect(query(a, b, k * 2 + 1, l, m),query(a, b, k * 2 + 2, m, r));
	}

	
};

struct qu{
	int from;
	int to;
	ll cost;
};
int main() {
	ios::sync_with_stdio(false);
	int N,K;cin>>N>>K;
	string st;cin>>st;
	segtree seg(N+1);
	seg.update(0,0);
	vector<vector<qu>>qs(N+1);

	for(int i=0;i<N;++i){
		if(st[i]=='1'){
			int from=max(0,i-K);
			int to=min(N,i+K+1);

			qs[to].push_back(qu{from,to,i+1});
		}
		qs[i+1].push_back(qu{i,i+1,i+1});
	}

	vector<ll>anss(N+1,ini);
	anss[0]=0;
	for(int i=0;i<N;++i){
		ll ans=ini;
		for(auto q:qs[i+1]){
			anss[i+1]=min(anss[i+1],seg.query(q.from,i+1)+q.cost);
			seg.update(i+1,anss[i+1]);
		}
	}
	cout<<anss[N]<<endl;

	return 0;
}