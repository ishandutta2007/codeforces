#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 200000;

int n, k;
int s[N + 5];

int main() {
	scanf("%d %d", &n, &k);
	int l = 1, r = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		s[x]++;
		r = max(r, s[x]);
	}
	
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		int cur = 0;
		for (int i = 1; i <= N; i++) {
			cur += (s[i] / mid);
		}
		
		if (cur >= k) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	
	int now = 0;
	for (int i = 1; i <= N; i++) {
		while (now < k && s[i] >= l) {
			printf("%d ", i);
			s[i] -= l;
			now++;
		}
	}
	
	return 0;
}