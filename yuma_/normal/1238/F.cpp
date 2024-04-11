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

int answer=0;
vector<vector<int>>edges;
vector<int>answers;
int dfs(int now,int from){
	vector<int>max_nums{0,0};
	for(auto e:edges[now]){
		if(e==from)continue;
		int num=dfs(e,now);
		max_nums.push_back(num);
	}
	sort(max_nums.begin(),max_nums.end(),greater<int>());
	int nanswer=1+max_nums[0]+max_nums[1]+max(0,int(edges[now].size())-2);
	answers[now]=nanswer;
	int ret=max_nums[0]+1;
	ret+=max(0,int(edges[now].size())-2);
	//WHATS(ret)
	//WHATS(now)
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	int Q;cin>>Q;
	while(Q--){
		int N;cin>>N;
		edges.clear();
		edges.resize(N);
		answers.clear();
		answers.resize(N);
		for(int i=0;i<N-1;++i){
			int u,v;cin>>u>>v;u--;v--;
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		for(int x=0;x<1;++x){
			answers.clear();
			answers.resize(N);
			dfs(x,-1);
			//WHATS(answers);

		}
		cout<<*max_element(answers.begin(),answers.end())<<endl;
	}
	return 0;
}