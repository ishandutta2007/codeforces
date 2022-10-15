#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <functional>

using namespace std;

void solve(int test_ind){
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	for (int i=0;i<n;++i){
		cin >> s[i];
	}

	int mix, miy, mx, my;

	vector<vector<bool> > visited(n, vector<bool>(m, false));
	function<int(int, int)> dfs = [&](int i, int j) -> int {
		// cout << i << " " << j << endl;
		int c = 1;
		visited[i][j] = true;
		mix = min(i, mix);
		mx = max(i, mx);
		miy = min(j, miy);
		my = max(j, my);
		for (int k=0;k<4;++k){
			int dx = k==0?-1:k==1?1:0;
			int dy = k==2?-1:k==3?1:0;
			if (i+dx<0 || i+dx>=n || j+dy<0 || j+dy>=m) continue;
			if (!visited[i+dx][j+dy] && s[i+dx][j+dy] == '1'){
				c += dfs(i+dx, j+dy);
			}
		}
		return c;
	};

	for (int i=0;i<n;++i){
		for (int j=0;j<m;++j){
			if (!visited[i][j] && s[i][j] == '1'){
				mix = mx = i;
				miy = my = j;
				int res = dfs(i, j);
				// cout << mix << " " << mx << " " << miy << " " << my << " " << res << endl;
				if (res != (mx - mix + 1) * (my - miy + 1)){
					cout << "NO" << endl;
					return;
				}
			}
		}
	}
	cout << "YES" << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}