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
using ld = __float128;
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
	int N,M;cin>>M>>N;
	vector<ll>pluss(3*N);
	while(M--){
		int L;cin>>L;
		deque<pair<int,int>>que;
		que.emplace_back(0,N-L);
		map<int,int>mp;
		for(int i=0;i<=L;++i){
			if(!que.empty()&&que.front().second==i)que.pop_front();
			int x;
			if(i==L)x=0;
			else {
				cin>>x;
			}
			while(true){
				if(que.empty()|| que.back().first>x){
					que.emplace_back(x,i+N-L+1);
					if(i+N-L+1<0){
						cout<<'o'<<' '<<i+N-L+1<<endl;
					}
					break;
				}else{
					que.pop_back();
				}
			}
			int nans=que.front().first;
			mp[i]=nans;
		}

		while(true){
			int x=que.front().second;
			
			que.pop_front();
			if(!que.empty())mp[x]=que.front().first;
			else{
				break;
			}
		}
		for(auto it=mp.begin();it!=mp.end();++it){
		//WHATS(*it)
			if(it==mp.begin()){
				
				pluss[it->first]+=it->second;
			}else pluss[it->first]+=it->second-(prev(it)->second);
		}
	//	WHATS(pluss)
	}
	vector<ll>anss(N);
	for(int i=0;i<N;++i){
		if(i)anss[i]=anss[i-1]+pluss[i];
		else anss[i]=pluss[i];

		cout<<anss[i]<<' ';
	}
	cout<<endl;
	return 0;
}