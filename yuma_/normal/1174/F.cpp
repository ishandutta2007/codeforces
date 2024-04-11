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

vector<vector<int>>edges;
vector<int>depths;
vector<int>pas;
void dfs(int now,int from,int d=0){
	depths[now]=d;
	pas[now]=from;
	for(auto e:edges[now]){
		if(e==from){

		}else{
			dfs(e,now,d+1);
		}
	}
}
int dfs2(int now,int from,int d,const vector<int>&is_kouhos,vector<int>&chs){
	if(is_kouhos[now]){
		chs[now]++;
	}
	for(auto e:edges[now]){
		if(e==from){

		}else{
			chs[now]+=dfs2(e,now,d+1,is_kouhos,chs);
		}
	}
	return chs[now];
}
void dfs3(int now,int from,vector<int>&is_kouhos,int x,bool flag=false,const bool ok=false){
	if(x==now){
		flag=true;
	}
	if(!flag){
		if(ok)is_kouhos[now]=false;
	}else{
		if(!ok)is_kouhos[now]=false;
	}
	for(auto e:edges[now]){
		if(e==from){

		}else{
			dfs3(e,now,is_kouhos,x,flag,ok);
		}
	}
}
int say(int x,char type){
	x++;
	cout<<type<<' '<<x<<endl;
	if(type=='!'){
		return 0;
	}
	int ans;cin>>ans;
	return ans;
}
void solve(vector<int>&kouhos,int root,int fst_dis){
	//WHATS(kouhos)
	//WHATS(root)
	//WHATS(fst_dis)
	vector<int>chs(kouhos.size());
	dfs2(0,-1,0,kouhos,chs);
	int sum=std::accumulate(kouhos.begin(),kouhos.end(),0);
	
	if(sum==1){
		int ans=find(kouhos.begin(),kouhos.end(),1)-kouhos.begin();
		say(ans,'!');
		return;
	}
	int now=root;
	//cout<<'k'<<endl;
	while(true){
		int next=-1;
		for(auto e:edges[now]){
			if(e==pas[now])continue;
			else{
				if(chs[e]*2>=sum){
					next=e;
				}
			}
		}
		if(next==-1){
			break;
		}else{
			now=next;
		}
	}
	int next_dis;
	int next_root;
	if(now==root){
		int way=say(now,'s');
		way--;
		dfs3(0,-1,kouhos,way,false,true);
		next_dis=fst_dis-1;
		next_root=way;
	}else{
		int snd_dis=say(now,'d');
		if(snd_dis+depths[now]-depths[root]==fst_dis){
			dfs3(0,-1,kouhos,now,false,true);
			next_dis=snd_dis;
			next_root=now;
		}else{
			dfs3(0,-1,kouhos,now,false,false);
			next_dis=fst_dis;
			next_root=root;
		}
	}
	solve(kouhos,next_root,next_dis);
}
int main() {
	int N;cin>>N;
	edges.resize(N);
	depths.resize(N);
	pas.resize(N);
	for(int i=0;i<N-1;++i){
		int  u,v;cin>>u>>v;
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dfs(0,-1);
	int ad=say(0,'d');
	vector<int>kouhos(N);
	for(int i=0;i<N;++i){
		if(depths[i]==ad){
			kouhos[i]=true;
		}
	}
	
	vector<int>chs(N);
	solve(kouhos,0,ad);
	return 0;
}