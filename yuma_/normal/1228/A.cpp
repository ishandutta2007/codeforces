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
	
struct UnionFind {
	vector<int> data;
	UnionFind(int size) : data(size, -1) { }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) {
		return root(x) == root(y);
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	int size(int x) {
		return -data[root(x)];
	}
};

using ll=long long ;
vector<int>depths;
vector<vector<int>>edges;
UnionFind uf(1);
void dfs(int now,int d,vector<int>&astack){
	astack.emplace_back(now);
	depths[now]=d;
	for(auto e:edges[now]){
		if(depths[e]==-1){
			dfs(e,d+1,astack);
		}
	}
	for(auto e:edges[now]){
		if(depths[e]+1<depths[now]){
			for(int k=astack.size()-1;k>=depths[e]+1;--k){
				uf.unionSet(astack[k],astack[k-1]);
			}
		}
	}
	astack.pop_back();
}

int main() {
	ios::sync_with_stdio(false);
	int L,R;cin>>L>>R;
	int answer=-1;
	for(int x=L;x<=R;++x){
		string st=to_string(x);
		set<char >aset;
		for(auto c:st){
			aset.emplace(c);
		}
		if(aset.size()==st.size())answer=x;
	}
	cout<<answer<<endl;
	return 0;
}