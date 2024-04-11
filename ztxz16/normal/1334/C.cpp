#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int test;
    scanf("%d", &test);
    while (test--) {
    	int n;
    	scanf("%d", &n);
    	vector <long long> a, b;
    	for (int i = 0; i < n; i++) {
    		long long x, y;
    		scanf("%lld %lld", &x, &y);
    		a.push_back(x);
    		b.push_back(y);
    	}

    	long long ans = 0, mx = (1LL << 60);
    	for (int i = 0; i < n; i++) {
    		int pre = i == 0 ? n - 1 : i - 1;
    		ans += max(0LL, a[i] - b[pre]);
    		mx = min(mx, min(b[pre], a[i]));
    	}
    	ans += mx;
    	printf("%lld\n", ans);
    }
	return 0;
}