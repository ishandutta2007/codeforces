#include <bits/stdc++.h>
using namespace std;

int n, a[100005];

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		if(a[i] < 0) a[i] = -a[i] - 1;
	}
	int mx = *max_element(a + 1, a + n + 1);
	bool flg = 0;
	if(!(n & 1)) {
		for(int i = 1; i <= n; ++i) cout << -a[i] - 1 << ' ';
	} else {
		for(int i = 1; i <= n; ++i) {
			if(a[i] != mx || flg) a[i] = -a[i] - 1;
			else flg = 1;
			cout << a[i] << ' '; 
		}
	}
	return 0;
}