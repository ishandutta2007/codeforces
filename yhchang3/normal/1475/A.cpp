#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		long long x;
		cin >> x;
		if(__builtin_popcountll(x) == 1)
			cout << "NO" << '\n';
		else
			cout << "YES" << '\n';
	}
}