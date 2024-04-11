#include<iostream>
#include<algorithm>
using namespace std;
int d[200], h[200], c[200];
int main() {
	int t; cin >> t;
	while(t--) {
		int n,x; cin >> n >> x;
		for (int i = 1; i <= n; i++) {
			cin >> d[i] >> h[i];
			c[i] = d[i] - h[i];
		}
		sort(d + 1, d + n + 1);
		sort(c + 1, c + n + 1);
		if (d[n] >= x) {
			cout << "1" << endl;
			continue;
		}
		if (c[n] <= 0) {
			cout << "-1" << endl;
			continue;
		}
		cout << (x - d[n] - 1) / c[n] + 2 << endl;

	}
}