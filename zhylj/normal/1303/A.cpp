#include <bits/stdc++.h>

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		char s[233]; int fi, lst, cnt = 0;
		scanf("%s", s + 1);
		int n = strlen(s + 1);
		fi = n + 1; lst = 0;
		for(int i = 1; i <= n; ++i)
			if(s[i] == '1') fi = std::min(fi, i), lst = std::max(lst, i), ++cnt;
		if(fi == n + 1) printf("0\n");
		else printf("%d\n", lst - fi + 1 - cnt);
	}
	return 0;
}