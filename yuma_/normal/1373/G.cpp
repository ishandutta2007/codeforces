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
#include<memory>

#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;
using Graph=vector<vector<int>>;
using ll=long long;
	
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
//1. mask
	// 	a. i==0
	// 	for(int i=mask; i>0; i=(i-1)&mask) {
	// 	}

	// b. i==0
	// 	for(int i=mask; i>=0; i--) {
	// 		i&=mask;
	// 	}
// 2. mask

// mask

// 	for(int i=mask; i<(1<<n); i=(i+1)|mask) {
// 	}

	
using Value=pair<int,int>;
const Value ini =make_pair(-1,-1);
// Value operator +(const Value&al,const Value&ar){
// 	return al+ar;
// }
Value connect(Value al,const Value ar){
	if(ar.first==-1)return al;
    if(al.first==-1)return ar;
    if(al.first+al.second<=ar.first){
        return make_pair(ar.first-al.second,al.second+ar.second);
    }else{
        return make_pair(al.first,al.second+ar.second);
    }
}
Value dat[4000001];
struct segtree {
	int N;

	segtree() {}
	
	segtree(int n)  {
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
		if (r <= a || b <= l) return ini;
		if (a <= l && r <= b) return dat[k];
		const int m = (l + r) / 2;
		return connect(query(a, b, k * 2 + 1, l, m),query(a, b, k * 2 + 2, m, r));
	}

	
};

int main() {
    ios::sync_with_stdio(false);
	cin.tie();
	int N,K,M;cin>>N>>K>>M;
    set<pair<int,int>>aset;
    segtree seg(1e6);
    vector<int>cnts(1e6);
    for(int i=0;i<M;++i){
        int x,y;cin>>x>>y;
        int po_y=y+abs(x-K);

        if(aset.find(make_pair(x,y))==aset.end()){
            aset.emplace(make_pair(x,y));
            cnts[po_y]++;
            seg.update(po_y,make_pair(po_y,cnts[po_y]));

        }else{
            aset.erase(make_pair(x,y));
            cnts[po_y]--;
            if(cnts[po_y]==0){
                seg.update(po_y,make_pair(-1,-1));
            }else{
                seg.update(po_y,make_pair(po_y,cnts[po_y]));
            }
        }
        auto pp=seg.query(0,int(1e6));
        int needh=pp.first+pp.second-1;
        cout<<max(0,needh-N)<<endl;
    }
	return 0;
}