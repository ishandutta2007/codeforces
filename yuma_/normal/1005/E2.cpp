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
//0-indexed
const int MAX_N=400001;

ll f[MAX_N];

void upd(int pos, ll x){
	for(; pos < MAX_N; pos |= pos + 1)
		f[pos] += x;
}

ll get(int pos){
	ll res = 0;
	for(; pos >= 0; pos = (pos & (pos + 1)) - 1)
		res += f[pos];
	return res;
}
ll solve(const vector<int>&v,int M){
	int N=v.size();
	int now=N+1;
	ll ans=0;
	for(int i=0;i<MAX_N;++i)f[i]=0;
	for(int i=0;i<v.size();++i){
		upd(now,1);

		if(v[i]>=M){
			now++;
		}else{
			now--;
		}
		ans+=get(now-1);

	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	int N,M;cin>>N>>M;
	vector<int>v(N);
	for(int i=0;i<N;++i)cin>>v[i];
	ll one=solve(v,M);
	ll two=solve(v,M+1);
//	WHATS(one)
//	WHATS(two)
	cout<<one-two<<endl;
	return 0;
}