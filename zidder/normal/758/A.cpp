#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

long long n, a[105], sm, mx;

int main()
{
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		sm += a[i];
		mx = mx < a[i] ? a[i] : mx;
	}
	cout << mx * n - sm << endl;
	return 0;
}