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
const int MAX_N=2e5;
vector<int>min_divs(MAX_N+1);
void init(){
	iota(min_divs.begin(),min_divs.end(),0);
	for(ll x=2;x<=MAX_N;++x){
		if(min_divs[x]==x){
			for(int y=x*x;y<=MAX_N;y+=x){
				if(min_divs[y]==y){
					min_divs[y]=x;
				}
			}
		}
	}
}

ll bfs(int start,const vector<vector<int>>&edges,vector<int>&oks){
	assert(oks[start]==true);

	int sum=0;
	queue<int>que;
	que.push(start);
	while(!que.empty()){
		int now=que.front();
		que.pop();
		oks[now]=false;
		sum++;
		for(auto e:edges[now]){
			if(oks[e])que.emplace(e);
		}
	}
	return sum;
}
int main() {
	ios::sync_with_stdio(false);
	int N;cin>>N;
	vector<int>v(N);
	for(int i=0;i<N;++i)cin>>v[i];
	vector<vector<int>>ids(MAX_N+1);

	for(int i=0;i<N;++i)ids[v[i]].push_back(i);
	vector<vector<int>>edges(N);

	for(int i=0;i<N-1;++i){
		int a,b;cin>>a>>b;
		a--;b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	vector<ll>anss(MAX_N+1);
	vector<int>oks(N);
	for(int num=1;num<=MAX_N;++num){
		vector<int>now_ids;
		for(int x=num;x<=MAX_N;x+=num){
			for(auto id:ids[x]){
				oks[id]=true;
				now_ids.push_back(id);
			}
		}
		ll nanswer=0;
		for(auto n_id:now_ids){
			if(oks[n_id]){
				ll sum=bfs(n_id,edges,oks);
				nanswer+=sum*(sum+1)/2;
			}
		}
		anss[num]=nanswer;
	}
	//WHATS(anss)
	for(int num=MAX_N;num>=1;--num){
		for(int x=2*num;x<=MAX_N;x+=num){
			anss[num]-=anss[x];
		}
		
	}
	for(int num=1;num<=MAX_N;++num){
		
		if(anss[num]){
			cout<<num<<' '<<anss[num]<<endl;
		}
	}
	return 0;
}