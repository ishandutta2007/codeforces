#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
using namespace std;

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
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	int size(int x) {
		return -data[root(x)];
	}
};


int main() { 
	int N;cin>>N;
	string a,b;cin>>a>>b;
	UnionFind uf(26);
	for(int i=0;i<N;++i){
		uf.unionSet(a[i]-'a',b[i]-'a');
	}

	map<int,vector<int>>mp;
	for(int i=0;i<26;++i){
		mp[uf.root(i)].push_back(i);
	}

	vector<pair<int,int>>anss;
	for(auto it=mp.begin();it!=mp.end();it++){
		int sz=it->second.size();
		for(int i=0;i<sz-1;++i){
			anss.emplace_back(make_pair(it->second[i],it->second[i+1]));
		}
	}
	cout<<anss.size()<<endl;
	for(int i=0;i<anss.size();++i){
		cout<<char('a'+anss[i].first)<<" "<<char('a'+anss[i].second)<<endl;
	}
	return 0;

}