#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
using namespace std;

deque<int> deq;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		deq.push_back(i);
	for (int i = 1; i <= n; i++) {
		int l = ((n - 1) / i) * i;
		deq.push_back(deq[l]);
		while (l) {
			deq[l] = deq[l - i];
			l -= i;
		}
		deq.pop_front();
	}
	for (int i = 0; i < n; i++)
		printf("%d ", deq[i]);
	puts("");
	return 0;
}