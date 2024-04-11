#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

void work() {
	int n, x;
	scanf("%d %d", &n, &x);
	vector <int> v;
	int s1 = 0, s2 = 0, ss = 0;
	for (int i = 0; i < n; i++) {
		int now;
		scanf("%d", &now);
		v.push_back(now);
		s1 |= (now % 2 == 0);
		s2 |= (now % 2 != 0);
		ss += (now % 2);
	}

	if (n == x) {
		if (ss % 2 == 0) {
			printf("no\n");
		} else {
			printf("yes\n");
		}
		return;
	}
	if (s1 && s2) {
		printf("yes\n");
	} else if (s2 && x % 2 == 1) {
		printf("yes\n");
	} else {
		printf("no\n");
	}
}
int main() {
    int test;
    scanf("%d", &test);
    while (test--) {
    	work();
    }
	return 0;
}