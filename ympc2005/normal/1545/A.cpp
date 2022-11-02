#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int T, n, mx = 1e5, a[N], t[N], f[N], s[N], top;

vector <int> b[N];

void upd_(int x) {
	for (; x <= mx; x += x&-x) {
		t[x]++;
	}
}

int ask_(int x, int res = 0) {
	for (; x; x -= x&-x) {
		res += t[x];
	}
	
	return res;
}

bool check_(int k) {
	top = 0;
	
	for (int x : b[k]) {
		if (top && s[top] == x) {
			top--;
			continue;
		}
		
		s[++top] = x;
	}
	
	for (int i = 1; i <= top; i++) {
		if (s[i]) {
			return 0;
		}
	}
	
	return 1;
}

int main() {
	scanf("%d", &T);
	
	while (T--) {
		scanf("%d", &n);

		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]); 
			f[i] = 0;
		}
		
		for (int i = 1; i <= mx; i++) {
			b[i].clear();
		}
		
		memset(t, 0, sizeof(t));
		
		for (int i = 1; i <= n; i++) {
			f[i] += i - 1 - ask_(a[i]);
			upd_(a[i]);
		}
		
		memset(t, 0, sizeof(t));
		
		for (int i = n; i; i--) {
			f[i] += ask_(a[i] - 1);
			upd_(a[i]);
		}
		
		for (int i = 1; i <= n; i++) {
			b[a[i]].push_back(f[i]&1);
		}
		
		bool ok = 1;
		
		for (int i = 1; i <= mx; i++) {
			if (!check_(i)) {
				ok = 0;
				break;
			}
		}
		
		printf("%s\n", ok ? "YES" : "NO");
	}
}