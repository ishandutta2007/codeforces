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

struct Value1 {
	long long int len;
};
typedef ll Value2;
const Value1 Zero1{0};
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
		for (int i = 0; i < v.size(); ++i) {
			dat[i+N].sum = v[i];
		}
		for (int i = N - 1; i >= 1; --i) {
			update_node(i);
		}
	}
 
	Value2 lazy_connect(const Value2 l, const Value2 r) {
		return max(l,r);
	}
 
	void lazy_func(const int k, const int a, const int b) {
		if (dat[k].lazy)dat[k].sum.len=0;
	}
 
	Value1 connect(const Value1 l, const Value1 r) {
		return Value1{l.len+r.len};
	}
 
	// inline!()
	inline void lazy_evaluate_node(int k, int a, int b) {
		lazy_func(k, a, b);
		if (k < N) { // 2*k() < 2*N () . .
			dat[2 * k].lazy = lazy_connect(dat[2 * k].lazy, dat[k].lazy);	//.
			dat[2 * k + 1].lazy = lazy_connect(dat[2 * k + 1].lazy, dat[k].lazy);
		}
		//WHATS(dat[2*k].lazy)
		dat[k].lazy = Zero2;
	}
 
	inline void update_node(int k) { // k. if.
		dat[k].sum = connect(dat[2 * k].sum, dat[2 * k + 1].sum);
 
	}
 
	// update(l,r,v) := [l,r). 0-indexed.
	void update(int l, int r, Value2 v, int k = 1, int a = 0, int b = -1) {
		//WHATS(a)
		//WHATS(b)
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


map<ll,int>amp;
map<int,ll>rev_mp;

int main() {
	
	ios::sync_with_stdio(false);
	ll D,N,M;cin>>D>>N>>M;
	deque<pair<ll,ll>>que;

	vector<pair<ll,ll>>pluss;
	for(int i=0;i<M;++i){
		ll x,p;cin>>x>>p;
		pluss.push_back(make_pair(x,p));
	}
	pluss.push_back(make_pair(0,0));
	pluss.push_back(make_pair(D,0));
	sort(pluss.begin(),pluss.end());
	ll pre_x=0;
	bool ok=true;
	ll answer=0;
	for(auto pl:pluss){
		
		ll now_x=pl.first;
		ll acost=pl.second;
		if(pre_x!=now_x){
			
			while(que.size()&&pre_x!=now_x){
				auto p=que.front();
				if(p.second<pre_x){
					assert(false);
				}else{
					if(p.second<=now_x){
						answer+=(p.second-pre_x)*p.first;
						pre_x=p.second;
						que.pop_front();
					}else{
						answer+=(now_x-pre_x)*p.first;
						pre_x=now_x;
					}
				}
			}
			if(que.empty()&&now_x!=pre_x){
				ok=false;
			}
		}
		if(now_x==D)break;
		else{
			{
				while(!que.empty()&&que.back().first>acost){
					que.pop_back();
				}
				que.emplace_back(acost,now_x+N);
			}
		}
	}
	if(!ok)answer=-1;
	cout<<answer<<endl;
	return 0;
}