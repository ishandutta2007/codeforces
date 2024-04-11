#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

void solve(int test_ind){
	int n, m;
	cin >> n >> m;
	vector<string> v(n);
	string s;
	for (int i=0;i<n;++i) cin>>v[i];
	cin >> s;
	unordered_map<string, pair<int, int> > mp2, mp3; // mp2[v[i][j:j+2]] = {i, j}, mp3[v[i][j:j+3]] = {i, j}
	for(int i=0;i<n;++i){
		for (int j=0;j<m-1;++j){
			mp2[v[i].substr(j, 2)] = {i, j};
		}
		for (int j=0;j<m-2;++j){
			mp3[v[i].substr(j, 3)] = {i, j};
		}
	}
	vector<pair<pair<int, int>, int> > prev(m+1, {{-1, -1}, -1});
	prev[0] = {{0, 0}, 0};
	for (int i=0;i<=m;++i){
		if (prev[i].second == -1) continue;
		if (i+2<=m)if (mp2.find(s.substr(i, 2)) != mp2.end()){
			prev[i+2] = {mp2[s.substr(i, 2)], 2};
		}
		if (i+3<=m)if (mp3.find(s.substr(i, 3)) != mp3.end()){
			prev[i+3] = {mp3[s.substr(i, 3)], 3};
		}
	}
	if (prev[m].second == -1){
		cout << "-1" << endl;
		return;
	}
	int end = m;
	vector<pair<pair<int, int>, int > > ans; // {{l, r}, i}
	while (end){
		ans.push_back({{prev[end].first.second, prev[end].first.second + prev[end].second}, prev[end].first.first});
		end -= prev[end].second;
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (auto p: ans){
		cout << p.first.first + 1 << " " << p.first.second << " " << p.second + 1 << endl;
	}
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}