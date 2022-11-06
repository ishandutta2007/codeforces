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

pair<int,bool> get_c(const vector<vector<int>>&graph,int N){
	vector<int>comes(N);
	vector<int>colors(N,-1);
	bool ok=true;
	queue<int>que;
	int sum=0;
	for(int i=0;i<N;++i){
		if(!comes[i]){
			colors[i]=0;
			sum++;
			que.emplace(i);
			while(!que.empty()){
				int now=que.front();
				comes[now]=true;
				que.pop();
				for(auto e:graph[now]){
					if(!comes[e]){
						que.emplace(e);
						colors[e]=1^colors[now];
					}
					if(colors[e]==colors[now])ok=false;
				}
			}
		}
	}
	return make_pair(sum,ok);
}

ll int_pow(int a,int b){
	if(b==0)return 1;
	else return a*int_pow(a,b-1);
}
int main() {
	ios::sync_with_stdio(false);
	int N,M;cin>>N>>M;
	vector<vector<int>>edges(N);
	vector<ll>cnts(N);
	for(int i=0;i<M;++i){
		int u,v;cin>>u>>v;u--;v--;
		if(u>v)swap(u,v);
		edges[u].push_back(v);
		cnts[u]++;
		cnts[v]++;
	}
	ll answer=0;
	for(int i=0;i<N;++i){
		answer+=(cnts[i]-edges[i].size())*edges[i].size();
	}
	cout<<answer<<endl;
	int Q;cin>>Q;
	while(Q--){
		int x;cin>>x;
		x--;
		for(auto e:edges[x]){
			int i=e;
			answer-=(cnts[i]-edges[i].size())*edges[i].size();
			edges[i].push_back(x);
			answer+=(cnts[i]-edges[i].size())*edges[i].size();
		}
		answer-=(cnts[x]-edges[x].size())*edges[x].size();
		edges[x].clear();
		cout<<answer<<endl;
	}

	return 0;
}