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
ll solve(vector<ll>v){
	ll answer=0;
	sort(v.begin(),v.end());
	for(int i=0;i<3;++i)answer+=v[i]*v[i];
	answer+=v[0]*7;
	return answer;
}

struct player{
	int id;
	ld power;
	ld per;

};
int N,K;
vector<vector<int>>graph;
vector<int>costs;

vector<int> dfs(int now,int from){
	vector<int>answers(K+1);
	answers[0]=costs[now];
	for(auto e:graph[now]){
		if(e==from)continue;
		else{
			auto v=dfs(e,now);
			vector<int>nanswers(K+1);
			for(int i=0;i<=K;++i){
				for(int j=K-i;j<=K;++j){
					nanswers[min(i,j+1)]=max(nanswers[min(i,j+1)],answers[i]+v[j]);
				}
			}
			answers=nanswers;
		}
	}
	//WHATS(now)
	//WHATS(answers)
	return answers;
}

int main() {
	ios::sync_with_stdio(false);
	cin>>N>>K;
	graph.resize(N);
	costs.resize(N);
	for(int i=0;i<N;++i)cin>>costs[i];
	for(int i=0;i<N-1;++i){
		int u,v;cin>>u>>v;u--;v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int answer=0;
	vector<int>answers=dfs(0,-1);
	//WHATS(answers);
	cout<<*max_element(answers.begin(),answers.end())<<endl;
	return 0;
}