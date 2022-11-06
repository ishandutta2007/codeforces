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

struct po{
	int l;
	int r;
	ll cost;
};
struct Compress {
	map<int, int>mp;
	map<int, int>revmp;

	Compress(vector<int>vs) {
		sort(vs.begin(), vs.end());
		vs.erase(unique(vs.begin(),vs.end()),vs.end());
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
using Value1=pair<long long int,int>;
typedef long long int Value2;
const Value1 Zero1(-1,-1);
const Value2 Zero2(0);
 
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
	lazy_segtree(int n,vector<Value1>v) :N(1) {
		while (N < n) N *= 2;
		dat.resize(2 * N);
		for(int i=0;i<v.size();++i){
			dat[N+i].sum=v[i];
		}
		for (int i = N - 1; i >= 1; --i) {
			update_node(i);
		}
	}
 
	Value2 lazy_connect(const Value2 l, const Value2 r) {
		return l+r;
	}
 
	void lazy_func(const int k, const int a, const int b) {
		dat[k].sum.first+=dat[k].lazy;
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
	vector<po>pos;
	vector<int>v;
	for(int i=0;i<N;++i){
		int x,y,c;cin>>x>>y>>c;
		int l=min(x,y);
		int r=max(x,y);
		pos.push_back(po{l,r,c});
		v.push_back(x);
		v.push_back(y);
	}
	Compress comp(v);
	vector<vector<po>>l_pos(comp.mp.size());

	vector<Value1>vals(comp.mp.size());

	auto jt=comp.mp.begin();
	for(int i=0;i<comp.mp.size();++i){
		vals[i]=make_pair(-(jt->first-comp.mp.begin()->first),i);
		jt++;
	}
	//WHATS(vals)
	lazy_segtree seg(comp.mp.size(),vals);
	for(int i=0;i<N;++i){
		po apo(pos[i]);
		apo.l=comp.mp[apo.l];
		apo.r=comp.mp[apo.r];
		l_pos[apo.l].push_back(apo);
		//cout<<apo.r<<' '<<comp.mp.size()<<' '<<apo.cost<<endl;
		seg.update(apo.r,comp.mp.size(),apo.cost);
	}
	pair<ll,pair<int,int>>answer(0,make_pair(1e9,1e9));

	auto it=comp.mp.begin();
	for(int l=0;l<comp.mp.size();++l){
		auto n_answer=seg.get(l,comp.mp.size());
		answer=max(answer,make_pair(n_answer.first,make_pair(l,n_answer.second)));
		//WHATS(answer)
		for(auto apo:l_pos[l]){
			seg.update(apo.r,comp.mp.size(),-apo.cost);
		}
		if(l!=comp.mp.size()-1){
			ll plus=(next(it))->first-(it->first);
			seg.update(0,comp.mp.size(),plus);
			it++;
		}
	}
	cout<<answer.first<<endl;
	//WHATS(answer.second)
	ll al=comp.revmp[answer.second.first];
	ll ar=comp.revmp[answer.second.second];
	if(answer.first==0){
		al=2e9;
		ar=2e9;
	}
	cout<<al<<' '<<al<<' '<<ar<<' '<<ar<<endl;
	return 0;
}