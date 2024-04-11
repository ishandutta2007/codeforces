#include <map>
#include <set>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int n;

int main() {
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	int last = 0;
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		ans += abs(last - x);
		last = x;
	}
	
	printf("%I64d\n", ans);
	return 0;
}