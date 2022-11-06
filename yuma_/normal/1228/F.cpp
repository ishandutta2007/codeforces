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
void dfs(int now,int from,const vector<vector<int>>&graph,vector<int>&dists,int d){
	dists[now]=d;
	for(auto e:graph[now]){
		if(e!=from)dfs(e,now,graph,dists,d+1);
	}
}
vector<int>get_diamater(const vector<vector<int>>&graph){
	vector<int>dists(graph.size());
	dfs(0,-1,graph,dists,0);
	int k=max_element(dists.begin(),dists.end())-dists.begin();
	dfs(k,-1,graph,dists,0);
	int j=max_element(dists.begin(),dists.end())-dists.begin();

	vector<int>dias;
	int now=j;
	while(now!=k){
		dias.push_back(now);
		for(auto e:graph[now]){
			if(dists[e]==dists[now]-1){
				now=e;
				break;
			}
		}
	}
	dias.push_back(now);
	return dias;
}

pair<int,int> check(const vector<vector<int>>&graph,int now,int from){
	vector<int>nums;
	int place=-1;
	for(auto e:graph[now]){
		if(e==from)continue;
		else{
			auto p=check(graph,e,now);
			if(p.second!=-1){
				if(place==-1){
					place=p.second;
				}else{
					throw(false);
				}
			}
			nums.push_back(p.first);
		}
	}
	sort(nums.begin(),nums.end());
	int sz=-1;
	if(nums.empty())sz=0;
	else{
		{
			if(nums.size()==1&&nums[0]==0){
				if(place==-1){
					place=now;
				}else{
					throw(false);
				}
				sz=1;
			}
			else if(nums.size()==2&&nums[0]==nums[1])sz=nums[0]+1;
			else if(nums.size()==3&&nums[0]==nums[1]&&nums[1]+1==nums[2]){
				sz=nums[2]+1;
				if(place==-1){
					place=now;
				}else{
					throw(false);
				}
			}else{
				throw(false);
			}
		}
		
	}
	return make_pair(sz,place);
}

int main() {
	ios::sync_with_stdio(false);
	int N;cin>>N;
	vector<vector<int>>graph((1<<N)-1);
	for(int i=0;i<(1<<N)-3;++i){
		int u,v;cin>>u>>v;u--;v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	vector<int>dias=get_diamater(graph);
	vector<int>answers;
	//WHATS(dias)
	if(dias.size()%2){
		//WHATS(dias)
		int root=dias[dias.size()/2];
		bool ok=true;
		if(graph[root].size()!=2)ok=false;
		else{
			int ans=-1;
			for(int i=0;i<2;++i){
				try{
					auto p=check(graph,graph[root][i],root);
					//WHATS(p)
					if(p.second!=-1){
						if(ans==-1){
							ans=p.second;
						}else{
							throw(false);
						}
					}
				}catch(...){
					ok=false;
				}
			}
			if(ans==-1)ok=false;
			if(ok){
				answers.push_back(ans);
			}
		}
	}else{
		vector<int>roots{dias[dias.size()/2-1],dias[dias.size()/2]};
		//WHATS(dias)
		bool ok=true;
			
		for(int i=0;i<2;++i){
			try{
				auto p=check(graph,roots[i],roots[i^1]);
				if(p.second!=-1)throw(false);
			}catch(...){
				ok=false;
			}
		}
		
		if(ok){
			answers=roots;
		}
	}
	cout<<answers.size()<<endl;
	sort(answers.begin(),answers.end());
	for(auto a:answers)cout<<1+a<<' ';
	cout<<endl;
	return 0;
}