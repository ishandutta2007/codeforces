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

using ll =long long ;
ll mod;

void solve(vector<vector<int>>&cango){
	int tt=cango.size();
	for(int i=0;i<tt;++i){
		for(int j=0;j<tt;++j){
			for(int k=0;k<tt;++k){
				cango[j][k]|=cango[j][i]&cango[i][k];
			}
		}
	}
}
vector<int> dfs(int now,int N,vector<pair<int,int>>&edges){
	vector<int>av{now};
	if(now*2+1<N){
		auto v=dfs(now*2+1,N,edges);
		av.insert(av.end(),v.begin(),v.end());
	}
	if(now*2+2<N){
		auto v=dfs(now*2+2,N,edges);
		for(auto e:v){
			edges.push_back(make_pair(now,e));
		}
		av.insert(av.end(),v.begin(),v.end());
	}
	return av;
}

int ask(int x){
	cout<<x+1<<endl;
	fflush(stdout);
	string st;cin>>st;
	if(st=="Yes")return -1;
	else if(st=="No")return 0;
	else return 1;
}
int MAX_N=1000000;
vector<int>divs(MAX_N+1,-1);
void solve(){
	for(ll i=2;i<=MAX_N;++i){
		if(divs[i]==-1){
			divs[i]=i;

			for(ll j=i*i;j<=MAX_N;++j){
				divs[j]=i;
			}
		}
	}

}
int main() {
	ios::sync_with_stdio(false);
	int N;cin>>N;
	vector<int>v(N);
	for(int i=0;i<N;++i){
		cin>>v[i];
	}
	solve();
	int sum=accumulate(v.begin(),v.end(),0);
	vector<int>answer;
	if(sum==N*2||sum==N){
		answer=v;
	}else{
		answer.push_back(2);
		answer.push_back(1);
		int two=count(v.begin(),v.end(),2);
		for(int k=0;k<two-1;++k){
			answer.push_back(2);
		}
		for(int k=0;k<N-two-1;++k){
			answer.push_back(1);
		}
	}
	for(int i=0;i<N;++i){
		cout<<answer[i]<<' ';
	}
	cout<<endl;
	return 0;	
}