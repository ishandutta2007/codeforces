#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		int n, k1, k2, w, b;
		cin >> n >> k1 >> k2 >> w >> b;
		if(w <= min(k1, k2) + abs(k1 - k2) / 2 && b <= min(n - k1, n - k2) + abs(k1 - k2) / 2)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
}