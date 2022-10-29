#include <cstdio>
#include <cstdlib>

int main() {
	int n, m, a, b;
	scanf("%d%d%d%d", &n, &m, &a, &b);
	int ra=(a-1)/m+1, ca=(a-1)%m+1;
	int rb=(b-1)/m+1, cb=(b-1)%m+1;
	if (b==n) cb=m;
	if (ra==rb || (ca==1 && cb==m)) puts("1");
	else if (ra+1==rb) puts("2");
	else {
		if (ca==1 && cb<m) puts("2");
		else if (cb==m && ca>1) puts("2");
		else if (cb+1==ca) puts("2");
		else puts("3");
	}
	return 0;
}