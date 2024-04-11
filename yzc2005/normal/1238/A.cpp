#include <bits/stdc++.h>
using namespace std;

long long t, a, b;

int main() {
	cin >> t; while(t--) {
		cin >> a >> b;
		puts(a - b > 1 ? "YES" : "NO");
	}
	return 0;
}