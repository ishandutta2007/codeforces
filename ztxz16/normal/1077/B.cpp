#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int a[105];
int n, ans = 0;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (i > 2 && a[i] == 1 && a[i - 1] == 0 && a[i - 2] == 1) {
			ans++;
			a[i] = 0;
		}
		
	}
	
	printf("%d\n", ans);
	return 0;
}