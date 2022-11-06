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


const int MAX_X=2220;

using ll=long long ;

struct Edge{
	int src;
	int dst;
	int id;
};
using Graph=vector<vector<Edge>>;
int main() {
	ios::sync_with_stdio(false);
	int N,M,K;cin>>N>>M>>K;
	Graph g(N);
	for(int i=0;i<M;++i){
		int u,v;cin>>u>>v;u--;v--;
		g[u].push_back(Edge{u,v,i});
		g[v].push_back(Edge{v,u,i});
	}
	vector<int>costs(N,10000000);
	costs[0]=0;
	queue<int>que;
	que.push(0);
	while(!que.empty()){
		int now=que.front();
		que.pop();
		for(auto e:g[now]){
			if(costs[e.dst]>costs[now]+1){
				costs[e.dst]=costs[now]+1;
				que.emplace(e.dst);
			}
		}
	}
	vector<vector<int>>tos(N);
	for(int s=0;s<N;++s){
		for(auto e:g[s]){
			if(costs[s]+1==costs[e.dst]){
				tos[e.dst].push_back(e.id);
			}
		}
	}
	ll total=1;
	for(int i=1;i<N;++i){
		total*=tos[i].size();
		if(total>=K)total=K;
	}
	cout<<total<<endl;
	for(int id=0;id<total;++id){
		string st(M,'0');
		int rest=id;
		for(int s=1;s<N;++s){
			int num=rest%(tos[s].size());
			st[tos[s][num]]='1';
			rest/=tos[s].size();
		}
		cout<<st<<endl;
	}
	return 0;
}