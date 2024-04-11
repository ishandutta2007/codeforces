#include <bits/stdc++.h>
using namespace std;

const int N = 3005;

int T, n, a[N], f[N][N];

vector <int> b[N];

void init_() {
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		b[i].clear();
	}
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		b[a[i]].push_back(i);
	}
}

void work_() {
	for (int i = n - 1; i; i--) {
		for (int j = i + 1; j <= n; j++) {
			f[i][j] = f[i + 1][j] + 1;
			
			for (int k : b[a[i]]) {
				if (i < k && k <= j) {
					f[i][j] = min(f[i][j], f[i][k - 1] + f[k][j]);
				}
			}
		}
	}
	
	printf("%d\n", f[1][n]);
}

int main() {
	scanf("%d", &T);
	
	while (T--) {
		init_();
		work_();
	}
	
	return 0;
}