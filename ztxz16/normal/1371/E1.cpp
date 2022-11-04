#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100005;
int n, p;
int f[N], a[N];

int find(int i) {
	return f[i] == i ? i : f[i] = find(f[i]);
}

void del(int i, int n, int p) {
	while (i != n - 1) {
		if (i >= p) {
			f[i] = find(f[i - p]);
		} else {
			f[i] = n - 1;
		}
		i = find(i);
	}
}

int main() {
    scanf("%d %d", &n, &p);
    for (int i = 0; i < n; i++) {
    	scanf("%d", &a[i]);
    	f[i] = i;
    }

    sort(a, a + n);
    reverse(a, a + n);
    int x = 0, xmax = n - 2;
    for (int i = 0; i < n; i++) {
    	int now = -a[i] + n - i;
    	x = max(x, -now + 1);
    }
    for (int i = 0; i < n; i++) {
    	int now = -a[i] + n - i + x;
    	int mx = n - i;
    	if (mx % p == 0) {
    		xmax = min(mx - now - 1, xmax);
    	}
    	mx -= (mx % p);
    	if (now <= mx) {
    		del(mx - now, n, p);
    	}
    }
    int ans = 0;
    for (int i = 0; i <= xmax; i++) {
    	ans += (find(i) == i);
    }
    printf("%d\n", ans);
    for (int i = 0; i <= xmax; i++) {
    	if (find(i) == i) {
    		printf("%d ", x + i);
    	}
    }
    printf("\n");
	return 0;
}