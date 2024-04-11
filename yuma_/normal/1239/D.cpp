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
using ll =unsigned long long ;	

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


pair<int,int> ad(pair<int,int>a,int b){
	if(b){
		return make_pair(max(1+a.second,a.first),1+a.second);
	}else{
		return make_pair(a.first+1,a.second);
	}
}
using Graph=vector<vector<int>>;


typedef int Weight;
struct Edge {
	int src, dst;
	Weight weight;
	Edge(int src, int dst, Weight weight) :
		src(src), dst(dst), weight(weight) { }
};
struct Dscc {
public:

	//belongs,newedges
	pair<vector<vector<int>>, vector<vector<int>>>get(const vector<vector<int>>&edges) {
		nums.resize(edges.size());
		fill(nums.begin(), nums.end(), -1);
		vector<vector<int>>revedges(edges.size());
		for (int i = 0; i < edges.size(); ++i) {
			for (auto j : edges[i]) {
				revedges[j].push_back(i);
			}
		}
		int num = 0;
		for (int i = 0; i < edges.size(); ++i) {
			dfs(i, num, edges);
		}
		vector<int>big(nums.size());
		for (int i = 0; i < nums.size(); ++i) {
			big[nums[i]] = i;
		}
		reverse(big.begin(), big.end());
		unis.resize(edges.size());
		fill(unis.begin(), unis.end(), -1);
		num = 0;
		for (int i = 0; i < big.size(); ++i) {

			dfs2(big[i], num, revedges);
			num++;
		}
		vector<int>nums;
		for (int i = 0; i < unis.size(); ++i) {
			nums.push_back(unis[i]);
		}
		sort(nums.begin(), nums.end());
		nums.erase(unique(nums.begin(), nums.end()), nums.end());


		map<int, int>mp;
		for (int i = 0; i < nums.size(); ++i) {
			mp[nums[i]] = i;
		}
		for (int i = 0; i < unis.size(); ++i) {
			unis[i] = mp[unis[i]];
		}

		vector<vector<int>>belongs(nums.size());
		for (int i = 0; i < unis.size(); ++i) {
			belongs[unis[i]].push_back(i);
		}
		vector<vector<int>>newedges(nums.size());
		for (int i = 0; i < edges.size(); ++i) {
			for (auto j : edges[i]) {
				if (unis[i] != unis[j]) {
					newedges[unis[i]].push_back(unis[j]);
				}
			}
		}
		return make_pair(belongs, newedges);
	}


private:
	vector<int>nums;
	vector<int>unis;

	void dfs(const int id, int &num, const vector<vector<int>>&edges) {
		if (nums[id] != -1)return;
		else {
			nums[id] = -2;
			for (auto i : edges[id]) {
				dfs(i, num, edges);
			}
		}
		nums[id] = num++;
		return;
	}
	void dfs2(const int id, const int &num, const vector<vector<int>>&edges) {
		if (unis[id] != -1)return;
		else {
			unis[id] = -2;
			for (auto i : edges[id])
				dfs2(i, num, edges);
		}
		unis[id] = num;
		return;
	}
	void dfs(const int id, int &num, const vector<vector<Edge>>&edges) {
		if (nums[id] != -1)return;
		else {
			nums[id] = -2;
			for (auto i : edges[id]) {
				dfs(i.dst, num, edges);
			}
		}
		nums[id] = num++;
		return;
	}
	void dfs2(const int id, const int &num, const vector<vector<Edge>>&edges) {
		if (unis[id] != -1)return;
		else {
			unis[id] = -2;
			for (auto i : edges[id]) {
				dfs2(i.dst, num, edges);
			}
		}
		unis[id] = num;
		return;
	}

}dscc;
int main() {
	ios::sync_with_stdio(false);
	int Q;cin>>Q;
	while(Q--){
		int N,K;cin>>N>>K;
		Graph g(N);
		for(int i=0;i<K;++i){
			int u,v;cin>>u>>v;u--;v--;
			if(u==v)continue;
			else{
				g[u].push_back(v);
			}
		}
		auto p=dscc.get(g);
		//aWHATS(p)
		if(p.first.size()==1){
			cout<<"No"<<endl;
		}else{
			cout<<"Yes"<<endl;
			auto ng=p.second;
			vector<int>humans(N,true);
			for(int i=0;i<ng.size();++i){
				if(ng[i].size()==0){
					for(auto x:p.first[i]){
						humans[x]=false;
					}
					break;
				}
			}
			vector<int>aa,bb;
			for(int i=0;i<N;++i){
				if(humans[i])aa.push_back(i+1);
				else bb.push_back(i+1);
			}
			swap(aa,bb);
			cout<<aa.size()<<' '<<bb.size()<<endl;
			for(auto x:aa)cout<<x<<' ';
			cout<<endl;
			for(auto x:bb)cout<<x<<' ';
			cout<<endl;
		}
	}
	return 0;	
}