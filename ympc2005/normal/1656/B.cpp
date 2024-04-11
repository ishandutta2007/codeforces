#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e5 + 10;

int T, n, m;

map <int, int> mp;

int main() {
	scanf("%d", &T);
	
	while (T--) {
		mp.clear();
		scanf("%d%d", &n, &m);
		int ans = 0;
		
		for (int x, i = 1; i <= n; i++) {
			scanf("%d", &x);
			ans |= mp[m + x];
			ans |= mp[x - m];
			mp[x] = 1;
		}
		
		printf("%s\n", ans ? "Yes" : "No");
	}
}