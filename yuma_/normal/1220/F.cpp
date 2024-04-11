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
	
using ll=long long ;

using Value1=int;
typedef int Value2;
const Value1 Zero1=0;
const Value2 Zero2=0;
 
struct Node {
	Value1 sum;//. .
	Value2 lazy;	//
	Node() :sum(Zero1) {
		lazy = Zero2;
	}
};
struct lazy_segtree {
	int N;
	vector<Node>dat;
	lazy_segtree(int n) :N(1) {
		while (N < n) N *= 2;
		dat.resize(2 * N);
		
		for (int i = N - 1; i >= 1; --i) {
			update_node(i);
		}
	}
 
	Value2 lazy_connect(const Value2 l, const Value2 r) {
		return l+r;
	}
 
	void lazy_func(const int k, const int a, const int b) {
		
		dat[k].sum+=dat[k].lazy;
	}
 
	Value1 connect(const Value1 l, const Value1 r) {
		return max(l,r);
	}
 
	// inline!()
	inline void lazy_evaluate_node(int k, int a, int b) {
		lazy_func(k, a, b);
		if (k < N) { // 2*k() < 2*N () . .
			dat[2 * k].lazy = lazy_connect(dat[2 * k].lazy, dat[k].lazy);	//.
			dat[2 * k + 1].lazy = lazy_connect(dat[2 * k + 1].lazy, dat[k].lazy);
		}
		dat[k].lazy = Zero2;
	}
 
	inline void update_node(int k) { // k. if.
		dat[k].sum = connect(dat[2 * k].sum, dat[2 * k + 1].sum);
 
	}
 
	// update(l,r,v) := [l,r). 0-indexed.
	void update(int l, int r, Value2 v, int k = 1, int a = 0, int b = -1) {
		if (b == -1)b = N;
		if (l < 0 || r < 0)assert(false);
		lazy_evaluate_node(k, a, b); 	// .
 
		if (b <= l || r <= a) //[a,b)[l,r)
			return;
		if (l <= a && b <= r) { // [l,r)[a,b)
			dat[k].lazy = lazy_connect(dat[k].lazy, v);
			lazy_evaluate_node(k, a, b); //.
			return;
		}
 
		int m = (a + b) / 2;
		update(l, r, v, 2 * k, a, m);
		update(l, r, v, 2 * k + 1, m, b);
		update_node(k);
	}
	//get(l,r) := [l,r). 0-indexed.
	Value1 get(int l, int r, int k = 1, int a = 0, int b = -1) {
		if (b == -1)b = N;
 
		if (l < 0 || r<0)assert(false);
		lazy_evaluate_node(k, a, b); // .
 
		if (b <= l || r <= a) //[a,b)[l,r)
			return Zero1;
 
		if (l <= a && b <= r) { // [l,r)[a,b)
			return dat[k].sum;
		}
 
		int m = (a + b) / 2;
		Value1 vl = get(l, r, 2 * k, a, m);
		Value1 vr = get(l, r, 2 * k + 1, m, b);
		update_node(k);
		return connect(vl, vr);
	}

};


int main() {
	ios::sync_with_stdio(false);
	int N;cin>>N;
	if(N==1){
		cout<<1<<' '<<0<<endl;
		return 0;
	}
	vector<int>v(N);
	for(int i=0;i<N;++i)cin>>v[i];
	for(int i=0;i<N;++i)v[i]--;
	int tt=find(v.begin(),v.end(),0)-v.begin();
	rotate(v.begin(),find(v.begin(),v.end(),0)+1,v.end());

	vector<int>rs(N);
	vector<int>places(N);
	for(int i=0;i<N;++i){
		places[v[i]]=i;
	}
	set<int>aset;
	lazy_segtree dep_tree(N);
	for(int i=0;i<N;++i){
		int aplace=places[i];
		auto it=aset.lower_bound(aplace);
		int r=N;
		int l=0;
		if(it!=aset.end()){
			r=(*it);
		}
		if(it!=aset.begin()){
			l=(*prev(it))+1;
		}
		rs[aplace]=r;
		dep_tree.update(l,aplace,1);
		dep_tree.update(aplace+1,r,1);
		aset.emplace(aplace);
	}
	// for(int i=0;i<N;++i){
	// 	cout<<dep_tree.get(i,i+1)<<' ';
	// }
	// cout<<endl;
	ll answer=0;

	vector<int>r_set;
	r_set.emplace_back(0);
	vector<int>answers;
	for(int i=0;i<N;++i){
		answers.push_back(dep_tree.get(0,N));
		if(i==N-1)break;
		dep_tree.update(i+1,rs[i],-1);

		while(r_set.back()>v[i]){
			r_set.pop_back();
		}
		dep_tree.update(i,i+1,-dep_tree.get(i,i+1));
		dep_tree.update(i,i+1,r_set.size());
		dep_tree.update((places[r_set.back()]+1)%N,i,1);
		// for(int i=0;i<N;++i){
		// 	cout<<dep_tree.get(i,i+1)<<' ';
		// }
		// cout<<endl;
		r_set.emplace_back(v[i]);
	}
	//WHATS(answers)
	auto it=min_element(answers.begin(),answers.end());
	//WHATS(answers)
	int kk=*it;
	int cnt=((tt+1+(it-answers.begin())))%N;
	if(cnt<0)cnt+=N;
	cout<<kk+1<<' '<<cnt<<endl;
	return 0;
}