#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 105;

int n, k, a[N];

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	int s = 0;
	for (int i = 0; i <= n; i++) {
		if (i == n || a[i] > k) {
			s += i;
			break;
		}
	}
	
	reverse(a, a + n);
	for (int i = 0; i <= n; i++) {
		if (i == n || a[i] > k) {
			s += i;
			break;
		}
	}
	
	printf("%d\n", min(s, n));
	return 0;
}