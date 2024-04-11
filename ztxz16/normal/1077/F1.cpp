#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 2147483647;
const int N = 205;

long long f[N][N][N];
int a[N];
int n, k, x;

int main() {
	scanf("%d %d %d", &n, &k, &x);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= x; j++) {
			for (int l = 0; l < k; l++) {
				f[i][j][l] = -1;
			}
		}
	}
	
	f[0][0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= x; j++) {
			for (int l = 0; l < k; l++) {
				if (f[i][j][l] < 0) {
					continue;
				}
		
				if (j < x) {
					f[i + 1][j + 1][0] = max(f[i + 1][j + 1][0], f[i][j][l] + a[i + 1]);
				}
				
				if (l < k - 1) {
					f[i + 1][j][l + 1] = max(f[i + 1][j][l + 1], f[i][j][l]);
				}
			}
		}
	}
	
	long long ans = -1;
	for (int l = 0; l < k; l++) {
		ans = max(ans, f[n][x][l]);
	}
	
	cout << ans << endl;
	return 0;
}