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


using Value=int;
const Value ini =0;
// Value operator +(const Value&al,const Value&ar){
// 	return al+ar;
// }
Value connect(Value al,const Value ar){
	return al|ar;
}
Value dat[800001];
struct segtree {
	int N;

	segtree() {}
	segtree(int n):segtree(n,vector<Value>(n,ini)){

	}
	segtree(int n,vector<Value>v)  {
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
const int XX=20;
vector<int> solve(string st){
	int N=st.size();
	vector<int>rs(1<<XX,N+1);
	for(int l=0;l<N;++l){
		int num=0;
		for(int x=l;x<min(N,l+XX);++x){
			if(num&(1<<(st[x]-'a'))){
				break;
			}else{
				num|=(1<<st[x]-'a');
			}
			rs[num]=min(rs[num],x+1);
		}
	}
	return rs;
}

int main() {
	ios::sync_with_stdio(false);
	string st;cin>>st;
	vector<int>rs=solve(st);
	//WHATS(rs)
	vector<int>nums(1<<XX);
	for(int i=0;i<XX;++i){
		for(int j=0;j<(1<<XX);++j){
			if(j&(1<<i))nums[j]++;
		}
	}
	for(int j=0;j<(1<<XX);++j){
		if(rs[j]==st.size()+1){
			rs[j]=0;
		}else{
			rs[j]=nums[j];
		}
	}
	//WHATS(rs)
	for(int i=0;i<XX;++i){
		for(int j=0;j<(1<<XX);++j){
			if(j&(1<<i)){

			}else{
				rs[j^(1<<i)]=max(rs[j^(1<<i)],rs[j]);
			}
		}
	}
	int ans=0;
	for(int j=0;j<(1<<XX);++j){
		ans=max(ans,rs[j]+rs[(1<<(XX))-1-j]);
	}
	cout<<ans<<endl;
	return 0;
}