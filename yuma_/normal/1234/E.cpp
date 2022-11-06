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


using Value=int;
const Value ini =0;
// Value operator +(const Value&al,const Value&ar){
// 	return al+ar;
// }
Value connect(Value al,const Value ar){
	return al|ar;
}
Value dat[800001];
struct segtree {
	int N;

	segtree() {}
	segtree(int n):segtree(n,vector<Value>(n,ini)){

	}
	segtree(int n,vector<Value>v)  {
		N = 1;
		while (N < n) N *= 2;
		
		for(int x=0;x<N;++x){
			if(x<v.size()){
				dat[x+N-1]=v[x];
			}else{
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
		if (r <= a or b <= l) return ini;
		if (a <= l and r <= b) return dat[k];
		const int m = (l + r) / 2;
		return connect(query(a, b, k * 2 + 1, l, m),query(a, b, k * 2 + 2, m, r));
	}

	
};


int main() {
	ios::sync_with_stdio(false);
	int N,M;cin>>N>>M;
	vector<int>v(M);
	for(int i=0;i<M;++i)cin>>v[i];
	for(int i=0;i<M;++i)v[i]--;
	vector<int>perms(N);
	perms=v;

	vector<vector<int>>ids(N);
	for(int i=0;i<M;++i){
		ids[v[i]].push_back(i);
	}
	vector<ll>anss(N);
	for(int i=0;i<M-1;++i){
		anss[0]+=abs(v[i]-v[i+1]);
	}
	//WHATS(ids)
	//WHATS(perms)
	for(int i=1;i<N;++i){
		anss[i]=anss[i-1];
		vector<pair<int,int>>querys;
		for(auto id:ids[i-1]){
			querys.push_back(make_pair(id,i));
		}
		for(auto id:ids[i]){
			querys.push_back(make_pair(id,0));
		}
		for(auto q:querys){
			//WHATS(perms)
			//WHATS(anss[i])
			if(q.first!=0){
				anss[i]-=abs(perms[q.first]-perms[q.first-1]);
			}
			if(q.first!=M-1){
				anss[i]-=abs(perms[q.first]-perms[q.first+1]);
			}
			perms[q.first]=q.second;
			if(q.first!=0){
				anss[i]+=abs(perms[q.first]-perms[q.first-1]);
			}
			if(q.first!=M-1){
				anss[i]+=abs(perms[q.first]-perms[q.first+1]);
			}
			//WHATS(perms)
			//WHATS(anss[i])
		}
		//WHATS(perms)
	}
	for(int i=0;i<N;++i){
		cout<<anss[i]<<' ';
	}
	cout<<endl;
	return 0;
}