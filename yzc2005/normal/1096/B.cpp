#include <bits/stdc++.h>
using namespace std;

string s;
int n, a, b;
const int mod = 998244353;

int main() {
	cin >> n >> s, s = ' ' + s;
	for(a = 1; a < n; ++a) if(s[a] != s[a + 1]) break;
	for(b = n; b > 1; --b) if(s[b] != s[b - 1]) break;
	if(a > b) {
		printf("%d\n", 1ll * n * (n + 1) / 2 % mod);
	} else {
		if(s[1] == s[n]) printf("%d\n", 1ll * (a + 1) * (n + 2 - b) % mod);
		else printf("%d\n", (a + n - b + 2) % mod);
	}
	return 0;
}