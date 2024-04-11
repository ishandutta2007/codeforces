#include <bits/stdc++.h>
using namespace std;

const int N = 1<<19;

int n, rk[N], sa[N], len, _rk[N];

char s[N];

bool cmp_(int u, int v) {
	return rk[u] == rk[v] ? rk[u^len] < rk[v^len] : rk[u] < rk[v];
}

int main() {
	scanf("%d%s", &n, s), n = 1<<n;
	
	for (int i = 0; i < n; i++) {
		rk[i] = s[i];
		sa[i] = i;
	}
	
	len = 0;
	sort(sa, sa + n, cmp_);
	
	for (len = 1; len < n; len <<= 1) {
		sort(sa, sa + n, cmp_);
		
		for (int j = 0; j < n; j++) {
			_rk[j] = rk[j];
		}
		
		for (int j = 0, k = 0; j < n; j++) {
			k++;
			
			if (j && (_rk[sa[j]] == _rk[sa[j - 1]] && _rk[sa[j]^len] == _rk[sa[j - 1]^len])) {
				k--;
			}
			
			rk[sa[j]] = k;
		}
	}
	
	for (int i = 0; i < n; i++) {
		putchar(s[i^sa[0]]);
	}
}