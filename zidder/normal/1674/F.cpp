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
	int q;
	cin >> q;

	vector<vector<bool> > v(n, vector<bool>(m, false));
	int cnt = 0;
	for (int i=0;i<n;++i){
		string s;
		cin >> s;
		for (int j=0;j<m;++j){
			if (s[j] == '*') v[i][j] = true;
			cnt += v[i][j];
		}
	}

	int ind = 0, p=0;
	for (int j=0;j<m;++j){
		for (int i=0;i<n;++i){
			if (ind == cnt) break;
			p += v[i][j];
			ind++;
		}
	}

	for (int i=0;i<q;++i){
		int x, y;
		scanf("%d%d", &x, &y);
		x--;y--;
		if (v[x][y]) {
			v[x][y] = false;
			cnt--;
			if (y * n + x == cnt) {
				p--;
			} else {
				if (v[cnt%n][cnt/n]) p--;
				if (y * n + x < cnt) p--;
			}
		} else {
			v[x][y] = true;
			if (y * n + x == cnt) {
				p++;
			} else {
				if (y * n + x < cnt) p++;
				if (v[cnt%n][cnt/n]) p++;
			}
			cnt++;
		}
		// cout << cnt << " " << p << endl;
		printf("%d\n", cnt-p);
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