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
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

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
using ll=long long ;

using Value=pair<int,vector<int>>;
const Value ini =make_pair(int(2e9)+10,vector<int>(9,int(1e9)+5));
// Value operator +(const Value&al,const Value&ar){
// 	return al+ar;
// }
Value connect(Value al,const Value ar){
	for(int i=0;i<9;++i){
		if(al.second[i]<1e9 &&ar.second[i]<1e9)al.first=min(al.first,al.second[i]+ar.second[i]);
		al.second[i]=min(al.second[i],ar.second[i]);
	}
	al.first=min(al.first,ar.first);
	return al;
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
pair<int,vector<int>>get_v(int st){
	auto v=ini;
	int lll=st;
	for(int j=0;j<9;++j){
		int num=st%10;
		st/=10;
		if(num){
			v.second[j]=lll;
		}
	}
	return v;
}
int main() {
	
	int N,Q;
	scanf("%d %d",&N,&Q);
	vector<Value>vs;
	for(int i=0;i<N;++i){
		int st;
		scanf("%d",&st);
		auto v=get_v(st);
		vs.push_back(v);
	}
	segtree seg(N,vs);

	while(Q--){
		int type;
		scanf("%d",&type);
		if(type==1){
			int x;
			int st;
			scanf("%d %d",&x ,&st);
			auto v=get_v(st);
			WHATS(v)
			seg.update(x-1,v);
		}else{
			int l,r;
			scanf("%d %d",&l,&r);
			l--;
			auto v=seg.query(l,r);
			ll amin=v.first;
			if(amin==2e9+10){
				amin=-1;
			}
			printf("%d\n",amin);
		}
	}
	return 0;
}