#include<bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		long long p, a, b, c;
		cin >> p >> a >> b >> c;
		cout << min({(a - p % a) % a, (b - p % b) % b, (c - p % c) % c}) << '\n';
	}
}