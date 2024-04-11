#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <functional>

using namespace std;

void solve(int test_ind){
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<pair<int, int> > lr(n+1);
	for (int i=1;i<=n;++i){
		scanf("%d%d", &lr[i].first, &lr[i].second);
	}

	vector<pair<char, int> > v;
	function<void(int)> dfs = [&](int u){
		if (u == 0) return;
		dfs(lr[u].first);
		v.emplace_back(s[u-1], u);
		dfs(lr[u].second);
	};

	dfs(1);

	vector<bool> okdup(n+1, false);
	for (int i=0;i<v.size()-1;){
		int i1 = i;
		for (int j=i+1;j<v.size();++j){
			if (v[j].first < v[i].first) {i = j;break;}
			if (v[i].first < v[j].first) {for (;i<j;++i) {okdup[v[i].second] = true;}break;}
		}
		if (i1 == i) break;
	}

	vector<char> v2;

	vector<int> okdup2(n+1, -1);
	function<void(int)> dfs3 = [&](int u){
		if (u == 0) return;
		if (okdup[u]) okdup2[u] = 0;
		dfs3(lr[u].first);
		if (okdup2[lr[u].first] != -1 && !okdup[u]) okdup2[u] = okdup2[lr[u].first] + 1;
		dfs3(lr[u].second);
	};
	dfs3(1);

	function<void(int, bool)> dfs2 = [&](int u, bool allowed){
		if (u == 0) return;
		bool dp = false;
		if (allowed && okdup2[u] != -1 && okdup2[u] < k) {dp=true;k--;}
		dfs2(lr[u].first, dp);
		v2.push_back(s[u-1]);
		if (dp) {
			v2.push_back(s[u-1]);
		}
		dfs2(lr[u].second, dp);
	};

	dfs2(1, true);

	for (char c: v2) printf("%c", c);
	cout << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}