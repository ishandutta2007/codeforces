#include <bits/stdc++.h>
using namespace std;
#define rg register
#define fu(i, a, b) for(rg int i = (a), I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(rg int i = (a), I = (b) - 1; i > I; --i)

const int N = 300005;
int n, k;
char a[N], b[N];

int main() {
	scanf("%d%d%s", &n, &k, a + 1);
	fu(i, 1, k) for(rg int j = i; j <= n; j += k) b[j] = a[i];
	if(strcmp(a + 1, b + 1) <= 0) {
		printf("%d\n", n);
		fu(i, 1, n) putchar(b[i]);
		return 0;
	}
	b[k]++;
	int pos = k + 1;
	fd(i, k, 1) 
		if(b[i] <= '9') break;
		else pos = i, b[i] = '0', b[i - 1]++;
	if(pos == 1) {
		++n; printf("%d\n", n);
		fu(i, 1, n) printf("%d\n", i % k == 1 ? 1 : 0);
		return 0;
	}
	fu(i, 1, k) for(rg int j = i; j <= n; j += k) b[j] = b[i];
	printf("%d\n", n);
	fu(i, 1, n) putchar(b[i]);
	return 0;
}