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
using ll =long long int;
ld dis(pair<int,int>a,pair<int,int>b){
	ld dx=a.first-b.first;
	ld dy=a.second-b.second;
	return sqrt(dx*dx+dy*dy);
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
struct segtree {
	int N;
	vector<Value>dat;
	segtree() {}
	
	segtree(int n,vector<Value>&v)  {
		N = 1;
		while (N < n) N *= 2;
		dat.resize(2*N);
		
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
int main() {
	
	ios::sync_with_stdio(false);
	int N,K;
	ll A,B;
	int Q;
	cin>>N>>K>>B>>A>>Q;
	vector<Value>vec(N,0);
	segtree seg1(N,vec);
	segtree seg2(N,vec);
	vector<ll>nums(N);
	while(Q--){
		int type;
		cin>>type;
		if(type==1){
			int day;
			cin>>day;
			day--;
			ll plus;cin>>plus;
			nums[day]+=plus;
			seg1.update(day,min(nums[day],A));
			seg2.update(day,min(nums[day],B));
		}else{
			int s;cin>>s;
		//	WHATS(nums)
			ll answer=seg1.query(0,s-1);
			//WHATS(answer)
			answer+=seg2.query(min(N,K+s-1),N);
			//WHATS(answer)
			cout<<answer<<endl;
		}
	}
	return 0;
}