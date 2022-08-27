#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 1054;

int n, top;
int a[N];
int stack[N];

inline void print() {
	for (int i = 1; i <= top; ++i) cout << stack[i] << (i == top ? '\n' : '.');
}

void work() {
	int i; top = 0;
	cin >> n;
	for (i = 0; i < n; ++i) cin >> a[i];
	for (i = 0; i < n; ++i) {
		if (a[i] == 1) stack[++top] = 1;
		else {
			for (; top && stack[top] != a[i] - 1; --top);
			assert(top), ++stack[top];
		}
		print();
	}
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}