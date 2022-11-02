#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int a[N], n, z;
bool test(int k) {
	if (k * 2 > n) return false;
	for (int i = 0; i < k; i++) {
		if (a[i] + z > a[n-k+i]) return false;	
	}
	return true;
}

int main() {

	scanf("%d%d", &n, &z);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
	sort(a,a+n);
	int l = 0, r = n/2+1;
	while (l + 1 < r) {
		int mid = (l+r)/2;
		if (test(mid)) l = mid;
		else r = mid;
	}
	printf("%d\n", l);
}