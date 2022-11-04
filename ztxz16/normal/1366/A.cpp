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
    	int a, b;
    	scanf("%d %d", &a, &b);
    	if (a > b) {
    		swap(a, b);
    	}
    	int ans = 0;
    	if (2 * a <= b) {
    		ans = a;
    	} else {
    		int d = b - a;
    		ans += d;
    		a -= d;
    		b = a;

    		ans += 2 * (a / 3);
    		a %= 3;
    		ans += (a > 1);
    	}
    	printf("%d\n", ans);
    }
	return 0;
}