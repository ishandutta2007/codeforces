#include <bits/stdc++.h>
using namespace std;

const int N = 300005;

int n, lsta, lstb;
char a[N];

int main() {
	scanf("%d%s", &n, a + 1);
	long long ans = 0;
	for(int i = 1; i <= n; ++i) 
		for(int j = 1; a[i] == a[i + 1]; ++i, ans += j++);
	for(int i = 1; i <= n; ++i) {
		if(a[i] == 'A') {
			ans += max(0, min(lstb - 1, lsta));
			lsta = i;
		} else {
			ans += max(0, min(lsta - 1, lstb));
			lstb = i;
		}
	}
	printf("%lld\n", ans);
}