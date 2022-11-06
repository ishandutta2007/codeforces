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
#pragma GCC optimize("Ofast")
#pragma GCC target("sse2")

#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;
using Graph=vector<vector<int>>;
using ll=long long;
	
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

struct UnionFindUndo {
  vector< int > data;
  stack< pair< int, int > > history;

  UnionFindUndo(int sz) {
    data.assign(sz, -1);
  }

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    history.emplace(x, data[x]);
    history.emplace(y, data[y]);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }


  int find(int k) {
    if(data[k] < 0) return (k);
    return (find(data[k]));
  }

  int size(int k) {
    return (-data[find(k)]);
  }

  void undo() {
    data[history.top().first] = history.top().second;
    history.pop();
    data[history.top().first] = history.top().second;
    history.pop();
  }

  void snapshot() {
    while(history.size()) history.pop();
  }

	//undo all
  void rollback() {
    while(history.size()) undo();
  }
};

const int MAX_N=18;
vector<vector<pair<int,int>>>node((1<<(MAX_N+1))-1);

void dfs(int id,int l,int r,int a,int b,pair<int,int>p){
	if(r<=a||b<=l)return;
	if(a<=l&&r<=b){
		node[id].push_back(p);
	}else{
		int m((l+r)>>1);
		dfs(id*2+1,l,m,a,b,p);
		dfs(id*2+2,m,r,a,b,p);
	}
}
UnionFindUndo uf(1<<MAX_N);
vector<int>anss(1<<MAX_N);
void solve(int id,int l,int r,bool ok){
	//WHATS(id)
	//WHATS(l)
	/////WHATS(r)
	//WHATS(ok)
	//auto data1=uf.data;
	int cnt=0;
	for(auto p:node[id]){
		if(uf.find(p.first)==uf.find(p.second)){
			ok=false;
		}
		if(uf.unite(p.first,p.second+(1<<(MAX_N-1))))cnt+=0;
		if(uf.unite(p.second,p.first+(1<<(MAX_N-1))))cnt+=0;
		cnt+=2;
	}
	if(l+1==r){
		anss[id-((1<<MAX_N)-1)]=ok;
	}else{
		int m((l+r)>>1);
		solve(id*2+1,l,m,ok);
		solve(id*2+2,m,r,ok);
	}
	//WHATS(cnt)
	//WHATS(uf.data)
	while(cnt){
		cnt--;
		uf.undo();
	}
	//WHATS(data1)
	//WHATS(uf.data)
	//assert(data1==uf.data);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie();

	int N,Q;cin>>N>>Q;
	map<pair<int,int>,vector<int>>mp;
	for(int i=0;i<Q;++i){
		int u,v;cin>>u>>v;
		u--;v--;
		mp[make_pair(u,v)].push_back(i);
	}
	for(auto m:mp){
		auto v(m.second);
		if(v.size()%2==1){
			v.push_back(Q);
		}
		for(int i=0;i<v.size();i+=2){
			int l=v[i];
			int r=v[i+1];
			dfs(0,0,1<<MAX_N,l,r,m.first);
		}
	}
	//WHATS(N)
	//WHATS(node)
	solve(0,0,1<<MAX_N,true);
	for(int i=0;i<Q;++i){
		if(anss[i])cout<<"YES"<<'\n';
		else cout<<"NO"<<'\n';
	}
	
	return 0;
}