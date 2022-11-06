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
#pragma GCC optimize("Ofast")
#pragma GCC target("sse2")

#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;
using Graph=vector<vector<pair<int,int>>>;
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

struct aa{
	pair<int,int>p;
	int len;
	int l_len,r_len;
	void say(){
		WHATS(p)
		WHATS(len)
		WHATS(l_len)
		WHATS(r_len)
	}
};
using Value=aa;
const Value ini =aa{make_pair(0,0),0,0,0};
// Value operator +(const Value&al,const Value&ar){
// 	return al+ar;
// }
Value connect(Value al,const Value ar){
	Value ans=al;
	ans.len=al.len+ar.len;
	if(ans.p<ar.p){
		ans.p=make_pair(ar.p.first,ar.p.second+al.len);
	}
	if(al.r_len+ar.l_len>ans.p.first){
		ans.p=make_pair(al.r_len+ar.l_len,al.len-al.r_len);
	}
	ans.r_len=ar.r_len;
	if(ar.r_len==ar.len){
		ans.r_len=ar.r_len+al.r_len;
	}
	ans.l_len=al.l_len;
	if(al.l_len==al.len){
		ans.l_len=al.l_len+ar.l_len;
	}
	return ans;
}
Value dat[3200001];
struct segtree {
	int N;

	segtree() {}
	
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
		if (r <= a || b <= l) return ini;
		if (a <= l && r <= b) return dat[k];
		const int m = (l + r) / 2;
		return connect(query(a, b, k * 2 + 1, l, m),query(a, b, k * 2 + 2, m, r));
	}
};
segtree seg;
vector<ll>memo(1000000);
void init(){
	vector<vector<ll>>v(5,vector<ll>(1000000));
	v[0][0]=1;
	for(int x=0;x<4;++x){
		for(int i=1;i<999999;++i){
			v[x+1][i]=v[x+1][i-1]+v[x][i-1];
		}
	}
	memo=v[4];
	
}
ll solve(int l,int r){
	auto ans=seg.query(l,r);
	auto p=ans.p;
	int al=p.second;
	int alen=p.first;

	ll ret=0;
	if(alen==0){
		ret= 0;
	}else if(r-l==alen){
		ret=memo[r-l+3];
	}else{
		ll num=solve(l,l+al+alen-1)+solve(l+al+1,r)-memo[alen+1];
		ll x_l=al;
		ll x_r=(r-l)-(al+alen);

		num+=(x_l+1)*(x_r+1)*alen;
		
		ret= num;
	}
	//WHATS(l)
	//WHATS(r)
	//WHATS(ret)
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	init();
	for(int i=0;i<10;++i){
		//WHATS(memo[i])
	}
	int N;string st;cin>>N;cin>>st;
	vector<Value>v(N);
	for(int i=0;i<N;++i){
		if(st[i]=='0'){
			v[i]=aa{make_pair(0,0),1,0,0};
		}else{
			v[i]=aa{make_pair(0,1),1,1,1};
		}
	}
	
	seg=segtree(N,v);

	ll answer=solve(0,N);
	cout<<answer<<endl;
	//WHATS(solve(0,3))
	return 0;
}