#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
int n, a;
long long black, white;

int main() {
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a;
		if(i & 1) black += a >> 1, white += a - (a >> 1);
		else black += a - (a >> 1), white += a >> 1;
	}
	cout << min(black, white) << endl;
	return 0;
}