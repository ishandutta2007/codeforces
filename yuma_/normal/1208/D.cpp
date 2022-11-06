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
using ld = __float128;
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
	
	segtree(int n,vector<Value>&v)  {
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
	int dfs(Value need){return dfs(need,0,0,N);};
	int dfs(Value need,int k,int l,int r){
		// WHATS(l)
		// WHATS(r)
		// WHATS(need)
		// WHATS(dat[2*k+1])
		int m=((l+r)/2);
		if(l+1==r){
			if(need<dat[k])return l;
			else return r;
		}
		if(need>=dat[2*k+1]){

			return dfs(need-dat[2*k+1],2*k+2,m,r);
		}else{
			return dfs(need,2*k+1,l,m);
		}
	}
	
};
int main() {
	ios::sync_with_stdio(false);
	int N;cin>>N;
	vector<ll>v(N);
	for(int i=0;i<N;++i){
		cin>>v[i];
	}
	vector<ll>xx(N);
	iota(xx.begin(),xx.end(),1ll);
	segtree seg(N,xx);
	vector<int>anss(N);
	for(int i=N-1;i>=0;--i){
		ll num=v[i];
		int place=seg.dfs(num);
		anss[i]=place+1;
		seg.update(place,0);
	}
	for(int i=0;i<N;++i)cout<<anss[i]<<' ';
	cout<<endl;
	return 0;
}