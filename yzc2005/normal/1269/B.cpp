#include <bits/stdc++.h>
using namespace std;
#define rg register
#define fu(i, a, b) for(rg int i = (a), I = (b) + 1; i < I; ++i)
 
const int N = 2005, P = 1e9;
int n, m, mnlen = 2e9, a[N], b[N], tmp[N];
 
int main() {
	scanf("%d%d", &n, &m);
	fu(i, 1, n) scanf("%d", &a[i]);
	fu(i, 1, n) scanf("%d", &b[i]);
	sort(a + 1, a + n + 1); sort(b + 1, b + n + 1);
	fu(k, 0, n) {
		fu(j, 1, k) tmp[j] = b[j] + m;
		fu(j, k + 1, n) tmp[j] = b[j];
		sort(tmp + 1, tmp + n + 1);
		int len = tmp[1] - a[1];
		if(len < 0) continue;
		bool ok = 1;
		fu(i, 2, n) 
			if(len != tmp[i] - a[i]) {
				ok = 0;
				break;
			}
		if(ok) mnlen = min(mnlen, len);
	} 
	printf("%d\n", mnlen);
	return 0;
}