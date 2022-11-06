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
	int N,M;cin>>N>>M;
	vector<int>v(M+1);
	for(int i=0;i<N;++i){
		int l,r;cin>>l>>r;
		v[l-1]++;
		v[r]--;
	}
	for(int i=0;i<M;++i){
		v[i+1]+=v[i];
	}
	
	v.pop_back();
	//WHATS(v)
	vector<int>ls=solve(v);
	//WHATS(ls)
	
	reverse(v.begin(),v.end());
	vector<int>rs=solve(v);
	reverse(rs.begin(),rs.end());
//WHATS(rs)
	vector<int>answers(M,1);
	for(int i=0;i<M;++i){
		answers[i]=ls[i]+rs[i]-1;
	}
	cout<<*max_element(answers.begin(),answers.end())<<endl;
	//WHATS(answers)
	return 0;
}