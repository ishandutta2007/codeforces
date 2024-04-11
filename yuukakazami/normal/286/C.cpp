#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
const int MAX_N = int(1e6) + 10;
int p[MAX_N], n, t;
bool neg[MAX_N];

int stack[MAX_N], top;

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		scanf("%d", p + i);
	}
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int x;
		scanf("%d", &x);
		neg[x - 1] = true;
	}

	for (int i = n - 1; i >= 0; --i) {
		if (neg[i]) {
			stack[top++] = i;
		} else {
			if (top > 0 && p[stack[top - 1]] == p[i]) { //left
				--top;
			} else { //right
				neg[i] = true;
				stack[top++] = i;
			}
		}
	}

	if (top > 0) {
		puts("NO");
		return 0;
	}
	puts("YES");
	for (int i = 0; i < n; ++i) {
		printf("%d ", p[i] * (neg[i] ? -1 : 1));
	}
	puts("");
	return 0;
}