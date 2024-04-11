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
	vector<string> s(n);
	for (int i=0;i<n;++i) cin >> s[i];
	int mx = n + m, my = n + m;
	for (int i=0;i<n;++i) for (int j=0;j<m;++j) if (s[i][j] == 'R') {
		mx = min(mx, i);
		my = min(my, j);
	}
	if (mx > n || s[mx][my] == 'E') {
		cout << "NO" << endl;
		return;
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