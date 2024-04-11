#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

//// < "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\a.txt" > "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\b.txt"

void dfs(vector<int>&depths,const  vector<vector<int>>&revedges,int dep,int now) {
	depths[now]=dep;
	for (auto re : revedges[now]) {
		dfs(depths,revedges,dep+1,re);
	}
}

int main() {
	int N;cin>>N;
	vector<vector<int>>edges;
	edges.resize(N);
	vector<vector<int>>revedges(N);
	vector<int>depths(N);
	for (int i = 0; i < N - 1; ++i) {
		int a;cin>>a;
		edges[i+1].push_back(a-1);
		revedges[a-1].push_back(i+1);
	}
	dfs(depths,revedges,0,0);

	map<int,int>mp;
	for (auto d : depths) {
		mp[d]++;
	}
	int ans=0;
	for (auto m : mp) {
		ans+=m.second%2;
	}
	cout<<ans<<endl;

	return 0;
}