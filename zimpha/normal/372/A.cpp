#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 500010;

int a[MAXN];
bool vis[MAXN];

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++ i) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	fill(vis, vis + n, 0);
	int ret = 0;
	for (int i = 0, j = n / 2; i < n; ++ i) {
		if (vis[i]) continue;
		while (j < n) {
			if (a[i] * 2 <= a[j]) {
				vis[j] = true;
				j ++;
				break;
			}
			j ++;
		}
		ret ++;
	}
	printf("%d\n", ret);
	return 0;
}