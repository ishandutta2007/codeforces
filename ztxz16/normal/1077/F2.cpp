#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 2147483647;
const int N = 5005;

pair <long long, int> v[N];
long long f[N][N];
int a[N];
int n, k, x;

int main() {
	scanf("%d %d %d", &n, &k, &x);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	for (int i = 0; i <= x; i++) {
		for (int j = 0; j <= n; j++) {
			f[i][j] = -1;
		}
	}
	
	f[0][0] = 0;
	for (int i = 1; i <= x; i++) {
		int h = 1, t = 0;
		for (int j = 0; j < i; j++) {
			while (t >= h && v[t].first < f[i - 1][j]) {
				t--;
			}
			
			v[++t] = make_pair(f[i - 1][j], j);
			f[i][j] = -1;
		}
		
		for (int j = i; j <= n; j++) {
			if (v[h].first >= 0 && h <= t) {
				f[i][j] = v[h].first + a[j];
			}
			
		//	cout << i << ' ' << j << ' ' << f[i][j] << endl;
			
			if (v[h].second == j - k && h <= t) {
				h++;
			}
			
			while (t >= h && v[t].first < f[i - 1][j]) {
				t--;
			}
			
			v[++t] = make_pair(f[i - 1][j], j);
		}
	}

	long long ans = -1;
	for (int j = 1; j <= n; j++) {
		if (n + 1 - j <= k) {
			ans = max(ans, f[x][j]);
		}
	}
	
	cout << ans << endl;
	return 0;
}