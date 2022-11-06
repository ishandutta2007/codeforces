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
	int T;cin>>T;
	while(T--){
		int N;cin>>N;
		int id=1;
		vector<int>anss(N,-1);
		stack<pair<int,int>>sta;
		vector<vector<int>>edges(N);
		for(int i=0;i<N;++i){
			int ne;cin>>ne;
			while(!sta.empty()&&sta.top().second==i){
				sta.pop();
			}
			if(!sta.empty()){
				edges[i].push_back(sta.top().first);
			}
			if(ne!=-1){
				ne--;
				if(ne!=N)edges[i].push_back(ne);
				if(!sta.empty()){
					if(sta.top().second>ne)edges[ne].push_back(sta.top().first);
				}
				sta.push(make_pair(i,ne));
			}
		}
		vector<int>comes(N);
		for(int i=0;i<N;++i){
			for(auto e:edges[i]){
				comes[e]++;
			}
		}
		queue<int>que;
		for(int i=0;i<N;++i){
			if(comes[i]==0){
				que.push(i);
			}
		}
		while(!que.empty()){
			int now=que.front();
			anss[now]=id++;
			que.pop();
			for(auto e:edges[now]){
				comes[e]--;
				if(comes[e]==0){
					que.push(e);
				}
			}
		}
		if(find(anss.begin(),anss.end(),-1)!=anss.end()){
			cout<<-1<<endl;
		}else{
			for(auto ans:anss)cout<<ans<<' ';
			cout<<endl;
		}

	}

	return 0;
}