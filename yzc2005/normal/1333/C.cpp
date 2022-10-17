//I love Violet Evergarden!!!
#include <bits/stdc++.h>
using namespace std;

int n, a[200005];
typedef long long ll;
ll s[200005], ans;
map<ll, int> lst;

int main() {
	scanf("%d", &n);
	lst[0] = 0;
	for(int i = 1, mx = -1; i <= n; ++i) {
		scanf("%d", &a[i]);
		s[i] = s[i - 1] + a[i];
		if(lst.count(s[i])) mx = max(mx, lst[s[i]]);
		lst[s[i]] = i;
		ans += max(i - mx - 1, 0);
	}
	printf("%lld", ans);
}