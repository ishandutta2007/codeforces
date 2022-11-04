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
    	vector <int> a;
    	scanf("%d", &n);
    	for (int i = 0; i < n; i++) {
    		int x;
    		scanf("%d", &x);
    		a.push_back(x);
    	}
    	int last = 0, ans = 0, l = 0, r = n - 1;
    	int s[2] = {0, 0}, cur = 0;
    	while (l <= r) {
    		int now = 0;
    		if (cur == 0) {
    			ans++;
    			while (l <= r && now <= last) {
    				s[0] += a[l];
    				now += a[l];
    				l++;
    			}
    		} else {
    			ans++;
    			while (l <= r && now <= last) {
    				s[1] += a[r];
    				now += a[r];
    				r--;
    			}
    		}
    		last = now;
    		cur ^= 1;
    	}
    	printf("%d %d %d\n", ans, s[0], s[1]);
    }
	return 0;
}