#include <bits/stdc++.h>

const int kMaxN = 5e5 + 5;

int t, a[kMaxN], f1[kMaxN], f2[kMaxN];

int main() {
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i)
			scanf("%d", a + i);
		f1[1] = 1;
		for(int i = 2; i <= n; ++i)
			f1[i] = (f1[i - 1] && (a[i] >= i - 1));
		f2[n] = 1;
		for(int i = n - 1; i; --i)
			f2[i] = (f2[i + 1] && (a[i] >= n - i));
		bool flag = f2[1] || f1[n];
		for(int i = 1; i < n; ++i)
			flag = (flag || (a[i] >= n - i && f1[i] && f2[i + 1]));
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}