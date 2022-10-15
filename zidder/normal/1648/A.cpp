#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, m;
	cin >> n >> m;
	map<int, vector<int> > row, col;
	for (int i=0;i<n;++i){
		for (int j=0;j<m;++j){
			int x;
			scanf("%d", &x);
			row[x].push_back(i);
			col[x].push_back(j);
		}
	}
	for (auto &p: row) sort(p.second.begin(), p.second.end());
	for (auto &p: col) sort(p.second.begin(), p.second.end());
	long long ans = 0;
	for (auto &p: row){
		long long c = -((long long)(p.second.size() - 1));
		for (int i=0;i<p.second.size();++i){
			// cout << p.second[i] << " " << i << " " << c << endl;
			ans += p.second[i] * c;
			c += 2;
		}
	}
	for (auto &p: col){
		long long c = -((long long)(p.second.size() - 1));
		for (int i=0;i<p.second.size();++i){
			// cout << p.second[i] << " " << i << " " << c << endl;
			ans += p.second[i] * c;
			c += 2;
		}
	}
	cout << ans << endl;
}

int main(){
	int t=1;
	// cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}