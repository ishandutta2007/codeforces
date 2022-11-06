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
using ll=long long ;

struct Edge{
	int u;
	int v;
	ll cost;
};
vector<ll>solve2(const vector<vector<Edge>>&graph,int src){
	map<int,ll>mp;
	mp[src]=0;
	priority_queue<pair<ll,int>>que;
	que.emplace(0,src);
	while(!que.empty()){
		auto p(que.top());
		que.pop();
		int now=p.second;
		ll cost=-p.first;
		for(auto e:graph[now]){
			ll ncost=cost+e.cost;
			if(mp.find(e.v)==mp.end()||mp[e.v]>ncost){
				mp[e.v]=ncost;
				que.emplace(-ncost,e.v);
			}
		}	
	}
	vector<ll>v;
	for(auto m:mp){
		if(m.first>src){
			v.push_back(m.second);
		}
	}
	return v;
}
ll solve(int N,int K,const vector<Edge>all_edges){
	vector<vector<Edge>>graph(N);
	for(auto e:all_edges){
		graph[e.u].push_back(e);
		graph[e.v].push_back(Edge{e.v,e.u,e.cost});
	}
	vector<ll>v;
	for(int i=0;i<N;++i){
		auto nv=solve2(graph,i);
		v.insert(v.end(),nv.begin(),nv.end());
	}
	//WHATS(v);

	sort(v.begin(),v.end());
	return v[K-1];
}
int main() {
	
	ios::sync_with_stdio(false);
	int N,M,K;cin>>N>>M>>K;
	vector<Edge>all_edges;
	for(int i=0;i<M	;++i){
		int u,v;
		ll k;
		cin>>u>>v>>k;
		u--;v--;
		all_edges.push_back(Edge{u,v,k});
	}
	sort(all_edges.begin(),all_edges.end(),[](const Edge&l,const Edge&r){return l.cost<r.cost;});
	ll answer=solve(N,K,vector<Edge>(all_edges.begin(),all_edges.begin()+min(M,K)));
	cout<<answer<<endl;
	return 0;
}