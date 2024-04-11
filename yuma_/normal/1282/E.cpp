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
template<class T> ostream& operator <<(ostream &os, const map<T,T> &v){
	int i=0;
	for(auto it:v){
		if(i > 0){os << ' ';}
		os << it.first<<' '<<it.second;
		i++;
	} 
	return os;
}
using ll=long long ;
const ll mod=1e9+7;


int main() {
	int T;cin>>T;
	while(T--){
		int N;cin>>N;

		vector<vector<int>>v(N-2,vector<int>(3));

		map<pair<int,int>,vector<int>>mp;
		for(int i=0;i<N-2;++i){
			for(int j=0;j<3;++j){
				scanf("%d",&v[i][j]);
				v[i][j]--;
			}
			for(int j=0;j<3;++j){
				int a=v[i][j];
				int b=v[i][(j+1)%3];

				if(a>b)swap(a,b);

				mp[make_pair(a,b)].push_back(i);
			}
		}
		if(N==3){
			printf("1 2 3\n1\n");
			continue;
		}else{
			
		}
		vector<vector<int>>edges(N-2);
		vector<vector<int>>connects(N);
		//cout<<3<<endl;

		for(auto m:mp){
			//WHATS(m)
			if(m.second.size()==2){
				int u=m.second[0];
				int v=m.second[1];
				edges[u].push_back(v);
				edges[v].push_back(u);
			}else{
				connects[m.first.first].push_back(m.first.second);
				connects[m.first.second].push_back(m.first.first);
			}
		}
		//cout<<3<<endl;
		vector<int>answers1;
		{
			int from=-1;
			int now=0;
			while(true){
				//WHATS(now)
				answers1.push_back(now);

				int to;
				if(connects[now][0]==from){
					to=connects[now][1];
				}else{
					 to=connects[now][0];
				}

				from=now;
				now=to;
				if(!now)break;

			}
		}
		vector<int>answers2;

		vector<int>cnts(N-2);
		queue<int>que;
		for(int i=0;i<N-2;++i){
			cnts[i]=edges[i].size();
			if(cnts[i]==1){
				que.emplace(i);
			}
		}
		while(!que.empty()){
			auto now(que.front());
			que.pop();
			answers2.push_back(now);
			for(auto e:edges[now]){
				cnts[e]--;
				if(cnts[e]==1){
					que.emplace(e);
				}
			}
		}


		for(int i=0;i<N;++i){
			printf("%d ",answers1[i]+1);
		}
		printf("\n");
		for(int i=0;i<N-2;++i){
			printf("%d ",answers2[i]+1);
		}
		printf("\n");
	}
	return 0;
}