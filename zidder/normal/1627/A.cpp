#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, m, r, c;
	cin >> n >> m >> r >> c;
	r--;c--;
	vector<string> s(n);
	for (int i=0;i<n;i++) cin >> s[i];
	if (s[r][c] == 'B') {
		cout << 0 << endl;
		return;
	}
	for (int i=0;i<m;++i){
		if (s[r][i] == 'B') {
			cout << 1 << endl;
			return;
		}
	}
	for (int i=0;i<n;++i){
		if (s[i][c] == 'B') {
			cout << 1 << endl;
			return;
		}
	}
	for (int i=0;i<n;++i){
		for (int j=0;j<m;++j){
			if (s[i][j] == 'B') {
				cout << 2 << endl;
				return;
			}
		}
	}
	cout << -1 << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}