#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

void work() {
	int n, r;
	scanf("%d %d", &n, &r);
	long long ans = 0;
	if (r >= n) {
		ans = (long long)n * (n - 1) / 2 + 1;
	} else {
		ans = (long long)r * (r + 1) / 2;
	}
	cout << ans << endl;
}

int main() {
    int test;
    scanf("%d", &test);
    while (test--) {
    	work();
    }
	return 0;
}