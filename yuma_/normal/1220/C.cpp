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

class asuffix_array {
	const int an;
public:

	string S;
	vector<int> sa, rank;
	asuffix_array(const string &S_) : an(S_.size()), S(S_), sa(an + 1), rank(an + 1) {
		for (int i = 0; i <= an; i++) {
			sa[i] = i;
			rank[i] = i < an ? S[i] : -1;
		}
		vector<int> tmp(an + 1);
		for (int k = 1; k <= an; k *= 2) {
			auto Compare_SA = [=](int i, int j) {
				if (rank[i] != rank[j]) return rank[i] < rank[j];
				int ri = i + k <= an ? rank[i + k] : -1;
				int rj = j + k <= an ? rank[j + k] : -1;
				return ri < rj;
			};
			sort(sa.begin(), sa.end(), Compare_SA);
			tmp[sa[0]] = 0;
			for (int i = 1; i <= an; i++)
				tmp[sa[i]] = tmp[sa[i - 1]] + (Compare_SA(sa[i - 1], sa[i]) ? 1 : 0);
			for (int i = 0; i <= an; i++)
				rank[i] = tmp[i];
		}
	}

	vector<int> get_lcp() {
		
		for (int i = 0; i <= an; i++) rank[sa[i]] = i;
		for(int i=0;i<=an;++i){
			//cout<<rank[i]<<endl;
		}
		int h = 0;
		vector<int> lcp(an + 1);
		for (int i = 0; i < an; i++) {
			if(rank[i]<=0){
				continue;
			}
			int j = sa[rank[i] - 1];

			if (h > 0) h--;
			for (; j + h < an && i + h < an; h++) {
				if (S[j + h] != S[i + h]) break;
			}
			lcp[rank[i] - 1] = h;
		}
		return lcp;
	}
};

int main() {
	ios::sync_with_stdio(false);
	string st;cin>>st;
	//asuffix_array suf(st);
	vector<int>anss(st.size());
	int amin=1e9;
	for(int i=0;i<st.size();++i){
		int xx=st[i]-'a';
		anss[i]=(amin<xx);
		amin=min(amin,xx);
	}
	for(int i=0;i<st.size();++i){
		if(anss[i]==1)cout<<"Ann"<<endl;
		else cout<<"Mike"<<endl;
	}

	return 0;
}