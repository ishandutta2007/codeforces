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
int froms[500][500][2];
struct sta{
	int a;
	int b;
	int c;
};
int main() {
	
	ios::sync_with_stdio(false);
	int N,M;cin>>N>>M;
	vector<vector<int>>graph(N);
	for(int i=0;i<M;++i){
		int u,v;cin>>u>>v;u--;v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for(int i=0;i<500;++i){
		for(int j=0;j<500;++j){
			for(int k=0;k<2;++k){
				froms[i][j][k]=-1;
			}
		}
	}
	queue<sta>que;
	que.push(sta{0,N-1,0});
	bool ok=false;
	while(!que.empty()){
		auto asta(que.front());
		// WHATS(asta.a)
		// WHATS(asta.b)
		// WHATS(asta.c)
		que.pop();
		if(asta.a==N-1&&asta.b==0&&asta.c==0){
			ok=true;
			break;
		}

		if(!asta.c){
			for(auto e:graph[asta.a]){
				if(froms[e][asta.b][1]==-1){
					froms[e][asta.b][1]=asta.a;
					que.push(sta{e,asta.b,1});
				}
			}
		}else{
			for(auto e:graph[asta.b]){
				if(e==asta.a)continue;
				if(froms[asta.a][e][0]==-1){
					froms[asta.a][e][0]=asta.b;
					que.push(sta{asta.a,e,0});
				}
			}
		}
	}
	if(ok){
		vector<int>answer;
		int now_a=N-1;
		int now_b=0;
		int now_c=0;
		answer.push_back(0);
		answer.push_back(N-1);
		while(now_a!=0 || now_b!=N-1 || now_c!=0){
			if(now_c==0){
				now_b=froms[now_a][now_b][now_c];
				answer.push_back(now_b);
				now_c=1;
			}else{
				now_a=froms[now_a][now_b][now_c];
				answer.push_back(now_a);
				now_c=0;
			}
		}
		//WHATS(answer)
		cout<<answer.size()/2-1<<endl;
		for(int i=0;i<answer.size()/2;++i){
			cout<<1+answer[answer.size()-1-2*i]<<' ';
		}
		cout<<endl;
		for(int i=0;i<answer.size()/2;++i){
			cout<<1+answer[answer.size()-2-2*i]<<' ';
		}
	}else{
		cout<<-1<<endl;
	}

	return 0;
}