#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		int n, k;
		cin >> n >> k;
		k--;
		cout << (k + (n % 2) * (k / (n / 2))) % n + 1 << endl;
	}
}