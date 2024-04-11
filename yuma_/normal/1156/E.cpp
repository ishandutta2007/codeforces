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
template<class T> ostream& operator <<(ostream &os, const map<T,T> &v){
	int i=0;
	for(auto it:v){
		if(i > 0){os << ' ';}
		os << it.first<<' '<<it.second;
		i++;
	} 
	return os;
}
using ll=long long ;

using Value=int;
const Value ini =-1;
// Value operator +(const Value&al,const Value&ar){
// 	return al+ar;
// }
Value connect(Value al,const Value ar){
	return max(al,ar);
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

	
};
vector<int>v,places;
ll answer=0;
void solve(int l,int r,segtree&seg){
	if(l+1>=r)return ;
	else{
		int ma_nu=seg.query(l,r);
		int ma_pl=places[ma_nu];
		//WHATS(ma_nu)

		if(r-ma_pl<ma_pl-l){
			for(int x=ma_pl+1;x<r;++x){
				int need=ma_nu-v[x];
				if(need>0){
					if(l<=places[need]&&places[need]<ma_pl){
						//cout<<need<<' '<<ma_nu<<' '<<v[x]<<endl;
						answer++;
					}
				}
			}
		}else{
			for(int x=l;x<ma_pl;++x){
				int need=ma_nu-v[x];
				if(need>0){
					if(ma_pl<places[need]&&places[need]<r){
						//cout<<v[x]<<' '<<ma_nu<<' '<<need<<endl;

						answer++;
					}
				}
			}
		}
		solve(l,ma_pl,seg);
		solve(ma_pl+1,r,seg);
	}
}
int main() {
	ios::sync_with_stdio(false);
	int N;cin>>N;
	v.resize(N),places.resize(N+1);
	for(int i=0;i<N;++i){
		cin>>v[i];
		places[v[i]]=i;
	}
	segtree seg(N,v);
	solve(0,N,seg);

	cout<<answer<<endl;

	return 0;
}