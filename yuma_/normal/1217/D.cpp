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

#define WHATS(var)//cout<<__LINE__<<' '<<#var<<"="<<var<<endl;

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
struct po{
	int l;
	int r;
	int u;
	int v;
	int nx,ny;
	po(){
		l=0;
		r=0;
		u=0;v=0;
		nx=0;
		ny=0;
	}
	void upd(int x,int y){
		l=min(l,x);
		r=max(r,x);
		u=min(u,y);
		v=max(v,y);
		nx=x;
		ny=y;
	}
};
int to_num(string &ast){
	int num=0;
	for(int i=0;i<ast.size();++i){
		num*=2;
		if(ast[i]=='1')num++;
	}
	return  num;
}
int main() {

	ios::sync_with_stdio(false);
	int N;cin>>N;
	int M;cin>>M;
	vector<vector<int>>edges(N);
	vector<int>comes(N);
	vector<pair<int,int>>all_edges;
	for(int i=0;i<M;++i){
		int u,v;cin>>u>>v;
		u--;v--;
		comes[v]++;
		edges[u].push_back(v);
		all_edges.push_back(make_pair(u,v));
	}
	bool ok=false;
	{
		queue<int>que;
		for(int i=0;i<N;++i){
			if(!comes[i]){
				que.emplace(i);
			}
		}
		while(!que.empty()){
			int now=que.front();
			que.pop();
			for(auto e:edges[now]){
				comes[e]--;
				if(!comes[e]){
					que.emplace(e);
				}
			}
		}
		if(all_of(comes.begin(),comes.end(),[](const int a){return a==0;})){
			ok=true;
		}
	}
	vector<int>colors(M);
	int cnt=1;
	if(ok){
		colors=vector<int>(M,1);
	}else{
		for(int i=0;i<all_edges.size();++i){
			auto p=all_edges[i];
			if(p.first<p.second){
				colors[i]=2;
			}else{
				colors[i]=1;
			}
		}
		cnt=2;
	}
	cout<<cnt<<endl;
	for(int i=0;i<M;++i){
		cout<<colors[i]<<' ';
	}
	cout<<endl;
	
	

	return 0;
}