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
	vector<vector<int> > lr(n);
	for (int i=0;i<n;++i){
		int l, r;
		scanf("%d%d", &l, &r);
		l--;r--;
		lr[l].push_back(r);
	}
	for (int i=0;i<n;++i) sort(lr[i].begin(), lr[i].end());
	vector<vector<int> > ans;
	for (int i=0;i<n;++i){
		if (lr[i].empty()) continue;
		int prev = i;
		for (int j=0;j<lr[i].size();++j){
			ans.push_back({i, lr[i][j], prev});
			prev = lr[i][j] + 1;
		}
	}
	for (auto &v: ans){
		for (int i: v) printf("%d ", i+1);
		printf("\n");
	}
	printf("\n");
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}