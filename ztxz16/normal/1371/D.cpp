#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 305;
int a[N][N], r[N], c[N];

int work(int n, int k) {
	for (int i = 0; i < n; i++) {
		r[i] = c[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int cur = (i + j) % n;
			a[i][cur] = (j < k / n || (j == k / n && i < k % n));
			r[i] += a[i][cur];
			c[cur] += a[i][cur];
		}
	}
	sort(r, r + n);
	sort(c, c + n);
	int v = (r[n - 1] - r[0]) * (r[n - 1] - r[0]) + (c[n - 1] - c[0]) * (c[n - 1] - c[0]);
	printf("%d\n", v);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%c", '0' + a[i][j]);
		}
		printf("\n");
	}
}

int main() {
    int test;
    scanf("%d", &test);
    while (test--) {
    	int n, k;
    	scanf("%d %d", &n, &k);
    	/*for (int n = 1; n <= 10; n++) {
    		for (int k = 0; k <= n * n; k++) {
    			printf("%d\n", work(n, k));
    		}
    	}
    	printf("%d\n", work(n, k));*/
    	work(n, k);
    }
	return 0;
}