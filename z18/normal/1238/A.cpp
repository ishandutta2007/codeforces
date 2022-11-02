#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int T;
ll x, y;

int main() {
	scanf("%d", &T);
	while (T --> 0) {
		scanf("%I64d %I64d", &x, &y);
		printf("%s\n", x - y > 1 ? "Yes" : "No");
	}
	return 0;
}