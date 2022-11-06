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
	
	
using ll = long long int;
using Graph=vector<vector<int>>;
Graph graph;
vector<int>depths;
vector<int>cycles;
vector<int>froms;
int N;
void dfs(int now,int from,int d){
	depths[now]=d;
	froms[now]=from;
	for(auto e:graph[now]){
		if(e==from)continue;
		else{
			if(depths[e]){
				if(depths[e]<depths[now]){
					int xx=now;
					cycles[xx]=true;
					while(xx!=e){
						xx=froms[xx];
						cycles[xx]=true;
					}
				}else if(depths[e]>=depths[now]){

				}
			}else{
				dfs(e,now,d+1);
			}
			
		}
	}
}
vector<int>szs;
vector<pair<ll,ll>>dps;
void dfs2(int now,int from,int d=0){
	szs[now]=1;
	bool flag=false;
	ll max_plus=0;
	ll normal_sum=0;
	for(auto e:graph[now]){
		if(e==from||cycles[e])continue;
		else{
			dfs2(e,now,d+1);
			szs[now]+=szs[e];
			flag=true;
			normal_sum+=dps[e].first;
			max_plus=max(max_plus,dps[e].second+N-szs[e]);
		}
	}
	if(!flag){
		max_plus=N-1;
	}else{
		max_plus-=szs[now];
	}
	normal_sum+=szs[now];
	{
		dps[now].first=normal_sum;
		dps[now].second=max_plus;
	}
	
}
int main() 
{
	ios::sync_with_stdio(false);
	cin>>N;
	graph.resize(N);
	depths.resize(N);
	froms.resize(N);
	cycles.resize(N);
	froms.resize(N);
	szs.resize(N);
	dps.resize(N);
	for(int i=0;i<N;++i){
		int u,v;cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(0,-1,1);
	WHATS(cycles)

	vector<int>cycle_ids;
	for(int i=0;i<N;++i){
		if(cycles[i]){
			dfs2(i,-1);
			cycle_ids.push_back(i);
		}
	}
	WHATS(dps)

	vector<vector<ll>>memo(2,vector<ll>(cycle_ids.size()));
	for(int l=0;l<cycle_ids.size();++l){
		int c_id=cycle_ids[l];
		memo[1][l]=ll(cycle_ids.size()-1)*ll(szs[c_id]);
	}
	ll answer=0;
	for(auto c_id:cycle_ids)answer+=dps[c_id].first;
	WHATS(answer)
		WHATS(memo[1])

	for(int sz=2;sz<cycle_ids.size();++sz){
		int cur=sz&1;
		int tar=cur^1;
		for(int l=0;l<cycle_ids.size();++l){
			int r=(l+sz-1)%cycle_ids.size();
			int l_use=cycle_ids[l];
			int r_use=cycle_ids[(l+sz-1)>=cycle_ids.size()?l+sz-1-cycle_ids.size():l+sz-1];
			ll r_use_cost=memo[tar][l]+ll(cycle_ids.size()-sz)*ll(szs[r_use]);
			ll l_use_cost=memo[tar][(l+1)>=cycle_ids.size()?0:l+1]+ll(cycle_ids.size()-sz)*ll(szs[l_use]);

			memo[cur][l]=max(r_use_cost,l_use_cost);
		}
		WHATS(memo[cur])
	}
	WHATS(memo[1-cycle_ids.size()%2])
	ll aplus=0;
	for(int i=0;i<cycle_ids.size();++i){
		int c_id=cycle_ids[i];
		ll nanswer=dps[c_id].second-(N-szs[c_id])+memo[1-cycle_ids.size()%2][(i+1)%cycle_ids.size()];
		WHATS(aplus)
		aplus=max(aplus,nanswer);
	}
	cout<<answer+aplus<<endl;

	
	return 0;
}