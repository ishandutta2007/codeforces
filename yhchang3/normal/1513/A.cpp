#include<bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n, k;
		cin >> n >> k;
		if(k * 2 + 1 > n) {
			cout << -1 << '\n';
		}
		else {
			for(int i=1;i<=n;i++) {
				if(i > k * 2 + 1) {
					cout << i << ' ';
				}
				else if(i & 1) {
					cout << 1 + (i >> 1) << ' ';
				}
				else {
					cout << k + 1 + (i >> 1) << ' ';
				}
			}
			cout << '\n';
		}
	}
}