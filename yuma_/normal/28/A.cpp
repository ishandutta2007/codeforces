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
int main() {
	ios::sync_with_stdio(false);
	int N,M;cin>>N>>M;
	vector<int>v;
	{
		vector<pair<int,int>>ps;
		for(int i=0;i<N;++i){
			int a,b;cin>>a>>b;
			ps.emplace_back(a,b);
		}
		for(int i=0;i<N;++i){
			auto ap(ps[i]);
			auto bp(ps[(i+1)%N]);
			if(ap.first==bp.first){
				v.push_back(abs(ap.second-bp.second));
			}else{
				v.push_back(abs(ap.first-bp.first));
			}
		}

	}
	//WHATS(v)
	vector<int>base_rods;
	for(int i=0;i<M;++i){
		int a;cin>>a;
		base_rods.emplace_back(a);
	}
	vector<int>answer;

	for(int s=0;s<2;++s){
		auto rods=base_rods;
		vector<int>nanswer(N,-2);
		bool ok=true;

		for(int i=0;i<N/2;++i){
			int len=v[(s+i*2)%N]+v[(s+i*2+1)%N];
			auto it=find(rods.begin(),rods.end(),len);
			if(it==rods.end()){
				ok=false;
			}else{
				nanswer[(s+i*2+1)%N]=it-rods.begin();
				*it=-1;
			}
		}
		if(ok){
			answer=nanswer;
		}

	}
	if(!answer.empty())cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	for(int i=0;i<answer.size();++i){
		cout<<answer[i]+1;
		if(i==answer.size()-1)cout<<endl;
		else cout<<' ';
	}
	return 0;
}