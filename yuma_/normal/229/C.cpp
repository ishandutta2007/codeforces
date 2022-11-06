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



vector<int>solve(vector<int>v){
	vector<int>nums(1000000,10000000);
	vector<int>anss(v.size());
	nums[0]=0;
	//WHATS(nums)
	for(int i=0;i<v.size();++i){
		auto it=upper_bound(nums.begin(),nums.end(),v[i]);
		anss[i]=it-nums.begin();
		*it=v[i];
		//WHATS(nums)
	}
	return anss;
}
int main() {
	ios::sync_with_stdio(false);
	
	ll N,M;cin>>N>>M;
	vector<ll>sums(N);
	for(int i=0;i<M;++i){
		int u,v;cin>>u>>v;
		u--;v--;
		sums[u]++;
		sums[v]++;
	}
	ll answer=N*(N-1)*(N-2)/6;
	answer-=M*(N-2);
	for(int i=0;i<N;++i){
		answer+=sums[i]*(sums[i]-1)/2;
	}
	cout<<answer<<endl;
	return 0;
}