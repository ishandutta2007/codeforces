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
int main() {
	ios::sync_with_stdio(false);
	int N;cin>>N;
	vector<pair<int,int>>ps(N-1);
	for(int i=0;i<N-1;++i){
		int a;cin>>a;
		ps[i].first=a;
	}
	for(int i=0;i<N-1;++i){
		int b;cin>>b;
		ps[i].second=b;
	}
	bool ok=true;
	vector<int>nums;
	for(int i=0;i<N-1;++i){
		if(ps[i].first>ps[i].second)ok=false;
		else{

		}
		nums.push_back(ps[i].first);
		nums.push_back(ps[i].second);
	}
		vector<int>anss;

	if(ok){

		Compress comp(nums);
		Graph g(comp.mp.size());
		int ii=0;
		//WHATS(nums)
		for(auto &p:ps){
			p.first=comp.mp[p.first];
			p.second=comp.mp[p.second];
			g[p.first].emplace_back(p.second,ii);
			g[p.second].emplace_back(p.first,ii++);
		}
		//if(N>=90000)return 0;

		auto perms=oylar(g,N-1);
		//if(N>=90000)return 0;

		if(perms.second.size()<N-1)ok=false;
		//WHATS(g)
		//WHATS(perms)
		anss.push_back(perms.first);
		for(int i=0;i<perms.second.size();++i){
			int id=perms.second[i];
			if(ps[id].first==anss.back()){
				anss.push_back(ps[id].second);

			}else{
				anss.push_back(ps[id].first);
			}
		}
		for(auto & ans:anss){
			ans=comp.revmp[ans];
		}
	}
	
	if(!ok){
		cout<<-1<<endl;
	}else{
		for(auto ans:anss){
			cout<<ans<<' ';
		}
		cout<<endl;
	}
	
	return 0;
}