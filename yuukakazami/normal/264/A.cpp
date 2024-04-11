#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <deque>
using namespace std;
const int MAX_N = int(1e6) + 10;
char buf[MAX_N];
int n;

int main() {
	scanf("%s", buf);
	n = strlen(buf);
	deque<int> q;
	for (int i = n - 1; i >= 0; --i) {
		if (buf[i] == 'l')
			q.push_back(i + 1);
		else
			q.push_front(i + 1);
	}
	for (int i = 0; i < n; ++i) {
		printf("%d\n", q.front());
		q.pop_front();
	}
	return 0;
}