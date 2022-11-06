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

pair<int,bool> get_c(const vector<vector<int>>&graph,int N){
	vector<int>comes(N);
	vector<int>colors(N,-1);
	bool ok=true;
	queue<int>que;
	int sum=0;
	for(int i=0;i<N;++i){
		if(!comes[i]){
			colors[i]=0;
			sum++;
			que.emplace(i);
			while(!que.empty()){
				int now=que.front();
				comes[now]=true;
				que.pop();
				for(auto e:graph[now]){
					if(!comes[e]){
						que.emplace(e);
						colors[e]=1^colors[now];
					}
					if(colors[e]==colors[now])ok=false;
				}
			}
		}
	}
	return make_pair(sum,ok);
}

ll int_pow(int a,int b){
	if(b==0)return 1;
	else return a*int_pow(a,b-1);
}
int main() {
	ios::sync_with_stdio(false);
	int N,M;cin>>N>>M;
	vector<vector<int>>edges(N);
	for(int i=0;i<M;++i){
		int u,v;cin>>u>>v;
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	auto p=get_c(edges,N);
	int C=p.first;
	bool b_ok=p.second;
	int isolated_v_cnt=0;
	for(int i=0;i<N;++i){
		if(edges[i].empty())isolated_v_cnt++;
	}
	vector<vector<vector<ll>>>cnts(2,vector<vector<ll>>(2,vector<ll>(2)));
	cnts[1][0][0]=cnts[0][0][1]=int_pow(2,isolated_v_cnt);
	cnts[0][1][0]=b_ok?int_pow(2,C):0;
	cnts[1][1][1]=int_pow(2,N);
	cnts[1][0][1]=int_pow(2,C);
	
	{
		int K=N/2;
		vector<int>yys(1ll<<(N-K));
		for(int xx=0;xx<(1ll<<K);++xx){
			bool ok=true;
			vector<int>uses(K);
			for(int i=0;i<K;++i){
				uses[i]=(xx&(1ll<<i))!=0;
			}
			int yy=0;
			for(int i=0;i<K;++i){
				for(auto e:edges[i]){
					if(uses[i]){
						if(e<K){
							if(uses[i]&&uses[e])ok=false;
						}else{
							yy|=(1ll<<(e-K));
						}
					}
					
				}
			}
			if(ok){
				yys[yy^((1ll<<(N-K))-1)]++;
			}else{
			}
		}
		for(int i=0;i<(N-K);++i){
			for(int x=0;x<(1ll<<(N-K));++x){
				if((x&(1ll<<i))!=0){
					yys[x^(1ll<<i)]+=yys[x];
				}
			}
		}
		ll answer=0;
		for(int yy=0;yy<(1ll<<(N-K));++yy){
			bool ok=true;
			vector<int>uses(N-K);
			for(int i=0;i<N-K;++i){
				uses[i]=(yy&(1ll<<i))!=0;
			}
			
			for(int i=0;i<N-K;++i){
				for(auto e:edges[K+i]){
					
					if(e>=K){
						if(uses[i]&&uses[e-K])ok=false;
					}else{
					}
				}
			}
			if(ok){
				answer+=yys[yy];
			}
		}
		cnts[1][1][0]=cnts[0][1][1]=answer;
	}
	if(!M)cnts[0][0][0]=(1ll<<N);
	ll answer=0;
	answer=cnts[1][1][1]-cnts[1][1][0]-cnts[1][0][1]-cnts[0][1][1]+cnts[1][0][0]+cnts[0][1][0]+cnts[0][0][1]-cnts[0][0][0];
	cout<<answer<<endl;

	return 0;
}