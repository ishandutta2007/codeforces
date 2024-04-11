#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

typedef long long int64;

#define checkMax(a,b) a=max(a,b)

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

typedef long long int64;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	if (n - 1 + m - 1 < k) {
		puts("-1");
		return 0;
	}
	int64 ans = 0;
//	int cnt = 0;
	for (int64 i = 1; i <= n; i++) {
//		++cnt;
		int64 r = n / (n / i);
		i = r;
		if (k - (r - 1) > m - 1)
			continue;
		int64 o = max(k - (r - 1) + 1, 1LL);
		checkMax(ans, 1LL * (n / r) * (m / o));
		//cout << " " << z << " " << t << " " << tt << endl;
	}
//	cout << cnt << endl;
	cout << ans << endl;
	return 0;
}