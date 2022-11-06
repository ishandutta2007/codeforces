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
template<class T> ostream& operator <<(ostream &os, const map<T,T> &v){
	int i=0;
	for(auto it:v){
		if(i > 0){os << ' ';}
		os << it.first<<' '<<it.second;
		i++;
	} 
	return os;
}
using ll=long long ;
const ll mod=1e9+7;

ll powll(ll a,ll b){
	if(b==0)return 1;
	else{
		ll x=powll(a,b/2);
		x*=x;
		x%=mod;
		if(b%2)x*=a;
		x%=mod;
		return x;
	}
}
#include<random>
int gcd(int a,int b){
	if(a%b==0)return b;
	else return gcd(b,a%b);
}
bool check(vector<int>ls,vector<int>rs){
	set<pair<int,int>>aset;
	for(int i=0;i<ls.size();++i){
		for(int j=i+1;j<ls.size();++j){
			int dl=ls[i]-ls[j];
			int dr=rs[j]-rs[i];
			pair<int,int>ap=make_pair(dl/gcd(dl,dr),dr/gcd(dl,dr));
			if(aset.find(ap)!=aset.end())return false;
			else aset.emplace(ap);
			//cout<<ap.first<<' '<<ap.second<<endl;
		}
	}
	return true;
}

vector<int>bfs(int from,const vector<vector<int>>&edges){
	queue<int>que;
	que.emplace(from);
	vector<int>memo(edges.size(),100000000);
	memo[from]=-1;
	while(!que.empty()){
		int now=que.front();
		que.pop();
		for(auto e:edges[now]){
			if(memo[e]>memo[now]+1){
				memo[e]=memo[now]+1;
				que.emplace(e);
			}
		}
	}
	return memo;
}
int main() {
	
	ios::sync_with_stdio(false);
	cin.tie();
	int N;cin>>N;
	vector<int>v(N);
	vector<vector<int>>edges(N+2);
	for(int i=0;i<N;++i){
		cin>>v[i];
		if(i-v[i]>=0){
			edges[i-v[i]].push_back(i);
		}
		if(i+v[i]<N){
			edges[i+v[i]].push_back(i);
		}
		if(v[i]%2==0){
			edges[N].push_back(i);
		}else{
			edges[N+1].push_back(i);
		}
	}
	vector<int>odds=bfs(N,edges);
	vector<int>evens=bfs(N+1,edges);
	vector<int>anss(N);
	for(int i=0;i<N;++i){
		if(v[i]%2){
			anss[i]=odds[i];
		}else{
			anss[i]=evens[i];
		}
	}
	//WHATS(odds)
	//WHATS(evens)
	for(int i=0;i<N;++i){
		if(anss[i]>=10000000)anss[i]=-1;
		cout<<anss[i]<<' ';
	}
	cout<<endl;
	
	return 0;
}