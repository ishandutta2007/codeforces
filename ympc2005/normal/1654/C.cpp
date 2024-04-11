#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;

int n, T, cnt;

ll sum;

map <ll, int> mp;

bool solve_(ll x) {
	if (mp[x] > 0) {
		mp[x]--;
		return 1;
	}
	
	cnt++;
	
	if (cnt > n) {
		return 0;
	}
	
	return solve_(x/2) && solve_(x - x/2);
}

int main() {
	scanf("%d", &T);
	
	while (T--) {
		mp.clear(), sum = 0, cnt = 1;
		scanf("%d", &n);
		
		for (int x, i = 1; i <= n; i++) {
			scanf("%d", &x);
			mp[x]++, sum += x;
		}
		
		printf("%s\n", solve_(sum) ? "YES" : "NO");
	}
}