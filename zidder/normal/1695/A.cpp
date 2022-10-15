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
	for (auto &v: a) for (auto &i: v) scanf("%d", &i);
	int mx = a[0][0];
	int x=0, y=0;
	for (int i=0;i<n;++i) for (int j=0;j<m;++j) {
		if (mx < a[i][j]) {
			mx = a[i][j];
			x = i;
			y = j;
		}
	}

	int h = max(x+1, n-x), w=max(y+1, m-y);
	cout << h * w << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}