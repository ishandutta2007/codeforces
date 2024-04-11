#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n;
	cin >> n;
	map<int, vector<int> > inds;
	for (int i=0;i<n;++i){
		int x;
		scanf("%d", &x);
		inds[x].push_back(i + 1);
	}
	vector<int> ans(n);
	for (auto &p: inds) {
		if (p.second.size() < 2) {
			cout << -1 << endl;
			return;
		}
		for (int j=0;j<p.second.size();++j) {
			int j1 = (j + 1) % p.second.size();
			ans[p.second[j] - 1] = p.second[j1];
		}
	}
	for (int i: ans) printf("%d ", i);
	cout << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}