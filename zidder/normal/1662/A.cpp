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
	vector<int> b(n), d(n);
	vector<int> a(11, -1);
	for (int i=0;i<n;++i) {
		cin >> b[i] >> d[i];
		a[d[i]] = max(a[d[i]], b[i]);
	}

	int ans = 0;
	for (int i=1;i<=10;++i) {
		if (a[i] == -1) {
			cout << "MOREPROBLEMS" << endl;
			return;
		}
		ans += a[i];
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