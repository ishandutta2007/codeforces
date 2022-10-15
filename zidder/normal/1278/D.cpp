#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void dfs(int v, vector<vector<int> > &g, vector<bool>& vis){
	vis[v] = true;
	for(int u:g[v]){
		if (vis[u])
			continue;
		dfs(u, g, vis);
	}
}
void solve(int test_ind){
	int n;
	cin >> n;
	vector<pair<int, int> > seg;
	for(int i=0;i<n;++i){
		int x, y;
		cin >> x >> y;
		seg.emplace_back(x, y);
	}
	sort(seg.begin(), seg.end());
	int cnt = 0;
	vector<vector<int> > g(n);
	set<pair<int, int> > ends;
	for(int i=0;i<n;++i){
		int x=seg[i].first, y=seg[i].second;
		if (!ends.empty()){
		auto it = ends.lower_bound(make_pair(y, 0));
		while(it!=ends.begin()){
			it--;
			int xx = it->second;
			if (it->first < x)
				break;
			g[i].push_back(xx);
			g[xx].push_back(i);
			cnt++;
			if (cnt >= n){
				cout << "NO" << endl;
				return;
			}
		}}
		ends.emplace(y, i);
	}
	vector<bool> visited(n, false);
	dfs(0, g, visited);
	int sm = 0;
	for(int i =0;i<n;++i)
		sm += visited[i];
	if(sm == n){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}