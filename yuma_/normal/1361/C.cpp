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
#include<memory>

#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;
using ll = long long int;

//using Graph=vector<vector<pair<int,ll>>>;
	
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
//1. mask
	// 	a. i==0
	// 	for(int i=mask; i>0; i=(i-1)&mask) {
	// 	}

	// b. i==0
	// 	for(int i=mask; i>=0; i--) {
	// 		i&=mask;
	// 	}
// 2. mask

// mask

// 	for(int i=mask; i<(1<<n); i=(i+1)|mask) {
// 	}



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
    perms2.clear();
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
			for(int i=0;i<g.size();++i){
                if(!g[i].empty()){
                    src=i;
                    break;
                }
            }
		}else{
		return make_pair(src,perms2);

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
        //WHATS(perms2)
        //WHATS(used)
        //WHATS(nexts)
		return make_pair(src,perms2);
	}
}

vector<int>solve(const vector<vector<int>>&ps,int x){
    int tt=0;
    tt=(1<<x)-1;
    //WHATS(tt)
    Graph g(tt+1);
    int id=0;

    vector<int>memo;
    for(auto p:ps){
       // WHATS(p)
        int u=p[0]&tt;
        int v=p[1]&tt;

        g[u].push_back(make_pair(v,id));
        g[v].push_back(make_pair(u,id));
        id++;
    }
    //WHATS(g)
    auto answer=oylar(g,int(ps.size()));
    int s_node=answer.first;
    vector<int>use_ids=answer.second;
    vector<int>perms;
    if(s_node!=-1&&use_ids.size()==ps.size()){
        int now_node=s_node;
        for(int i=0;i<use_ids.size();++i){
            int using_id=use_ids[i];
            if((ps[using_id][0]&tt)==now_node){
                perms.push_back(using_id*2);
                perms.push_back(using_id*2+1);
                now_node=ps[using_id][1]&tt;
            }else{
                perms.push_back(using_id*2+1);
                perms.push_back(using_id*2);
                now_node=ps[using_id][0]&tt;
            }
        }
        
    }
    return perms;
    
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie();

    int N;cin>>N;
    vector<vector<int>>ps;
    for(int i=0;i<N;++i){
        int a,b;cin>>a>>b;
        ps.push_back(vector<int>{a,b});
    }
    for(int i=20;i>=0;--i){
        //WHATS(i)
        auto perms=solve(ps,i);
        if(!perms.empty()){
            cout<<i<<endl;
            for(auto pe:perms){
                cout<<pe+1<<' ';
            }
            cout<<endl;
            return 0;
        }
    }
	return 0;
}