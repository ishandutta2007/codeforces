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
	vector<int> a(n);
	for (int i=0;i<n;++i) scanf("%d", &a[i]);
	int c = 0, mn = n, mx = -1;
	for (int i=1;i<n;++i) {
		if (a[i] == a[i-1]) {
			mx = max(i, mx);
			mn = min(i, mn);
			c++;
		}
	}
	if (c < 2) {
		cout << 0 << endl;
		return;
	}
	cout << max(mx - mn - 1, 1) << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}