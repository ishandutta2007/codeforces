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

	
using ll = long long int;
int main() {
	ios::sync_with_stdio(false);
	int N;cin>>N;
	vector<int>v(N);
	for(int i=0;i<N;++i)cin>>v[i];
	vector<pair<int,int>>pluss,zeros,minuss;
	for(int i=0;i<N;++i){
		if(v[i]>0)pluss.emplace_back(v[i],i);
		else if(v[i]==0)zeros.emplace_back(v[i],i);
		else minuss.emplace_back(v[i],i);
	}
	sort(minuss.begin(),minuss.end());
	//WHATS(minuss)
	vector<int>rms(N);
	if(pluss.size()+(int(minuss.size())/2*2)==0){
		for(int i=1;i<zeros.size();++i){
			rms[zeros[i].second]=true;
		}
		if(minuss.size()%2==1){
			rms[minuss.back().second]=true;
		}
	}else{
		for(int i=0;i<zeros.size();++i){
			rms[zeros[i].second]=true;
		}
		if(minuss.size()%2==1){
			rms[minuss.back().second]=true;
		}
	}
	vector<int>as,bs;
	//WHATS(rms)
	for(int i=0;i<N;++i){
		if(!rms[i]){
			as.push_back(i);
		}else{
			bs.push_back(i);
		}
	}
	for(int i=0;i<as.size()-1;++i){
		cout<<1<<' '<<as[i]+1<<' '<<as[i+1]+1<<endl;
	}
	for(int i=0;i<int(bs.size())-1;++i){
		cout<<1<<' '<<bs[i]+1<< ' '<<bs[i+1]+1<<endl;
	}
	if(!bs.empty())cout<<2<<' '<<bs.back()+1<<endl;
	return 0;
}