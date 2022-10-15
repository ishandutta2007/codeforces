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
	vector<vector<int> > v(n, vector<int>(m));
	for (int i=0;i<n;++i){
		for (int j=0;j<m;++j){
			scanf("%d", &v[i][j]);
		}
	}


	// 10 1 9 0
	vector<int> cols(n, -1);
	bool ok = true;
	for (int i=0;i<n;++i){
		for (int j=1;j<m;++j) {
			if (v[i][j] < v[i][j-1]) {
				// .. b a .. 
				if (cols[i] == -1) {
					if (j+1 == m || v[i][j-1] < v[i][j+1]) {
						cols[i] = j;
					}
					else {
						if (v[i][j-1] > v[i][j+1]) {
							cols[i] = j-1;
						} else {
							if (j - 1 == 0 || v[i][j-2] <= v[i][j]) {
								cols[i] = j-1;
							} else {
								if (v[i][j-2] == v[i][j-1]) {
									cols[i] = j;
								} else {
									cout << -1 << endl;
									return;
								}
							}
						}
					}
				}
			}
		}
		if (cols[i] != -1) ok = false;
	}
	if (ok) {
		cout << "1 1" << endl;
		return;
	}

	set<int> c;
	for (int i: cols) {
		if (i != -1) c.insert(i);
	}
	if (c.size() > 2) {
		cout << -1 << endl;
		return;
	}
	if (c.size() == 2) {
		int x = *c.begin();
		c.erase(x);
		int y = *c.begin();
		for (int i=0;i<n;++i){
			swap(v[i][x], v[i][y]);
			for (int j=1;j<m;++j){
				if (v[i][j] < v[i][j-1]) {
					cout << -1 << endl;
					return;
				}
			}
		}
		cout << x + 1 << " " << y + 1 << endl;
		return;
	} else {
		int x = *c.begin();
		int y = -1;
		for (int i=0;i<n;++i){
			if (cols[i] == -1) continue;
			if (x && v[i][x] < v[i][x-1])
			for (int j=0;j<m;++j) {
				if (v[i][j] >= v[i][x-1]) {
					y = j;
					break;
				}
			}
			else
			for (int j=m-1;j>=0;--j) {
				if (v[i][j] <= v[i][x+1]) {
					y = j;
					break;
				}
			}
		}
		// cout << x << " " << y << endl;
		for (int i=0;i<n;++i){
			swap(v[i][x], v[i][y]);
			for (int j=1;j<m;++j){
				if (v[i][j] < v[i][j-1]) {
					cout << -1 << endl;
					return;
				}
			}
		}
		cout << x + 1 << " " << y + 1 << endl;
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