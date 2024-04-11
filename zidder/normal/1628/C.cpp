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
	vector<vector<int> > m(n, vector<int>(n));

	for (int i=0;i<n;++i){
		for (int j=0;j<n;++j){
			scanf("%d", &m[i][j]);
		}
	}
	vector<vector<int> > v(n, vector<int>(n));
	auto nei = [&](int i, int j){
		int s = 0;
		for (int di=-1;di<=1;++di){
			for (int dj=-1;dj<=1;++dj){
				if (di != 0 && dj != 0 || di == 0 && dj == 0) continue;
				if (i + di < 0 || i + di >= n || j + dj < 0 || j + dj >= n) continue;
				s += v[i + di][j + dj];
			}
		}
		return s % 2;
	};

	for (int i=1;i<n;++i){
		for (int j=0;j<n;++j){
			if (nei(i-1, j) == 0){
				v[i][j] = 1;
			}
		}
	}
	int ans = 0;
	for (int i=0;i<n;++i){
		for (int j=0;j<n;++j){
			if (v[i][j]){
				ans ^= m[i][j];
			}
		}
	}

	cout << ans << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}