#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

const int MAX_N = int(2e5) + 10;

int n;
int a[MAX_N];
int pre[MAX_N], nxt[MAX_N];

int ans[MAX_N];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}

	//calc pre
	vector<int> stack;
	for (int i = 0; i < n; ++i) {
		while (!stack.empty() && a[stack.back()] >= a[i])
			stack.pop_back();
		if (stack.empty()) {
			pre[i] = -1;
		} else {
			pre[i] = stack.back();
		}
		stack.push_back(i);
	}

	stack.clear();
	for (int i = n - 1; i >= 0; --i) {
		while (!stack.empty() && a[stack.back()] >= a[i])
			stack.pop_back();
		if (stack.empty()) {
			nxt[i] = n;
		} else {
			nxt[i] = stack.back();
		}
		stack.push_back(i);
	}

	for (int i = 0; i < n; ++i) {
		int L = pre[i] + 1, R = nxt[i] - 1;
		int len = R - L + 1;
		ans[len] = max(ans[len], a[i]);
	}

	for (int i = n; i > 1; --i) {
		ans[i - 1] = max(ans[i - 1], ans[i]);
	}

	for (int i = 1; i <= n; ++i) {
		printf("%d ", ans[i]);
	}
	puts("");
}