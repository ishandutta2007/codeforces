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


using Value1=pair<int,int>;
using  Value2=int;
const Value1 Zero1(0,0);
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
	lazy_segtree(int n) :N(1) {
		while (N < n) N *= 2;
		dat.resize(2 * N);

	}
 
	Value2 lazy_connect(const Value2 l, const Value2 r) {
		return l+r;
	}
 
	inline void lazy_func(const int k, const int a, const int b) {
		dat[k].sum.first +=(dat[k].lazy);
		dat[k].sum.second+=dat[k].lazy;
	}
 
	inline Value1 connect(const Value1& l, const Value1& r) {
		return make_pair(min(l.first,r.first),max(l.second,r.second));
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
	char chs[1000010];

int main() {
	ios::sync_with_stdio(false);
	int N;cin>>N;
	vector<int>v(N);
	for(int i=0;i<N;++i){
		int a;cin>>a;
		v[a]++;
	}
	while(v.back()==0)v.pop_back();
	for(int h=1;h*h<=N;++h){
		if(N%h)continue;
		int w=N/h;
		for(int  ay=0;ay<h;++ay){
			int ax=int(v.size())-ay-1;
			if(ax<0||ax>=w)continue;

			int pre=0;
			bool ok=true;
			vector<int>diss{ax+1,ay+1,w-ax,h-ay};
			for(int k=0;k<v.size();++k){
				int need;
				int plus=4;

				if(k==0){
					need=1;
				}else{
					for(int l=0;l<4;++l){
						if(diss[l]==k)plus--;
						else if(diss[l]<k)plus-=2;

						int r=(l+1)%4;
						if(diss[l]+diss[r]<=k)plus++;
						//if(diss[l]+diss[r]<k)plus+=2;
					}
					need=pre+plus;
				}
				// WHATS(h)
				// WHATS(w)
				// WHATS(ay)
				// WHATS(ax)
				// WHATS(k)
				// WHATS(need);
				if(need!=v[k]){
					ok=false;
					break;
				}else{
					pre=need;
					if(k==0)pre--;
				}
			}
			if(ok){
				cout<<h<<' '<<w<<endl;
				cout<<ay+1<<' '<<ax+1<<endl;
				return 0;
			}
		}
		
	}
	cout<<-1<<endl;
	return 0;
}