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
struct Node{
	vector<shared_ptr<Node>>tos;
	shared_ptr<Node>aback;
	ll sum=0;
	int place;
	Node():tos(26,nullptr),aback(nullptr){
		
	}
};
bool check(vector<int>needs,int day,const vector<vector<int>>&sales){
	const int N=sales.size();
	vector<vector<int>>last_days(day);
	for(int i=0;i<N;++i){
		auto it=upper_bound(sales[i].begin(),sales[i].end(),day-1);
		if(it==sales[i].begin()){
		}else{
			
			last_days[*prev(it)].push_back(i);
		}
	}
	int rest=0;
	int sum=2*accumulate(needs.begin(),needs.end(),0);
	for(int i=0;i<day;++i){
		rest++;
		for(auto id:last_days[i]){
			int use=min(rest,needs[id]);
			rest-=use;
			needs[id]-=use;
			sum-=2*use;
		}
		if(rest>=sum)return true;
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	int N,M;cin>>N>>M;
	vector<int>needs(N);
	for(int i=0;i<N;++i)cin>>needs[i];
	vector<vector<int>>sales(N);
	for(int i=0;i<M;++i){
		int d,t;cin>>d>>t;
		d--;t--;
		sales[t].push_back(d);
	}
	for(auto&sale:sales){
		sort(sale.begin(),sale.end());
	}
	int ng=0;
	int ok=400000;
	while(ng+1!=ok){
		int amid((ng+ok)/2);
		if(check(needs,amid,sales))ok=amid;
		else ng=amid;
	}
	cout<<ok<<endl;

	return 0;
}