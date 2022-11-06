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


struct Compress {
	map<int, int>mp;
	map<int, int>revmp;

	Compress(vector<int>vs) {
		sort(vs.begin(), vs.end());
		vs.erase(unique(vs.begin(),vs.end()),vs.end());
		for (int i = 0; i < vs.size(); ++i) {
			mp[vs[i]] = i;
			revmp[i] = vs[i];
		}
	}
	Compress(const set<int>&vs) {
		int num = 0;
		for (auto v : vs) {
			mp[v] = num;
			revmp[num] = v;
			num++;
		}
	}
};
using Graph=vector<vector<pair<int,int>>>;
vector<int>perms2;
int dfs(int now,const int from_id, Graph&g,vector<int>&used,vector<int>&nexts){
	bool  flag=false;
	int alast=from_id;
	while(!g[now].empty()){
		auto e=g[now].back();
		g[now].pop_back();
		if(e.second==from_id){
		}
		else{
			if(used[e.second]){
			}
			else{
				used[e.second]=true;
				if(!flag){
					{
						nexts[from_id]=e.second;
					}
					alast=dfs(e.first,e.second,g,used,nexts);
					flag=true;
				}else{
					//WHATS(now)
					//WHATS(from_id)
					int kk=nexts[from_id];
					nexts[from_id]=e.second;
					int last=dfs(e.first,e.second,g,used,nexts);
					nexts[last]=kk;
				}
			}
		}
	}
	perms2.push_back(from_id);

	return alast;
}
pair<int,vector<int>>oylar(Graph g,int M){
	vector<int>used(M);
	vector<int>odds;
	vector<int>nexts(M+1,-1);
	for(int i=0;i<g.size();++i){
		if(g[i].size()%2)odds.push_back(i);
	}
	if(odds.size()>=3)return make_pair(-1,vector<int>());
	else{
		int src;
		if(odds.empty()){
			src=0;
		}else{
			src=odds[0];
		}
		dfs(src,M,g,used,nexts);
		// vector<int>perms;
		// int anow=M;
		// while(true){
		// 	if(anow!=M)perms.push_back(anow);
		// 	if(nexts[anow]!=-1){
		// 		anow=nexts[anow];
		// 	}else{
		// 		break;
		// 	}
		// }
		perms2.pop_back();
		reverse(perms2.begin(),perms2.end());
		//WHATS(perms)
		//WHATS(perms2)
		return make_pair(src,perms2);
	}
}
// 1 6 4 7 8 8 7 8 7 4
const ll mod=1e9+7;
struct query{
	int l;
	int r;
	bool is_doll;
	int spaces;	
	ll cnt;
};
bool operator <(const query&l,const query&r){
	return l.l==r.l?(int(l.is_doll)>int(r.is_doll)):l.l>r.l;
}
int main() {
	ios::sync_with_stdio(false);
	int N;cin>>N;
	vector<pair<int,int>>vs;
	priority_queue<query>que;
	int max_l=-1;
	for(int i=0;i<N;++i){
		int r,l;cin>>r>>l;
		vs.emplace_back(l,r);
		max_l=max(max_l,l);
		que.push(query{l,r,true,-1,-1});
	}
	sort(vs.begin(),vs.end());
	pair<int,ll>max_p=make_pair(0,1);

	pair<ll,ll>answer(ll(-1e18),ll(-1e18));
	while(!que.empty()){
		auto q=que.top();
		bool is_doll=q.is_doll;
		int l=q.l;
		//WHATS(l)
		//WHATS(is_doll)
		//WHATS(max_p)
		que.pop();
		if(!is_doll){
			ll cnt=q.cnt;
			ll spaces=q.spaces;
			//WHATS(spaces)
			if(max_p.first==spaces){
				max_p.second+=cnt;
				if(max_p.second>=mod)max_p.second-=mod;
			}else if(max_p.first<spaces){
				max_p=make_pair(spaces,cnt);
			}
		}else{
			int r=q.r;
			if(r>max_l){
				ll nscore=max_p.first-l;
				ll aplus=max_p.second;
				if(answer.first<nscore){
					answer=make_pair(nscore,aplus);
				}else if(answer.first==nscore){
					answer.second+=aplus;
				}
			}
			else que.push(query{r,r,false,max_p.first+r-l,max_p.second});
		}
	}
	answer.second%=mod;
	cout<<answer.second<<endl;
	return 0;
}