#include "bits/stdc++.h"
using namespace std;


int main() {
	
	int n; cin >> n;
	int amin=999999;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int a, p; cin >> a >> p;
		amin = min(amin, p);
		ans += amin*a;
	}
	cout << ans << endl;



	return 0;
}