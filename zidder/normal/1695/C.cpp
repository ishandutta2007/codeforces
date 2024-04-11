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
	vector<vector<int> > a(n, vector<int>(m));
	for (int i=0;i<n;++i) for (int j=0;j<m;++j) scanf("%d", &a[i][j]);

	vector<vector<pair<int, int> > > mm(n, vector<pair<int, int> >(m));
	mm[0][0] = {a[0][0], a[0][0]};
	for (int i=0;i<n;++i){
		for (int j=0;j<m;++j){
			if (i == 0 && j == 0) continue;
			if (i == 0) {
				mm[0][j] = {mm[0][j-1].first + a[i][j], mm[0][j-1].second + a[i][j]};
				continue;
			}
			if (j == 0) {
				mm[i][0] = {mm[i-1][0].first + a[i][j], mm[i-1][0].second + a[i][j]};
				continue;
			}
			mm[i][j].first = min(mm[i-1][j].first, mm[i][j-1].first) + a[i][j];
			mm[i][j].second = max(mm[i-1][j].second, mm[i][j-1].second) + a[i][j];
		}
	}
	if (mm[n-1][m-1].first > 0 || mm[n-1][m-1].second < 0 || (n+m-1)%2 == 1) {
		cout << "NO" << endl;
		return;
	}cout << "YES" << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}