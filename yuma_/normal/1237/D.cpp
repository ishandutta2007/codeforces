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

using Value=int;
const Value ini =1e9;
// Value operator +(const Value&al,const Value&ar){
// 	return al+ar;
// }
Value connect(Value al,const Value ar){
	return min(al,ar);
}
struct segtree {
	int N;
	Value dat[400001];

	segtree() {}
	
	segtree(int n)  {
		for(int i=0;i<400001;++i)dat[i]=ini;
		N = 1;
		while (N < n) N *= 2;
		
		for(int x=0;x<N;++x){
			{
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
struct query{
	int type;
	int num;
	int place;
};
bool operator<(const query&l,const query&r){
	return l.num==r.num?l.type<r.type:l.num<r.num;
}
int main() {
	ios::sync_with_stdio(false);
	int N;cin>>N;
	vector<int>v(N);
	for(int i=0;i<N;++i)cin>>v[i];
	vector<query>ps;
	for(int i=0;i<N;++i){
		v[i]*=2;
		ps.push_back(query{1,v[i],i});
		ps.push_back(query{0,v[i]/2,i});
	}
	sort(ps.begin(),ps.end());
	segtree seg(N);

	vector<int>anss(N);
	for(int i=0;i<2*N;++i){
		auto q(ps[i]);
		int place=q.place;
		if(q.type==0){
			int xx=seg.query(place+1,N);
			if(xx==1e9){
				xx=seg.query(0,place);
				if(xx!=1e9){
					xx+=N-place;
				}
			}else{
				xx-=place;
			}
			anss[place]=xx;
		}else{
			seg.update(place,place);
		}
	}
	vector<int>anss2(N);
	if(count(anss.begin(),anss.end(),1e9)==N){
		anss2=vector<int>(N,-1);
	}else{
		for(int i=0;i<N;++i){
			seg.update(i,anss[i]+i);
		}
		for(int i=0;i<N;++i){
			anss2[i]=seg.query(0,N)-i;
			seg.update(i,N+i+anss[i]);
		}
	}
	for(int i=0;i<N;++i)cout<<anss2[i]<<' ';
	return 0;
}