//I love Violet Evergarden!!!
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n, m;
	scanf("%d", &t); while(t--) {
		scanf("%d%d", &n, &m);
		for(int i = 1; i < n; ++i) {
			for(int j = 1; j < m; ++j) printf("W");
			puts("B");
		}
		for(int i = 1; i <= m; ++i) printf("B");
		puts("");
	}
	return 0;
}